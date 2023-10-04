# CMAKE NINJA TASKING TRICORE TOOLCHAIN & PROJECT
# By @phaistra (http://phaistra.net)

cmake_minimum_required(VERSION 3.26.0)
# ##################################################################
# PROJECT STUFF
# ##################################################################
project(NinjaCmakeTaskingTriCoreProject	VERSION 0.1	LANGUAGES C)

# Version info that will be compiled into the binaries
set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)
set(PATCH_VERSION 0)
set(REVISION 0)
set(RELEASE_VERSION ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}.${REVISION})
include(support/get_dir_list.cmake)

# ##################################################################
# BUILD TYPES
# ##################################################################
set(THE_BUILD_TYPE $<$<CONFIG:Release>:FBL_RELEASE>)
if(THE_BUILD_TYPE STREQUAL "FBL_RELEASE")
message(THE_BUILD_TYPE = ${THE_BUILD_TYPE})
set(CMAKE_BUILD_TYPE Release)
message(" --> RELEASE TYPE")
else()
set(CMAKE_BUILD_TYPE Debug)
message(" --> DEBUG TYPE")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set to on to see the flags printed during a build
set(CMAKE_DEBUG_MESSAGES false)

set(CMAKE_VERBOSE_MAKEFILE on )
# ##################################################################
# COMPILE FLAGS & DEFINITIONS
# ##################################################################

add_compile_definitions(_TASKING_C_TRICORE_=1 -DAPP_SW=${PROJECT_NAME})
add_compile_definitions(APP_SW=${PROJECT_NAME})
add_compile_definitions($<$<CONFIG:Debug>:FBL_DEBUG>)
add_compile_definitions($<$<CONFIG:Release>:FBL_RELEASE>)
add_compile_definitions(THE_BUILD_TYPE=${CMAKE_BUILD_TYPE})
add_compile_options("--misrac-version=2004")

set(STANDARD_FLAGS "--iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc39xb -Y0 -N0 -Z0")
string(REPLACE " -t2" "" CMAKE_C_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE}) # -t2 flag somewhow appears twice. This line is needed for release builds, otherwise you will get CCTC Error E204

# JUST FYI
# 1. Release: `-O3 -DNDEBUG`
# 2. Debug: `-O0 -g`
# 3. RelWithDebInfo: `-O2 -g -DNDEBUG`
# 4. MinSizeRel: `-Os -DNDEBUG`

if(CMAKE_BUILD_TYPE STREQUAL "Debug") # Possible Options: Debug, Release, RelWithDebInfo and MinSizeRel
	set(CMAKE_C_FLAGS "${STANDARD_FLAGS}" CACHE STRING "" FORCE)
	set(CMAKE_C_FLAGS_Debug "${STANDARD_FLAGS}" CACHE STRING "" FORCE)
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Release")
	set(CMAKE_C_FLAGS "" CACHE STRING "" FORCE)	
	set(CMAKE_C_FLAGS_Release "${STANDARD_FLAGS}" CACHE STRING "" FORCE)
endif()
if(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
	set(CMAKE_C_FLAGS "${STANDARD_FLAGS} -O3" CACHE STRING "" FORCE)
endif()
if(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
	set(CMAKE_C_FLAGS "${STANDARD_FLAGS} -O3" CACHE STRING "" FORCE)
endif()

# ##################################################################
# ASM STUFF
# ##################################################################

set(ASM_FLAGS "-Og -Os --no-warnings= --error-limit=42")

# ##################################################################
# SOURCES
# ##################################################################

# Add all *.c source files in src directory
file(GLOB_RECURSE APP_SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.c)

# Add all *.c source files in vendor directory
file(GLOB_RECURSE VENDOR_SOURCE_FILES ${CMAKE_SOURCE_DIR}/vendor/*.c)

# Generate a list of all folders in the vendor directory
get_dir_list(vendor VENDOR_INC_DIRS)

# Manually included, but it could be also generated.
include_directories(
	src
	src/core
	src/core/core0
	src/core/core1
	src/core/core2
	src/core/core3
	src/core/core4
	src/core/core5
	src/init
	src/os
	src/hw_if
	src/hw_if/adc_if
	src/hw_if/can_if
	src/hw_if/can_if/dcdc_can
	src/hw_if/can_if/debug_can
	src/hw_if/can_if/vehicle_can
	src/hw_if/hsis
	src/hw_if/IoHwAb
	src/hw_if/nvm_if
	src/hw_if/port_if
	src/hw_if/spi_if
	src/hw_if/timer_if
	vendor
	${VENDOR_INC_DIRS}
	)

# ##################################################################
# LINKER STUFF
# ##################################################################
set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/vendor/linkerscript/Lcf_Tasking_Tricore_Tc.lsl")

# I tried to match against the default settings of AURIX Studio as much as possible

#set(CMAKE_EXE_LINKER_FLAGS "-OCltxy -lcs_fpu -lfp_fpu -lrt --lsl-core=vtc -d${LINKER_SCRIPT}")
# --lsl-file="../linker/Lcf_Tasking_Tricore_Tc.lsl" -Wl-Oc -Wl-OL -Wl-Ot -Wl-Ox -Wl-Oy -Wl--map-file="${BuildArtifactFileBaseName}.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mo -Wl-mq -Wl-mr -Wl-ms -Wl-mu --no-warnings= -Wl--error-limit=1 -lcs_fpu -lfp_fpu -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++ -Ctc39xb
file(MAKE_DIRECTORY bin/flash)

# Generates One combined s19 file, an intel hex file *and* core specific s19 & hex files in the bin/flash directory
set(LINKER_OUTPUT_FORMATS "-Wl--output=bin/${PROJECT_NAME}.s19:SREC:4 -Wl--output=bin/${PROJECT_NAME}.hex:IHEX:4 --chip-output=bin/flash/${PROJECT_NAME}:IHEX:4 --chip-output=bin/flash/${PROJECT_NAME}:SREC:4")

set(COMMON_LINKER_FLAGS "-lcs_fpu -lfp_fpu -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++  ${LINKER_OUTPUT_FORMATS} -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=1")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${COMMON_LINKER_FLAGS} -O1 -d${LINKER_SCRIPT}")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${COMMON_LINKER_FLAGS} -O2 -d${LINKER_SCRIPT}")
set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "${COMMON_LINKER_FLAGS} -O1 -d${LINKER_SCRIPT}")
set(CMAKE_EXE_LINKER_FLAGS_MINSIZEREL "${COMMON_LINKER_FLAGS} -O2 -d${LINKER_SCRIPT}")

# ##################################################################
# GENERATE ELF/BINARIES
# ##################################################################
add_executable(${PROJECT_NAME} ${APP_SOURCE_FILES} ${VENDOR_SOURCE_FILES})

#add_size_output(${PROJECT_NAME})
# ##################################################################
# CMake Properties
# ##################################################################
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	OUTPUT_NAME "${PROJECT_NAME}"
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/lib"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)

# ##################################################################
# MESSAGES
# ##################################################################

if(CMAKE_DEBUG_MESSAGES)
message("CMAKE_BUILD_TYPE      = ${CMAKE_BUILD_TYPE}")
message("CMAKE_C_FLAGS         = ${CMAKE_C_FLAGS}")
message("CMAKE_C_FLAGS_DEBUG   = ${CMAKE_C_FLAGS_DEBUG}")
message("CMAKE_C_FLAGS_RELEASE = ${CMAKE_C_FLAGS_RELEASE}")
message("COMMON_LINKER_FLAGS   = ${COMMON_LINKER_FLAGS}")
endif()

# ##################################################################
# MISRA STUFF
# ##################################################################
# Generate MISRA reports here
#--misrac-version=2004 --misra-c-report=bin/Misra-report.txt page 437 ctc_user_guide.pdf

# ##################################################################
# GIT BUILD VERSION INFO
# ##################################################################
IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/.git)
	FIND_PACKAGE(Git)

	IF(GIT_FOUND)
		EXECUTE_PROCESS(
			COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
			WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
			OUTPUT_VARIABLE "GIT_BUILD_VERSION"
			ERROR_QUIET
			OUTPUT_STRIP_TRAILING_WHITESPACE)
		EXECUTE_PROCESS(
			COMMAND ${GIT_EXECUTABLE} describe --tags --always
			WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
			OUTPUT_VARIABLE "GIT_BUILD_VERSION_TAG"
			ERROR_QUIET
			OUTPUT_STRIP_TRAILING_WHITESPACE)
		if(CMAKE_DEBUG_MESSAGES)
			MESSAGE(STATUS "Git version: ${GIT_BUILD_VERSION}")
			MESSAGE(STATUS "Git version tag: ${GIT_BUILD_VERSION_TAG}")
		endif()
		
	ELSE(GIT_FOUND)
		SET(GIT_BUILD_VERSION 0)
		SET(GIT_BUILD_VERSION_TAG 0)
	ENDIF(GIT_FOUND)
ENDIF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/.git)

# ##################################################################
# GENERATED FILES & TEMPLATES
# ##################################################################

# To nicely support folders in IDEs.
set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)

# Make that vendor folder list human readable
string(REGEX REPLACE ";" ";\n\t" VENDOR_INC_DIRS_PRINT "${VENDOR_INC_DIRS}")

# #################################
# DEBUG CMAKE VARIABLES
# #################################

list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

# https://stackoverflow.com/questions/64667503/how-to-save-the-build-time-of-a-c-dll
string(TIMESTAMP _TIMESTAMP "%Y-%m-%dT%H:%M:%S")
string(TIMESTAMP _PRETTY_TIMESTAMP "%Y-%m-%d : %H:%M:%S")

# #################################
# GENERATED FILES & TEMPLATES
# #################################

# Generate version info file that can be used inside the SW
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/support/versionInfo.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/versionInfo.h)

# VS Code Only: Generate a launch.json file
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/support/vscode/launch.json.temp ${CMAKE_CURRENT_SOURCE_DIR}/.vscode/launch.json @ONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/support/vscode/vscode_settings.json.temp ${CMAKE_CURRENT_SOURCE_DIR}/.vscode/settings.json)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/support/vscode/vscode_tasks.json.temp ${CMAKE_CURRENT_SOURCE_DIR}/.vscode/tasks.json)

# #################################
# Extra Dirs
# #################################
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/ninja_stuff)
#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E echo "THE BUILD TYPE = $<$<CONFIG:Release>:FBL_RELEASE>")
