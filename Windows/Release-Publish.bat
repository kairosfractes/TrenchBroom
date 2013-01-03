@echo off

call Release-Build.bat

if errorlevel 1 goto errorDone

cd Release
del *.pdb
del TrenchBroom.log

For /f "tokens=1,2,3,4,5 delims=/. " %%a in ('date/T') do set CDate=%%c%%b%%a
For /f "tokens=1,2 delims=:" %%f in ('time /t') do set CTime=%%f%%g

7z.exe a "%DROPBOX%\TrenchBroom\TrenchBroom_Win32_%CDATE%_%CTIME%.zip" .\*
cd ..

goto done

:errorDone

:done

pause

