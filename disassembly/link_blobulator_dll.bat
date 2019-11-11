@echo off

set _path="%cd%"
set files=%_path%\blobulator_obj\*.obj %_path%\lib\tier0.lib %_path%\lib\tier2.lib %_path%\lib\mathlib.lib

cd %VS140COMNTOOLS%
call vsvars32.bat

if not exist %_path%\bin (
mkdir %_path%\bin
)

link.exe /dll %files% /debug /out:%_path%\bin\blobulator.dll

pause