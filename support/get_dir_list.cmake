# Runs powershell to get a list of directories
# Example Usage:
# get_dir_list(vendor VENDOR_INC_DIRS) 

function(get_dir_list INPUT_PATH OUTPUT_VAR)
	EXECUTE_PROCESS(
		COMMAND powershell.exe Get-ChildItem -Recurse -Path ${INPUT_PATH}| ?{ $_.PSIsContainer } | Select-Object FullName
		WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
		OUTPUT_VARIABLE "DIR_LIST"
		ERROR_QUIET
		OUTPUT_STRIP_TRAILING_WHITESPACE)

	#message(DIR_LIST ${DIR_LIST}) 
	string(REGEX REPLACE "\nFullName" "" DIR_LIST ${DIR_LIST})
	string(REGEX REPLACE "\n--------" "" CLEANED_DIR_LIST ${DIR_LIST})
	string(REPLACE " " "" WHITESPACE ${CLEANED_DIR_LIST}) # strip out whitespace
	string(REGEX REPLACE "\\\\" "/" WHITESPACE ${WHITESPACE})

	# https://jeremimucha.com/2021/03/cmake-lists/
	# Normalize paths (converts c:\some\long\path to c:/some/long/path)
	cmake_path(SET CLEAN_LIST "${WHITESPACE}")
	string(REPLACE ${CMAKE_CURRENT_SOURCE_DIR}/ "" CLEANED_STR ${CLEAN_LIST})
	#message(CLEANED_STR ${CLEANED_STR})
	string(REGEX REPLACE "\n" ";" CLEANED_STR ${CLEANED_STR})

	# print out the list
	# message(STATUS "HUMAN READABLE DIR LIST = ${CLEANED_STR}")

	set(${OUTPUT_VAR} ${CLEANED_STR} PARENT_SCOPE)
endfunction()

function(get_dir_list_bat INPUT_PATH OUTPUT_VAR)
	EXECUTE_PROCESS(
		COMMAND dir /b /s /a:d ${INPUT_PATH}
		WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
		OUTPUT_VARIABLE "DIR_LIST"
		ERROR_QUIET
		OUTPUT_STRIP_TRAILING_WHITESPACE)
	
	# Normalize paths (converts c:\some\long\path to c:/some/long/path)
	cmake_path(SET CLEAN_LIST "${WHITESPACE}")
	#message(CMAKE_CURRENT_SOURCE_DIR   ${CMAKE_CURRENT_SOURCE_DIR})
	#message(CLEAN_LIST ${CLEAN_LIST})
	string(REPLACE ${CMAKE_CURRENT_SOURCE_DIR}/ "" CLEANED_STR ${CLEAN_LIST})
	#message(CLEANED_STR ${CLEANED_STR})
	set(${OUTPUT_VAR} ${CLEANED_STR} PARENT_SCOPE)
endfunction()
