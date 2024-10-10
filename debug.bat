REM @echo off
REM
REM move /Y "./*.o" "./build-int"
@echo off

IF "%~1" == "" GOTO PrintHelp
IF "%~1" == "compile" GOTO Compile

vendor\premake5.exe %1
GOTO Done

:Compile
vendor\premake5.exe gmake2
make

copy "./MainGame/external-libs/SDL2-w64/bin/SDL2.dll" "./bin/Debug-windows/MainGame"
copy "./MainGame/external-libs/SDL2-w64/bin/SDL2_image.dll" "./bin/Debug-windows/MainGame"
mkdir "./bin/Debug-windows/MainGame/sprites"
xcopy "./sprites" "./bin/Debug-windows/MainGame/sprites" /E /Y

REM echo starting...
REM .\build\debug.exe

REM if not defined DevEnvDir (
REM     call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"
REM )
REM
REM set solutionFile="Westhunter.sln"
REM msbuild /t:Build /p:Configuration=Debug %solutionFile%

GOTO Done

:PrintHelp

echo.
echo Enter 'build.bat action' where action is one of the following:
echo.
echo   compile           Will generate make file then compile using the make file.
echo   clean             Remove all binaries and intermediate binaries and project files.
echo   codelite          Generate CodeLite project files
echo   gmake             Generate GNU makefiles for Linux
echo   gmake2            Generate GNU makefiles for Linux
echo   vs2005            Generate Visual Studio 2005 project files
echo   vs2008            Generate Visual Studio 2008 project files
echo   vs2010            Generate Visual Studio 2010 project files
echo   vs2012            Generate Visual Studio 2012 project files
echo   vs2013            Generate Visual Studio 2013 project files
echo   vs2015            Generate Visual Studio 2015 project files
echo   vs2017            Generate Visual Studio 2017 project files
echo   vs2019            Generate Visual Studio 2019 project files
echo   vs2022            Generate Visual Studio 2022 project files
echo   xcode4            Generate Apple Xcode 4 project files

GOTO Done

:Done
