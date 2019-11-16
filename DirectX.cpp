#include "DirectX.h"


IDirect3D9Ex* p_Object = 0;
IDirect3DDevice9Ex* p_Device = 0;
D3DPRESENT_PARAMETERS p_Params;
ID3DXFont* pFontSmall=0;
ID3DXLine *pLine=0;



int DirectXInit(HWND hWnd)
{
	if(FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
		exit(1);

	ZeroMemory(&p_Params, sizeof(p_Params));    
    p_Params.Windowed = TRUE;   
    p_Params.SwapEffect = D3DSWAPEFFECT_DISCARD;    
    p_Params.hDeviceWindow = hWnd;    
	p_Params.MultiSampleQuality   = D3DMULTISAMPLE_NONE;
    p_Params.BackBufferFormat = D3DFMT_A8R8G8B8 ;     
    p_Params.BackBufferWidth = Width;    
    p_Params.BackBufferHeight = Height;    
    p_Params.EnableAutoDepthStencil = TRUE;
    p_Params.AutoDepthStencilFormat = D3DFMT_D16;

	if (FAILED(p_Object->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &p_Params, 0, &p_Device)))
		exit(1);

	if (!pLine)
		D3DXCreateLine(p_Device, &pLine);
	
	return 0;
}

int Render()
{
	
	
	if (tWnd == GetForegroundWindow())
	{
		
		p_Device->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);
		p_Device->BeginScene();








		//»æÖÆ
		DrawLine(400, 400, 500, 500,5, D3DCOLOR_RGBA(255, 0, 0, 255));
		DrawFilledRectangle(50, 50, 100, 100, D3DCOLOR_RGBA(255, 0, 0, 255));
		DrawString("Simple Text",30 , 10, 10, D3DCOLOR_RGBA(255, 0, 0, 255));
		DrawBorderBox(200, 200, 300, 300, 2, D3DCOLOR_RGBA(255, 0, 0, 255));
		Box3D(500, 500, 500,600, D3DCOLOR_RGBA(255, 0, 0, 255));
		//


		
		
		
		
		
		
		
		
		p_Device->EndScene();
		p_Device->PresentEx(0, 0, 0, 0, 0);

		pFontSmall->Release();
		pFontSmall = nullptr;
		return 0;
	}

	p_Device->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);
	p_Device->BeginScene();
	p_Device->EndScene();
	p_Device->PresentEx(0, 0, 0, 0, 0);
	return 0;
}