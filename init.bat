echo off
set apk=%1
aapt.exe dump badging %apk% > .\aaptOut.txt
echo AndroidManifest.xml data extracted