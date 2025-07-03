@echo off
:goto start

:: Set your title ID here, this will be used for transferring the 3gx file
set title_id=00040000001ACB00

:start
    for %%F in (%CD%) do set folder_name=%%~nxF
    set plugin_name=%folder_name%.3gx
    set citra_path=%userprofile%\AppData\Roaming\Citra\sdmc\luma\plugins\%title_id%\
    set sd_path=E:\luma\plugins\%title_id%\
    echo Plugin build
    set w=[0;0m
    set r=[0;31m
    set g=[0;92m
    set b=[0;94m
    set p=[0;95m
    set y=[0;33m
    goto :build

:build
    cls
    echo %b%Plugin build
    echo ------------%r%
    echo.
    make clean
    echo %p%
    make -j
    echo.
    goto ask

:transfer_citra
    cls
    if not exist %plugin_name% (
        echo %r%%plugin_name% does not exist.%w%
        echo.
        goto :ask
    )

    if not exist %citra_path% (
        mkdir %citra_path%
    )

    copy %plugin_name% %citra_path% > nul
    echo %g%Copied plugin to %y%%citra_path%%g%.%w%
    echo.
    goto :ask

:transfer_sd
    cls
    if not exist %plugin_name% (
        echo %r%%plugin_name% does not exist.%w%
        echo.
        goto :ask
    )

    if not exist %sd_path% (
        echo %r%%sd_path% does not exist.%w%
        echo.
        goto :ask
    )

    copy %plugin_name% %sd_path% > nul
    echo %g%Copied plugin to %y%%sd_path%%g%.%w%
    echo.
    goto :ask

:ask
    echo %b%Press %y%R%b% to re-build.
    echo Press %y%C%b% to transfer to Citra.
    echo Press %y%S%b% to transfer to the SD card.
    echo Press %y%X%b% to close.%w%
    choice /C RCSX /N
    if %errorlevel%==1 goto :build
    if %errorlevel%==2 goto :transfer_citra
    if %errorlevel%==3 goto :transfer_sd
    if %errorlevel%==4 exit
