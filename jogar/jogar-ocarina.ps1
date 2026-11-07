# Abre o Ocarina Recomp.
$env:PATH = "C:\msys64\ucrt64\bin;$env:PATH"
if (Get-CimInstance Win32_VideoController | Where-Object { $_.Name -match 'NVIDIA' }) { $env:TOTK_GPU_NAME = "NVIDIA" }
$raiz = Split-Path $PSScriptRoot -Parent
$env:TOTK_PROFILE_DIR = Join-Path $raiz "perfil"
Set-Location (Join-Path $raiz "build\oot111")
$extras = if ($args.Count) { @{ ArgumentList = $args } } else { @{} }
Start-Process .\ocarina.exe @extras -RedirectStandardOutput (Join-Path $raiz "ultima-partida.log") -RedirectStandardError (Join-Path $raiz "ultima-partida-erros.log")
