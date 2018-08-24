@echo off

rem A helper script for debuggging Lily Tin
rem NOTE: This script requires Visual Studio Developer Command Prompt to work 

rem Regenerate the Visual Studio Solution
cmake . bin

rem Build the solution into an executable
msbuild bin\LilyTin.sln

rem If the build succeeded
if %ERRORLEVEL% == 0 (
	rem Run the executable
	bin\Debug\LilyTin.exe
)