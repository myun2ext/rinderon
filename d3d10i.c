#include <windows.h>
#include <d3d10.h>

typedef HRESULT (*D3D10CreateDeviceAndSwapChain_t)(
  IDXGIAdapter *pAdapter,
  D3D10_DRIVER_TYPE DriverType,
  HMODULE Software,
  UINT Flags,
  UINT SDKVersion,
  DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,
  IDXGISwapChain **ppSwapChain,
  ID3D10Device **ppDevice
);
D3D10CreateDeviceAndSwapChain_t D3D10CreateDeviceAndSwapChain_i;

void RinderonLoadD3d10Functions()
{
	HMODULE hLibrary = LoadLibrary("d3d10");
	D3D10CreateDeviceAndSwapChain_i = (D3D10CreateDeviceAndSwapChain_t)GetProcAddress(hLibrary, "D3D10CreateDeviceAndSwapChain");
}
