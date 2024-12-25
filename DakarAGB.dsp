# Microsoft Developer Studio Project File - Name="DakarAGB" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) External Target" 0x0106

CFG=DakarAGB - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "DakarAGB.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DakarAGB.mak" CFG="DakarAGB - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DakarAGB - Win32 Release" (based on "Win32 (x86) External Target")
!MESSAGE "DakarAGB - Win32 Debug" (based on "Win32 (x86) External Target")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "DakarAGB"
# PROP Scc_LocalPath "."

!IF  "$(CFG)" == "DakarAGB - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Cmd_Line "NMAKE /f DakarAGB.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "DakarAGB.exe"
# PROP BASE Bsc_Name "DakarAGB.bsc"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Cmd_Line "nmake /f "DakarAGB.mak""
# PROP Rebuild_Opt "/a"
# PROP Target_File "DakarAGB.exe"
# PROP Bsc_Name ""
# PROP Target_Dir ""

!ELSEIF  "$(CFG)" == "DakarAGB - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Cmd_Line "NMAKE /f DakarAGB.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "DakarAGB.exe"
# PROP BASE Bsc_Name "DakarAGB.bsc"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Cmd_Line "nmake /f "DakarAGB.mak""
# PROP Rebuild_Opt "/a"
# PROP Target_File "DakarAGB.exe"
# PROP Bsc_Name ""
# PROP Target_Dir ""

!ENDIF 

# Begin Target

# Name "DakarAGB - Win32 Release"
# Name "DakarAGB - Win32 Debug"

!IF  "$(CFG)" == "DakarAGB - Win32 Release"

!ELSEIF  "$(CFG)" == "DakarAGB - Win32 Debug"

!ENDIF 

# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Alphaset1.c
# End Source File
# Begin Source File

SOURCE=.\are_Graphics_DrawTri.s
# End Source File
# Begin Source File

SOURCE=.\car.c
# End Source File
# Begin Source File

SOURCE=.\Controls.c
# End Source File
# Begin Source File

SOURCE=.\Dakar.c
# End Source File
# Begin Source File

SOURCE=.\Dakar_DataEvents.c
# End Source File
# Begin Source File

SOURCE=.\Dakar_Logic.c
# End Source File
# Begin Source File

SOURCE=.\Dakar_LogicGame.c
# End Source File
# Begin Source File

SOURCE=.\Dakar_LogicGameRender.c
# End Source File
# Begin Source File

SOURCE=.\Dakar_LogicMenu.c
# End Source File
# Begin Source File

SOURCE=.\Debug.c
# End Source File
# Begin Source File

SOURCE=.\fixed.c
# End Source File
# Begin Source File

SOURCE=.\Globals.c
# End Source File
# Begin Source File

SOURCE=.\Graphics.c
# End Source File
# Begin Source File

SOURCE=.\Interrupts.c
# End Source File
# Begin Source File

SOURCE=.\mainmenu.c
# End Source File
# Begin Source File

SOURCE=.\Map.c
# End Source File
# Begin Source File

SOURCE=.\matrix.c
# End Source File
# Begin Source File

SOURCE=.\nintendo_header.s
# End Source File
# Begin Source File

SOURCE=.\Platform.c
# End Source File
# Begin Source File

SOURCE=.\sdtio.c
# End Source File
# Begin Source File

SOURCE=.\share.c
# End Source File
# Begin Source File

SOURCE=.\Sound.c
# End Source File
# Begin Source File

SOURCE=.\start.s
# End Source File
# Begin Source File

SOURCE=.\Track.c
# End Source File
# Begin Source File

SOURCE=.\trackdata.c
# End Source File
# Begin Source File

SOURCE=.\vector.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AdditionalAGBDefines.h
# End Source File
# Begin Source File

SOURCE=.\BasicDefines.h
# End Source File
# Begin Source File

SOURCE=.\BasicTypes.h
# End Source File
# Begin Source File

SOURCE=.\car.h
# End Source File
# Begin Source File

SOURCE=.\cardefines.h
# End Source File
# Begin Source File

SOURCE=.\Controls.h
# End Source File
# Begin Source File

SOURCE=.\Dakar.h
# End Source File
# Begin Source File

SOURCE=.\Debug.h
# End Source File
# Begin Source File

SOURCE=.\Extern.h
# End Source File
# Begin Source File

SOURCE=.\fixed.h
# End Source File
# Begin Source File

SOURCE=.\Graphics.h
# End Source File
# Begin Source File

SOURCE=.\Interrupts.h
# End Source File
# Begin Source File

SOURCE=.\Macros.h
# End Source File
# Begin Source File

SOURCE=.\Map.h
# End Source File
# Begin Source File

SOURCE=.\matrix.h
# End Source File
# Begin Source File

SOURCE=.\Platform.h
# End Source File
# Begin Source File

SOURCE=.\sdtio.h
# End Source File
# Begin Source File

SOURCE=.\share.h
# End Source File
# Begin Source File

SOURCE=.\Sound.h
# End Source File
# Begin Source File

SOURCE=.\trackdata.h
# End Source File
# Begin Source File

SOURCE=.\vector.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "Library Headers"

# PROP Default_Filter "*.h"
# Begin Source File

SOURCE=.\Agb.h
# End Source File
# Begin Source File

SOURCE=.\AgbDefine.h
# End Source File
# Begin Source File

SOURCE=.\AgbMacro.h
# End Source File
# Begin Source File

SOURCE=.\AgbMemoryMap.h
# End Source File
# Begin Source File

SOURCE=.\AgbMultiBoot.h
# End Source File
# Begin Source File

SOURCE=.\AgbSound.h
# End Source File
# Begin Source File

SOURCE=.\AgbSystemCall.h
# End Source File
# Begin Source File

SOURCE=.\AgbTypes.h
# End Source File
# Begin Source File

SOURCE=.\IsAgbPrint.h
# End Source File
# End Group
# Begin Group "Library Source"

# PROP Default_Filter "s"
# Begin Source File

SOURCE=.\AgbDefine.s
# End Source File
# Begin Source File

SOURCE=.\AgbMacro.s
# End Source File
# Begin Source File

SOURCE=.\AgbMemoryMap.s
# End Source File
# End Group
# End Target
# End Project
