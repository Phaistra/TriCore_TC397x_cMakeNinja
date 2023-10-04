@rmdir /S /Q "..\bin\"
del /s /q "..\.ninja_log"
del /s /q "..\.ninja_deps"
del /s /q "..\build.ninja"
del /s /q "..\CMakeCache.txt"
del /s /q "..\CMake_install.cmake"
@powershell.exe Write-host "Succesfully cleaned project" -f Green
