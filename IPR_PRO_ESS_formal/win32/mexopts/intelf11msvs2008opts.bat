@echo off
rem INTELF11MSVS2008OPTS.BAT
rem
rem    Compile and link options used for building MEX-files using the
rem    Intel� Fortran Compiler 11.1 with the Microsoft� Visual Studio�
rem    2008 SP1 Professional Edition linker.
rem
rem StorageVersion: 1.0
rem FortrankeyFileName: INTELF11MSVS2008OPTS.BAT
rem FortrankeyName: Intel Visual Fortran
rem FortrankeyManufacturer: Intel
rem FortrankeyVersion: 11.1
rem FortrankeyLanguage: Fortran
rem
rem    $Revision: 1.1.6.1 $  $Date: 2009/08/14 03:21:37 $
rem
rem ********************************************************************
rem General parameters
rem ********************************************************************
set MATLAB=%MATLAB%
set IFORT_COMPILER11=%IFORT_COMPILER11%
set VSINSTALLDIR=%VS90COMNTOOLS%\..\..
set VCINSTALLDIR=%VSINSTALLDIR%\VC
rem In this case, LINKERDIR is being used to specify the location of the SDK
set LINKERDIR='.registry_lookup("SOFTWARE\Microsoft\Microsoft SDKs\Windows" , "CurrentInstallFolder").'
set PATH=%IFORT_COMPILER11%\Bin\ia32;%VCINSTALLDIR%\BIN\;%VSINSTALLDIR%\VC\bin;%LINKERDIR%\bin;%VSINSTALLDIR%\Common7\IDE;%VSINSTALLDIR%\Common7\Tools;%VSINSTALLDIR%\Common7\Tools\bin;%VCINSTALLDIR%\VCPackages;%MATLAB_BIN%;%PATH%
set INCLUDE=%IFORT_COMPILER11%\Include;%VCINSTALLDIR%\ATLMFC\INCLUDE;%VCINSTALLDIR%\INCLUDE;%LINKERDIR%\include;%INCLUDE%
set LIB=%IFORT_COMPILER11%\Lib\ia32;%VCINSTALLDIR%\ATLMFC\LIB;%VCINSTALLDIR%\LIB;%LINKERDIR%\lib;%VSINSTALLDIR%\SDK\v2.0\lib;%MATLAB%\extern\lib\win32;%LIB%
set MW_TARGET_ARCH=win32

rem ********************************************************************
rem Compiler parameters
rem ********************************************************************
set COMPILER=ifort
set COMPFLAGS=/fpp /Qprec "/I%MATLAB%/extern/include" -c -nologo -DMATLAB_MEX_FILE /fixed /MD /fp:source /assume:bscc
set OPTIMFLAGS=/O2 /DNDEBUG
set DEBUGFLAGS=/Z7
set NAME_OBJECT=/Fo

rem ********************************************************************
rem Linker parameters
rem ********************************************************************
set LIBLOC=%MATLAB%\extern\lib\win32\microsoft
set LINKER=link
set LINKFLAGS=/dll /export:MEXFUNCTION /LIBPATH:"%LIBLOC%" libmx.lib libmex.lib libmat.lib /implib:"%LIB_NAME%.x" /MAP:"%OUTDIR%%MEX_NAME%%MEX_EXT%.map" /NOLOGO /INCREMENTAL:NO
set LINKOPTIMFLAGS=
set LINKDEBUGFLAGS=/debug /PDB:"%OUTDIR%%MEX_NAME%%MEX_EXT%.pdb"
set LINK_FILE=
set LINK_LIB=
set NAME_OUTPUT=/out:"%OUTDIR%%MEX_NAME%%MEX_EXT%"
set RSP_FILE_INDICATOR=@

rem ********************************************************************
rem Resource compiler parameters
rem ********************************************************************
set RC_COMPILER=rc /fo "%OUTDIR%mexversion.res"
set RC_LINKER=

set POSTLINK_CMDS=del "%LIB_NAME%.x" "%LIB_NAME%.exp"
set POSTLINK_CMDS1=mt -outputresource:"%OUTDIR%%MEX_NAME%%MEX_EXT%";2 -manifest "%OUTDIR%%MEX_NAME%%MEX_EXT%.manifest"
set POSTLINK_CMDS2=del "%OUTDIR%%MEX_NAME%%MEX_EXT%.manifest" 
set POSTLINK_CMDS3=del "%OUTDIR%%MEX_NAME%%MEX_EXT%.map"
