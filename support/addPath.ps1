function Add-Path($Path) {
	$Path = [Environment]::GetEnvironmentVariable("PATH", "Machine") + [IO.Path]::PathSeparator + $Path
	[Environment]::SetEnvironmentVariable( "Path", $Path, "Machine" )
}

# From ./support folder, run following pecific function like so:
# powershell -command "& { . .\addPath.ps1; printSomething }"
function printSomething() {
	Write-host "PRINT SOMETHING TEST FUNCTION" -f Blue
}

