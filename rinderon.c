#include <windows.h>

LRESULT CALLBACK RinderonWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_DESTROY:
			::PostQuitMessage(0);
			return 0;

		default:
			break;
	}
	return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
}

HWND RinderonCreateWindow(LPCSTR szWindowTitle, int nWidth, int nHeight)
{
	WNDCLASSEX wc;
	LPCSTR szWindowClassName = "__RinderonTemporaryWindowClass__";
	HWND hWnd;
	MSG msg;

	wc.cbSize        = sizeof(wc);
	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc   = RinderonWindowProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = NULL;
	wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = szWindowClassName;
	wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
	::RegisterClassEx(&wc);

	hWnd = ::CreateWindowEx(
	        WS_EX_APPWINDOW,
            szWindowClassName,
	        szWindowTitle,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            nWidth, nHeight,
            NULL,
            NULL,
            NULL,
            NULL);

	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	while (GetMessage (&msg,NULL,0,0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return hWnd;
}
