if exist %userprofile%\Desktop\COVID-UNIP.lnk del %userprofile%\Desktop\COVID-UNIP.lnk
if exist %userprofile%\Desktop\ARQUIVOS-COVID-UNIP.lnk del /f %userprofile%\Desktop\ARQUIVOS-COVID-UNIP.lnk del %userprofile%\Desktop\ARQUIVOS-COVID-UNIP.lnk

echo Set oWS = WScript.CreateObject("WScript.Shell") > CreateShortcut.vbs
echo sLinkFile = "%userprofile%\Desktop\COVID-UNIP.lnk" >> CreateShortcut.vbs
echo Set oLink = oWS.CreateShortcut(sLinkFile) >> CreateShortcut.vbs
echo oLink.TargetPath = "%cd%\bin\Release\covid-unip.exe" >> CreateShortcut.vbs
echo oLink.WorkingDirectory = "%cd%\bin\Release" >> CreateShortcut.vbs
echo oLink.Description = "Programa para cadastro de pacientes com Covid UNIP" >> CreateShortcut.vbs
echo oLink.IconLocation = "%cd%\icon.bmp" >> CreateShortcut.vbs
echo oLink.Save >> CreateShortcut.vbs
cscript CreateShortcut.vbs
del CreateShortcut.vbs
echo Set oWS = WScript.CreateObject("WScript.Shell") > CreateShortcut.vbs
echo sLinkFile = "%userprofile%\Desktop\ARQUIVOS-COVID-UNIP.lnk" >> CreateShortcut.vbs
echo Set oLink = oWS.CreateShortcut(sLinkFile) >> CreateShortcut.vbs
echo oLink.TargetPath = "%cd%\bin\Release" >> CreateShortcut.vbs
echo oLink.WorkingDirectory = "%cd%\bin\Release" >> CreateShortcut.vbs
echo oLink.Description = "Pasta com os arquivos do programa Covid UNIP" >> CreateShortcut.vbs
echo oLink.IconLocation = "%SystemRoot%\System32\SHELL32.dll,3" >> CreateShortcut.vbs
echo oLink.Save >> CreateShortcut.vbs
cscript CreateShortcut.vbs
del CreateShortcut.vbs
