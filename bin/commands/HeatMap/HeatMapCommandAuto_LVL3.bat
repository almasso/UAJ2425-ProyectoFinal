@echo off
setlocal EnableDelayedExpansion

set searchDir=%~dp0..\..\..\analysis\data\
for /f %%i in ('dir "%searchDir%" /b/a-d/od/t:c *.json') do set LAST=%%i
echo The most recently created file is %LAST%

set fileDirectory=%searchDir%%LAST%
echo The directory is %fileDirectory%

copy "%fileDirectory%" "%~dp0..\..\assets\data\" /Y
set newDirFile=%~dp0..\..\assets\data\%LAST%
echo The new directory is %newDirFile%
ren %newDirFile% HeatMapData.json 

copy "..\Not executing\HeatMapShowAutoLVL3.edencm" "..\" /Y 

setlocal enableextensions disabledelayedexpansion

set readJSONFile=%~dp0..\..\assets\data\HeatMapData.json

set "replace=%readJSONFile%"
set "search=REPLACE"

set "textFile=..\HeatMapShowAutoLVL3.edencm"

for /f "delims=" %%i in ('type "%textFile%" ^& break ^> "%textFile%" ') do (
    set "line=%%i"
    setlocal enabledelayedexpansion
    >>"%textFile%" echo(!line:%search%=%replace%!
    endlocal
)

cd "..\.."
".\EDEN_Main.exe"

cd ".\commands\"

del ".\HeatMapShowAutoLVL3.edencm"

del "%readJSONFile%"

cd "..\"