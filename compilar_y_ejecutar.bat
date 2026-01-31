@echo off
echo ======================================
echo   Compilando Sistema de Descuentos
echo ======================================
echo.

REM Compilar con g++
g++ -o SistemaDescuentos.exe main.cpp gestor.cpp cliente.cpp descuentoa.cpp descuentob.cpp descuentoc.cpp estrategiadescuento.cpp -std=c++11

if %errorlevel% neq 0 (
    echo.
    echo ERROR: La compilacion fallo
    echo Verifica que tengas g++ instalado y configurado
    pause
    exit /b 1
)

echo.
echo Compilacion exitosa!
echo.
echo ======================================
echo   Ejecutando el programa
echo ======================================
echo.

REM Ejecutar el programa
SistemaDescuentos.exe

echo.
echo.
pause
