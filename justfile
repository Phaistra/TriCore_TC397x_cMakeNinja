# Ninja CMake Just Project TriCore TC39xx
# By Mark Ufimzeff (mufimzeff@one.ai)
# Justfile - https://github.com/casey/just
# https://cheatography.com/linux-china/cheat-sheets/justfile/

# Set shell for Windows OSs:
# set windows-shell := ["powershell.exe", "-NoLogo", "-Command"]
set windows-shell := ["cmd.exe", "/c"]

# Alternative names for the commands below
alias b := build
alias r := buildr
alias release := buildr

# Generates Ninja files only
gen:
	@powershell.exe Write-host "Generating Ninja build files..." -f Blue
	@powershell.exe ./support/multi_ninja.ps1

# Build Debug
build: gen
	@powershell.exe Write-host "Running debug build..." -f Blue
	@ninja -f build.ninja
	@powershell.exe Write-host "Successfully built project" -f Green
	@powershell.exe Write-host "ELF File stats for Debug 'NinjaCmakeTaskingTriCoreProject.elf'" -f Cyan
	@elfsize bin/NinjaCmakeTaskingTriCoreProject.elf
	@powershell.exe Write-host "DONE!" -f Green

# Build Release
buildr: gen
	@powershell.exe Write-host "Running release build..." -f Blue
	@ninja -f build-Release.ninja
	@powershell.exe Write-host "Successfully built project" -f Green
	@powershell.exe Write-host "ELF File stats for 'Release/NinjaCmakeTaskingTriCoreProject.elf'" -f Cyan
	@elfsize bin/Release/NinjaCmakeTaskingTriCoreProject.elf
	@powershell.exe Write-host "DONE!" -f Green

# Build relase & debug
buildall:
	@powershell.exe Write-host "Running debug build..." -f Blue
	@ninja -f build-Debug.ninja
	@powershell.exe Write-host "Running release build..." -f Cyan
	@ninja -f build-Release.ninja
	@powershell.exe Write-host "Running release build (with debug info)..." -f Magenta
	@ninja -f build-RelWithDebInfo.ninja
	@powershell.exe Write-host "Succesfully built project" -f Green

fmt:
	@powershell.exe $Env:PATH += ";$pwd"
	@powershell.exe ./support/clang-format-all.ps1 -RepoRoot '%cd%/../src' -Include '*.h', '*.c' -Exclude '*.g.*'

clean:
	@powershell.exe Set-ExecutionPolicy -ExecutionPolicy Unrestricted -Scope CurrentUser
	@powershell.exe ./support/clean.ps1

export-src:
	@powershell.exe ./support/export-src.ps1

export-binsrc:
	@powershell.exe ./support/export-binsrc.ps1

clang:
	powershell.exe ./clang-build -export-jsondb
	@powershell.exe Write-host "Generated compile_commands.json" -f Green	

pwr_permissions:
	@powershell.exe Write-host "Attempting to gain proper permissions" -f Green
	@powershell.exe Set-ExecutionPolicy -ExecutionPolicy Unrestricted -Scope CurrentUser -Force

install_deps:
	choco install cmake

wt:
	@%LOCALAPPDATA%\Microsoft\WindowsApps\wt.exe -d %cd%
	@powershell.exe Write-host "Launched windows terminal" -f Green	

# Ninja Metadata that may be useful
ninja_stuff: gen
	@powershell.exe Write-host "Generating extra Ninja files in 'bin/ninja_stuff'" -f Cyan
	@ninja -t deps > bin/ninja_stuff/file_deps.txt
	@ninja -t inputs > bin/ninja_stuff/inputs.txt
	@ninja -t commands > bin/ninja_stuff/commands.txt
	@ninja -t compdb > bin/ninja_stuff/compdb.txt
	@ninja -t targets > bin/ninja_stuff/targets.txt
	@powershell.exe Write-host "Done" -f Green
