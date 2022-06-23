#pragma once
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

/*
* I added some bonus code for you :D
*/

//NT checker
VOID CheckNTVer(INT a) {
	OSVERSIONINFOEX info;
	ZeroMemory(&info, sizeof(OSVERSIONINFOEX));
	info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	GetVersionEx((LPOSVERSIONINFO)&info);

	if (info.dwMajorVersion == 5)
	{
		//IF XP
	}
	else if (info.dwMajorVersion == 6, 10) {
		//IF VISTA
		if (MessageBoxW(0, L"  This malware was build for XP use\n  Note that some payloads wont work on other NT Versions.\n  Its reccomended to run this malware on WinXP\n  Still Want to continue?", L"NT Checker", MB_YESNO | MB_ICONWARNING) == IDNO) {
			exit(0);
		}
	}
}