REM Build script to build for all
@ECHO OFF

ECHO "Building everything..."

PUSHD engine
CALL build.bat
POPD
IF %ERRORLEVEL% NEQ 0 (echo Error: %ERRORLEVEL% && exit)

PUSHD testbed
CALL build.bat
POPD
IF %ERRORLEVEL% NEQ 0 (echo Error: %ERRORLEVEL% && exit)

ECHO "ALL assemblies built successfully."