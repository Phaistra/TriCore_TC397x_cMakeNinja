$export_name = "bin-export.zip"

$compress = @{
	Path             = ".\src", ".\vendor", ".\support",".\bin", ".\.vscode", ".\.clang-format", ".\.gitignore", ".\CMakeLists.txt", ".\clang-build.ps1", ".\justfile", ".\readme.md"
	CompressionLevel = "Fastest"
	DestinationPath  = $export_name
}
Compress-Archive @compress -Force
Write-host "Succesfully exported '$export_name'" -f Green

# https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.archive/compress-archive?view=powershell-7.3
