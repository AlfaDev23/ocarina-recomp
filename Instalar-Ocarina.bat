@echo off
rem Dois cliques aqui instalam o Ocarina Recomp. Baixa o instalador se este arquivo estiver sozinho.
title Ocarina Recomp
set "S=%~dp0instalador\Instalar-Ocarina.ps1"
if exist "%S%" goto abrir
set "S=%TEMP%\Instalar-Ocarina.ps1"
echo Baixando o instalador...
curl -fsSL -o "%S%" "https://raw.githubusercontent.com/sostenesfreitas/ocarina-recomp/main/instalador/Instalar-Ocarina.ps1"
if errorlevel 1 (
  echo.
  echo Nao consegui baixar o instalador. Confira sua internet e tente de novo.
  pause
  exit /b 1
)
:abrir
start "" powershell -NoProfile -Sta -WindowStyle Hidden -ExecutionPolicy Bypass -File "%S%"
