#pragma once
#include <Windows.h>
#include <math.h>

typedef union _RGBQUAD {
	COLORREF rgb;
	struct {
		BYTE b;
		BYTE g;
		BYTE r;
		BYTE unused;
	};
} *PRGBQUAD;
typedef VOID(SHADER)(int t, int w, int h, PRGBQUAD prgbScreen);
extern VOID ShaderLoader(SHADER shadid, int Times);
typedef void(PAYLOAD)(int x, HDC hdc);
extern VOID PayloadLoader(PAYLOAD payname, int Times);
extern VOID Shad1(int t, int w, int h, PRGBQUAD PScreen);
extern VOID MidPay1(int t, int w, int h, PRGBQUAD PScreen);
extern VOID Shad2(int t, int w, int h, PRGBQUAD PScreen);
extern VOID Shad3(int t, int w, int h, PRGBQUAD PScreen);
extern VOID PreSha1(int t, int w, int h, PRGBQUAD prgbScreen);
extern VOID Shad4(int t, int w, int h, PRGBQUAD PScreen);