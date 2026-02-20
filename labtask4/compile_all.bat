@echo off
echo Compiling all C++ lab task questions...
echo.

echo Compiling q1.cpp...
g++ -o q1.exe q1.cpp
if %ERRORLEVEL% EQU 0 (
    echo q1.cpp compiled successfully!
) else (
    echo ERROR: q1.cpp failed to compile!
)
echo.

echo Compiling q2.cpp...
g++ -o q2.exe q2.cpp
if %ERRORLEVEL% EQU 0 (
    echo q2.cpp compiled successfully!
) else (
    echo ERROR: q2.cpp failed to compile!
)
echo.

echo Compiling q3.cpp...
g++ -o q3.exe q3.cpp
if %ERRORLEVEL% EQU 0 (
    echo q3.cpp compiled successfully!
) else (
    echo ERROR: q3.cpp failed to compile!
)
echo.

echo Compiling q4.cpp...
g++ -o q4.exe q4.cpp
if %ERRORLEVEL% EQU 0 (
    echo q4.cpp compiled successfully!
) else (
    echo ERROR: q4.cpp failed to compile!
)
echo.

echo Compiling q5.cpp...
g++ -o q5.exe q5.cpp
if %ERRORLEVEL% EQU 0 (
    echo q5.cpp compiled successfully!
) else (
    echo ERROR: q5.cpp failed to compile!
)
echo.

echo Compilation completed!
echo.
echo To run the programs:
echo q1.exe
echo q2.exe
echo q3.exe
echo q4.exe
echo q5.exe
pause