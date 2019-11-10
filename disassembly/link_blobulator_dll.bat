@echo off

set _path="%cd%"
set files=%_path%\blobulator_obj\*.obj %_path%\..\..\..\lib\public\tier0.lib %_path%\..\..\..\lib\public\tier2.lib %_path%\..\..\..\lib\public\mathlib.lib

cd %VS140COMNTOOLS%
call vsvars32.bat

mkdir %_path%\bin
link.exe /dll %files% /debug /out:%_path%\bin\blobulator.dll

pause