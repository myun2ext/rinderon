#include <windows.h>
#include <d3d9.h>

LPDIRECT3DDEVICE9 RinderonInitD3d9(HWND hWnd, UINT width, UINT height)
{
	IDirect3D9* pD3d;
	IDirect3DDevice9* pD3dDev;

	pD3d = ::Direct3DCreate9(D3D_SDK_VERSION);
	if ( pD3d == NULL )
		return NULL;

	D3DPRESENT_PARAMETERS d3dParams = {
		width, height,
		D3DFMT_UNKNOWN,
		0,
		D3DMULTISAMPLE_NONE,
		0,
        D3DSWAPEFFECT_DISCARD,
        NULL,
        TRUE,
        TRUE,
        D3DFMT_D24S8,
        0,
        0
	};

	if( FAILED( pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dParams, &pD3dDev ) ) )
	if( FAILED( pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParams, &pD3dDev ) ) )
	if( FAILED( pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dParams, &pD3dDev ) ) )
	if( FAILED( pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParams, &pD3dDev ) ) )
	{
		pD3d->Release();
		return NULL;
	}
	return pD3dDev;
}
