#include <windows.h>
#include <d3d9.h>

void Rinderon9Clear(IDirect3DDevice9* d3dDev)
{
	d3dDev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
}

void Rinderon9Fill(IDirect3DDevice9* d3dDev, D3DCOLOR cl)
{
	d3dDev->Clear(0, NULL, D3DCLEAR_TARGET, cl, 1.0f, 0);
}

void Rinderon9FillRect(IDirect3DDevice9* d3dDev, D3DCOLOR cl, const RECT& rect)
{
	d3dDev->Clear(0, &rect, D3DCLEAR_TARGET, cl, 1.0f, 0);
}
