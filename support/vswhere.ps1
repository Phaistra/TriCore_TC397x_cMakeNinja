$vswhereLatest = "https://github.com/Microsoft/vswhere/releases/latest/download/vswhere.exe"
$vswherePath = ".\vswhere.exe"
remove-item $vswherePath
invoke-webrequest $vswhereLatest -OutFile $vswherePath

Write-host "VS location:" -f Blue
.\vswhere.exe -prerelease -latest -property installationPath

Write-host "$vswherePath" -f Green
<# Install-Module VSSetup -Scope CurrentUser -Force
Write-host "Runnning..." -f Green
Get-VSSetupInstance | Select-VSSetupInstance -Latest -Require Microsoft.VisualStudio.Component.VC.Tools.x86.x64 > location.txt #>
<# 
Write-host "Runnning..." -f Green
$installationPath = vswhere.exe -prerelease -latest -property installationPath
if ($installationPath -and (test-path "$installationPath\Common7\Tools\vsdevcmd.bat")) {
  & "${env:COMSPEC}" /s /c "`"$installationPath\Common7\Tools\vsdevcmd.bat`" -no_logo && set" | foreach-object {
    $name, $value = $_ -split '=', 2
    set-content env:\"$name" $value
  }
} #>

#https://github.com/microsoft/vswhere/wiki/Start-Developer-Command-Prompt
