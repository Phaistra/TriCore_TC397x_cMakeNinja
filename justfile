### JUSTFILE - PROJECT SPECIFIC COMMANDS ##############################
# Written by: @phaistra (http://phaistra.net // https://github.com/phaistra)

# Justfile - https://github.com/casey/just

### SHELL #############################################################
set windows-shell := ["powershell.exe", "-NoLogo", "-Command"]
#set windows-shell := ["cmd.exe", "/c"]

### SETTINGS #########################################################
APP_NAME := "TriCore_397xx_cMakeNinja"

### COMMANDS #########################################################

# Alternative names for the commands below
alias b := build
alias r := buildr
alias release := buildr

# Generates Ninja files only
gen:
	@Write-host "Generating Ninja build files..." -f Blue
	@./support/multi_ninja.ps1

# Build Debug
build: gen
	@Write-host "Running debug build..." -f Blue
	@ninja -f build.ninja
	@Write-host "Successfully built project" -f Green
	@Write-host "ELF File stats for Debug 'NinjaCmakeTaskingTriCoreProject.elf'" -f Cyan
	@elfsize bin/NinjaCmakeTaskingTriCoreProject.elf
	@Write-host "DONE!" -f Green

# Build Release
buildr: gen
	@Write-host "Running release build..." -f Blue
	@ninja -f build-Release.ninja
	@Write-host "Successfully built project" -f Green
	@Write-host "ELF File stats for 'Release/NinjaCmakeTaskingTriCoreProject.elf'" -f Cyan
	@elfsize bin/Release/NinjaCmakeTaskingTriCoreProject.elf
	@Write-host "DONE!" -f Green

# Build relase & debug
buildall:
	@Write-host "Running debug build..." -f Blue
	@ninja -f build-Debug.ninja
	@Write-host "Running release build..." -f Cyan
	@ninja -f build-Release.ninja
	@Write-host "Running release build (with debug info)..." -f Magenta
	@ninja -f build-RelWithDebInfo.ninja
	@Write-host "Succesfully built project" -f Green

fmt:
	@$Env:PATH += ";$pwd"
	@./support/clang-format-all.ps1 -RepoRoot '%cd%/../src' -Include '*.h', '*.c' -Exclude '*.g.*'

clean:
	@Set-ExecutionPolicy -ExecutionPolicy Unrestricted -Scope CurrentUser
	@./support/clean.ps1

export-src:
	@./support/export-src.ps1

export-binsrc:
	@./support/export-binsrc.ps1

clang:
	./clang-build -export-jsondb
	@Write-host "Generated compile_commands.json" -f Green	

pwr_permissions:
	@Write-host "Attempting to gain proper permissions" -f Green
	@Set-ExecutionPolicy -ExecutionPolicy Unrestricted -Scope CurrentUser -Force

install_deps:
	choco install cmake

wt:
	@%LOCALAPPDATA%\Microsoft\WindowsApps\wt.exe -d %cd%
	@Write-host "Launched windows terminal" -f Green	

# Ninja Metadata that may be useful
ninja_stuff: gen
	@Write-host "Generating extra Ninja files in 'bin/ninja_stuff'" -f Cyan
	@ninja -t deps > bin/ninja_stuff/file_deps.txt
	@ninja -t inputs > bin/ninja_stuff/inputs.txt
	@ninja -t commands > bin/ninja_stuff/commands.txt
	@ninja -t compdb > bin/ninja_stuff/compdb.txt
	@ninja -t targets > bin/ninja_stuff/targets.txt
	@Write-host "Done" -f Green
