@REM ".\Tool\build\link.bat" "$K" !P @L
@set PATH="%1C51\bin";%PATH%
@"Tool\build\auto_link.exe" --uv "%2" --target "RL6193_Project" --opt 3 --sort --hex2bin ".\HexToBin.exe"

if exist .\Output\RL6193\RL6193_Project_WithChkSum.bin del .\Output\RL6193\RL6193_Project_WithChkSum.bin
.\AddCheckSum.exe .\Output\RL6193\RL6193_Project.bin  .\Output\RL6193\RL6193_Project_WithChkSum.bin BANK1 .\Output\RL6193\HDR.bin HdrBank14
if exist .\Output\RL6193\RL6193_Project.bin del .\Output\RL6193\RL6193_Project.bin