@echo off

cmake . bin
msbuild bin/LilyTin.sln
bin\Debug\LilyTin.exe