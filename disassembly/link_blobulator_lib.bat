@echo off

set _path="%cd%"

cd %VS140COMNTOOLS%
call vsvars32.bat

mkdir %_path%\bin
link.exe /lib %_path%/blobulator_obj/*.obj /out:%_path%\bin\blobulator.lib

pause