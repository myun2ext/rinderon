#include <windows.h>
#include <d3d10.h>

struct D3dCreated {
	ID3D10Device* pD3dDev;
	IDXGISwapChain* pSwapChain;
};

D3dCreated RinderonD3d10CreateDeviceAndSwapChain(HWND hWnd, UINT width, UINT height, UINT frameRate)
{
	ID3D10Device* pD3dDev;
	IDXGISwapChain* pSwapChain;

	DXGI_SWAP_CHAIN_DESC swapChainDesc = {
		{ width, height, {frameRate, 1}, DXGI_FORMAT_R16G16B16A16_FLOAT, DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED, DXGI_MODE_SCALING_CENTERED},
		{1, 0}, DXGI_USAGE_RENDER_TARGET_OUTPUT, 1, hWnd, true, DXGI_SWAP_EFFECT_DISCARD, DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH
	};

	if( FAILED( D3D10CreateDeviceAndSwapChain( 0, D3D10_DRIVER_TYPE_HARDWARE, 0, 0, D3D10_SDK_VERSION, &swapChainDesc, &pSwapChain, &pD3dDev ) ) )
		D3dCreated d3dc = { NULL, NULL };
		return d3dc;
	}

	D3dCreated d3dc = { pD3dDev, pSwapChain };
	return d3dc;
}

D3dCreated RinderonInitD3d10(HWND hWnd, UINT width, UINT height, UINT frameRate)
{
	ID3D10Texture2D *pBackBuffer;
	ID3D10RenderTargetView *pRenderTargetView;
	MSG msg;

	D3dCreated d3dc = RinderonD3d10CreateDeviceAndSwapChain(hWnd, width, height, frameRate);
	ID3D10Device* pD3dDev = d3dc.pD3dDev;
	IDXGISwapChain* pSwapChain = d3dc.pSwapChain;

	pSwapChain->GetBuffer( 0, __uuidof(ID3D10Texture2D), (void**)&pBackBuffer );
	if ( FAILED ( pD3dDev->CreateRenderTargetView( pBackBuffer, 0, &pRenderTargetView ) ) ) {
		pSwapChain->Release(); pD3dDev->Release();
		return d3dc;
	};

	pD3dDev->OMSetRenderTargets( 1, &pRenderTargetView, 0 );
	pBackBuffer->Release();

	D3D10_VIEWPORT vp = { 0, 0, width, height, 0.0f, 1.0f };
	pD3dDev->RSSetViewports( 1, &vp );

	ShowWindow( hWnd, SW_SHOW );

	do{
		if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) ){ DispatchMessage( &msg ); }
		else {
			float ClearColor[4] = { 0.0f, 0.125f, 0.6f, 1.0f };
			pD3dDev->ClearRenderTargetView( pRenderTargetView, ClearColor );
			pSwapChain->Present( 0, 0 );
		}
	}while( msg.message != WM_QUIT );

	pD3dDev->ClearState();
	pRenderTargetView->Release();
	pD3dDev->Release();
	pSwapChain->Release();

	return d3dc;
}
