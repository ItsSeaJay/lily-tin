@echo off

rem Regenerate the Visual Studio Solution
cmake . bin

rem Build the solution into an executable
msbuild bin/LilyTin.sln

if %ERRORLEVEL% == 0 (
	bin\Debug\LilyTin.exe
)