copy "..\Not executing\HeatMapShowAuto.edencm" "..\" /Y 

@echo off
setlocal enableextensions disabledelayedexpansion

set "replace=%~dp0..\..\assets\data\HeatMapData.json"
set "search=REPLACE"

set "textFile=..\HeatMapShowAuto.edencm"

for /f "delims=" %%i in ('type "%textFile%" ^& break ^> "%textFile%" ') do (
    set "line=%%i"
    setlocal enabledelayedexpansion
    >>"%textFile%" echo(!line:%search%=%replace%!
    endlocal
)

cd "..\.."
".\EDEN_Main.exe"

cd ".\commands\"

del ".\HeatMapShowAuto.edencm"

cd "..\"
