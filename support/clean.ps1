# Set-ExecutionPolicy -ExecutionPolicy Unrestricted
# Set-ExecutionPolicy -Scope CurrentUser
$Directories = "bin", "build", "support/psClang", "psClang", "CMakeFiles", "CMakeCache.txt", "ninja.log", "cmake_install.cmake", ".ninja_log", ".ninja_deps", ".cache", "lib/Release", "lib/Debug", "lib/RelWithDebInfo", "build.ninja", "build-Debug.ninja", "build-Release.ninja", "build-RelWithDebInfo.ninja"
 
#Delete files in each directory
ForEach ($Dir in $Directories) {
	
	If (Test-Path $Dir) {
		# Folder not exist, delete it!
		Remove-Item -Path $Dir -Recurse -Force
		Write-host "'$Dir' Deleted at '$Dir'!" -f Green
	}
	<# Else {
		Write-host "'$Dir' does not exists!" -f Red
	} #>
}
# https://superuser.com/questions/1091344/powershell-to-delete-all-files-with-a-certain-file-extension
#Get-ChildItem *.sln | foreach { Remove-Item -Path $_.FullName }
#Get-ChildItem *.vcxproj | foreach { Remove-Item -Path $_.FullName }
#Get-ChildItem *.filters | foreach { Remove-Item -Path $_.FullName }
#Get-ChildItem lib\*.lib | foreach { Remove-Item -Path $_.FullName }
Write-host "Succesfully cleaned" -f Green

# https://devblogs.microsoft.com/cppblog/finding-the-visual-c-compiler-tools-in-visual-studio-2017/
