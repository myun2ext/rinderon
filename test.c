#include <windows.h>

HWND RinderonCreateWindow(LPCSTR szWindowTitle, int nWidth, int nHeight);
void* RinderonInitD3d9(HWND hWnd, UINT width, UINT height);

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hInstPrev, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd = RinderonCreateWindow("Test", 640, 480);
	RinderonInitD3d9(hWnd, 640, 480);
}
