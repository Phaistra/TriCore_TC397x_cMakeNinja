# ############################################
# CROSS COMPILE STUFF
# ############################################
set(CMAKE_SYSTEM_NAME Generic-ELF)
set(CMAKE_SYSTEM_PROCESSOR tricore)
set(CMAKE_TASKING_TOOLSET TriCore)
set(CMAKE_C_STANDARD_LIBRARIES "-lcp -lc --munch -D__CPU__=tc39xb")

# ############################################
# FIND THE TASKING/TRICORE EXECUTABLES
# ############################################
# Find Tasking for Tricore.
find_program(TRICORE_COMPILER_C cctc PATHS ENV TASKING_TRICORE_TOOLCHAIN_PATH PATH_SUFFIXES bin)
find_program(TRICORE_COMPILER_CXX cptc PATHS ENV TASKING_TRICORE_TOOLCHAIN_PATH PATH_SUFFIXES bin)
find_program(TRICORE_ASM_COMPILER astc PATHS ENV TASKING_TRICORE_TOOLCHAIN_PATH PATH_SUFFIXES bin)
find_program(TRICORE_OBJDUMP elfdump PATHS ENV TASKING_TRICORE_TOOLCHAIN_PATH PATH_SUFFIXES bin)
find_program(TRICORE_SIZE elfsize PATHS ENV TASKING_TRICORE_TOOLCHAIN_PATH PATH_SUFFIXES bin)
find_program(TRICORE_ARCHIVER artc PATHS ENV TASKING_TRICORE_TOOLCHAIN_PATH PATH_SUFFIXES bin)
find_program(TRICORE_LINKER ltc PATHS ENV TASKING_TRICORE_TOOLCHAIN_PATH PATH_SUFFIXES bin)

foreach (_prefix C CXX)
    if ("${CMAKE_${_prefix}_COMPILER}" STREQUAL "")
        set(CMAKE_${_prefix}_COMPILER "${TASKING_ROOT_PATH}/bin/cctc.exe")
    endif()

    # This is used only if we skip auto compiler identification
    set(CMAKE_${_prefix}_COMPILER_ID "Tasking")
    set(CMAKE_${_prefix}_COMPILER_VERSION "6.3r1")
    # Skip compiler ID identification: use "Tasking"
    set(CMAKE_${_prefix}_COMPILER_ID_RUN TRUE)
    set(CMAKE_${_prefix}_COMPILER_FORCED TRUE)
endforeach()

# ############################################
# DEFINE SOME STUFF
# ############################################
# Specify the cross compiler
set(CMAKE_C_COMPILER ${TRICORE_COMPILER_C})
set(CMAKE_ASM_COMPILER ${TRICORE_ASM_COMPILER})
set(CMAKE_CXX_COMPILER ${TRICORE_COMPILER_CXX})
set(CMAKE_OBJDUMP ${TRICORE_OBJDUMP})
set(CMAKE_SIZE    ${TRICORE_SIZE})
set(CMAKE_AR    ${TRICORE_ARCHIVER})
set(CMAKE_LINKER ${TRICORE_LINKER})

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

if(CMAKE_DEBUG_MESSAGES)
message(COMPILER = ${TRICORE_COMPILER_C})
message(CMAKE_ASM_COMPILER = ${CMAKE_ASM_COMPILER})
message(CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER})
message(CMAKE_ARCHIVER = ${CMAKE_AR})
message(CMAKE_OBJDUMP = ${CMAKE_OBJDUMP})
message(CMAKE_SIZE = ${CMAKE_SIZE})
endif()
# ############################################
# PROJECT STUFF
# ############################################
set(CMAKE_C_CREATE_STATIC_LIBRARY "${CMAKE_AR} ${CMAKE_STATIC_LINKER_FLAGS} -o <TARGET> <OBJECTS>")


# ############################################
# PROJECT STUFF
# ############################################
# Additinal ouput functions
function(add_hex_output TARGET)
    target_link_options(${TARGET} PRIVATE
        LINKER:-c$<TARGET_FILE_DIR:${TARGET}>/$<TARGET_FILE_BASE_NAME:${TARGET}>:IHEX
    )
endfunction()

function(add_bin_output TARGET)
    target_link_options(${TARGET} PRIVATE
        LINKER:-c$<TARGET_FILE_DIR:${TARGET}>/$<TARGET_FILE_BASE_NAME:${TARGET}>:BIN
    )
endfunction()

function(add_size_output TARGET)
    add_custom_command(
        TARGET ${TARGET} 
        POST_BUILD COMMAND ${CMAKE_SIZE} 
            $<TARGET_FILE:${TARGET}>
    )
endfunction()

function(add_dis_output TARGET)
    add_custom_command(
        TARGET ${TARGET} 
        POST_BUILD COMMAND ${CMAKE_OBJDUMP} 
            -d $<TARGET_FILE:${TARGET}> > 
            $<TARGET_FILE_DIR:${TARGET}>/$<TARGET_FILE_BASE_NAME:${TARGET}>.dis)
endfunction()

function(add_map_output TARGET)
    target_link_options(${TARGET} PRIVATE
    LINKER:-M$<TARGET_FILE_DIR:${TARGET}>/$<TARGET_FILE_BASE_NAME:${TARGET}>.map)
endfunction()

function(add_extra_outputs TARGET)
    add_hex_output(${TARGET})
    add_bin_output(${TARGET})
    add_size_output(${TARGET})
    add_dis_output(${TARGET})
    add_map_output(${TARGET})
endfunction()
