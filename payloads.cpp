#include "payloads.h"
#define fori(x) for (INT i = 0; i < x; i++)

//Payloads Executor
typedef void(PAYLOAD)(int x, HDC hdc);
VOID PayloadLoader(PAYLOAD payname, int Times) {
	HDC hdc = GetDC(0);
	fori(Times) {
		payname(i, hdc);
	}
	ReleaseDC(0, hdc);
	DeleteDC(hdc);
	RedrawWindow(0, 0, 0, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	Sleep(110);
}

//Screen 
BOOL CALLBACK MonEnPc(HMONITOR hMonitor, HDC hdcMonitor, PRECT PRB, LPARAM LPR) {
	PRECT PPR = (RECT*)LPR;
	UnionRect(PPR, PPR, PRB);
	return true;
}
RECT GetScreen() {
	RECT RCS = { 0 };
	EnumDisplayMonitors(NULL, NULL, MonEnPc, (LPARAM)&RCS);
	return RCS;
}
POINT GetScPos() {
	RECT RCS = GetScreen();
	POINT PTS = {
		RCS.left,
		RCS.top
	};
	return PTS;
}
SIZE GetScSize() {
	RECT RCS = GetScreen();
	SIZE SZS = {
		RCS.right - RCS.left,
		RCS.bottom - RCS.top
	};
	return SZS;
}

//SHADER EXECUTOR
typedef VOID(SHADER)(int t, int w, int h, PRGBQUAD PScreen);
VOID  ShaderLoader(SHADER shadid, int Times) {
	HDC hdc = GetDC(0);
	HDC HTS;
	PRGBQUAD PScreen;

	BITMAPINFO BitM = { 0 };
	HBITMAP HBS;

	POINT PTS = GetScPos();
	SIZE SZS = GetScSize();

	BitM.bmiHeader.biSize = sizeof(BITMAPINFO);
	BitM.bmiHeader.biBitCount = 32;
	BitM.bmiHeader.biPlanes = 1;
	BitM.bmiHeader.biWidth = SZS.cx;
	BitM.bmiHeader.biHeight = SZS.cy;
	BitM.bmiHeader.biHeight = SZS.cy;

	PScreen = { 0 };

	HTS = CreateCompatibleDC(hdc);
	HBS = CreateDIBSection(hdc, &BitM, 0, (void**)&PScreen, NULL, 0);
	SelectObject(HTS, HBS);

	fori(Times) {
		hdc = GetDC(0);
		BitBlt(HTS, 0, 0, SZS.cx, SZS.cy, hdc, 0, 0, SRCCOPY);
		shadid(i, SZS.cx, SZS.cy, PScreen);
		BitBlt(hdc, 0, 0, SZS.cx, SZS.cy, HTS, 0, 0, SRCCOPY);
		Sleep(10);
	}
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	Sleep(100);
}

VOID PreSha1(int t, int w, int h, PRGBQUAD PScreen) {
	for (int i = 0; i < w * h; i++) {
		t += 10 - i * w + h / 5;
		PScreen[i].rgb = (PScreen[i].rgb * 2 - t) % (RGB(255, 255, 255));
	}
}

VOID Shad1(int t, int w, int h, PRGBQUAD PScreen) {
	PRGBQUAD tp = { 0 };
	tp = PScreen;
	for (int i = 0; i < h; i++) {
		for (int m = 0; m < w; m++) {
			t += 10 - i * w + h / 5;
			PScreen[i * w + m].rgb = PScreen[i * w + m].r + t * i * 256;
		}
	}
}

VOID MidPay1(int t, int w, int h, PRGBQUAD PScreen) {
	HDC hdc = GetDC(0);
	int x = GetSystemMetrics(0);
	int y = GetSystemMetrics(1);
	fori (35000) {
		BitBlt(hdc, rand() % 5, rand() % 5, x, y, hdc, rand() % 5, rand() % 5, SRCCOPY);
	}
}

VOID Shad2(int t, int w, int h, PRGBQUAD PScreen) {
	for (int i = 0; i < h; i++) {
		for (int m = 0; m < w; m++) {
			t += 10 - i * w + h / 5;
			PScreen[i * w + m].rgb = PScreen[i * h + m].r + m * i * 500 + m, (PScreen[i * w + m].b + t) % 256;
		}
	}
}

VOID Shad3(int t, int w, int h, PRGBQUAD PScreen) {
	for (int i = 0; i < h; i++) {
		for (int m = 0; m < w; m++) {
			t += 30 - i * w + h / 30;
			PScreen[i * w + m].rgb = RGB((PScreen[i * w + m].r + t * i) % 256, (PScreen[i * 5].g) % 256, PScreen[i * w + m].b + t) % 256;
		}
	}
}

VOID Shad4(int t, int w, int h, PRGBQUAD PScreen) {
	for (int i = 0; i < h; i++) {
		for (int m = 0; m < w; m++) {
			t += 10 - i * w + h / 5;
			PScreen[i * w + m].rgb = PScreen[i * h + m].r + t * i * w + t, (PScreen[i * t + w].b + m) * 256 * PScreen[i * h + m].r + h * i * 500 + m * 104;
		}
	}
}

