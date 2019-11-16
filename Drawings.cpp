#include "Drawings.h"

struct D3DTLVERTEX
{
	float x, y, z, rhw;
	DWORD color;
};

void Box3D(int HeadX, int HeadY, int bottomX, int bottomY, D3DCOLOR Color)
{
	//立体原型
	/*float DrawBox1 = 480 / Player_Distance;
	float DrawBox2 = 260 / Player_Distance;
	float DrawBox3 = 100 / Player_Distance;

	DrawLine （pDevice ，bottomX - DrawBox1 ，bottomY ，bottomX + DrawBox1 ，bottomY ，Color ）;
	DrawLine （pDevice ，HeadX - DrawBox1 ，HeadY ，HeadX + DrawBox1 ，HeadY ，Color ）;
	DrawLine （pDevice ，HeadX - DrawBox1 ，HeadY ，bottomX - DrawBox1 ，bottomY ，Color ）;
	DrawLine （pDevice ，HeadX + DrawBox1 ，HeadY ，bottomX + DrawBox1 ，bottomY ，Color ）;
	DrawLine （pDevice ，HeadX - DrawBox2 ，HeadY - DrawBox3 ，bottomX - DrawBox2 ，bottomY - DrawBox3 ，Color ）;
	DrawLine （pDevice ，bottomX - DrawBox1 ，bottomY ，bottomX - DrawBox2 ，bottomY - DrawBox3 ，Color ）;
	DrawLine （pDevice ，HeadX - DrawBox1 ，HeadY ，HeadX - DrawBox2 ，HeadY - DrawBox3 ，Color ）;
	DrawLine （pDevice ，（HeadX + DrawBox1 ） + DrawBox2 ，HeadY - DrawBox3 ，（bottomX + DrawBox1 ） + DrawBox2 ，bottomY - DrawBox3 ，Color ）;
	DrawLine （pDevice ，bottomX + DrawBox1 ，bottomY ，（bottomX + DrawBox1 ） + DrawBox2 ，bottomY - DrawBox3 ，Color ）;
	DrawLine （pDevice ，HeadX + DrawBox1 ，HeadY ，（HeadX + DrawBox1 ） + DrawBox2 ，HeadY - DrawBox3 ，Color ）;
	DrawLine （pDevice ，HeadX - DrawBox2 ，HeadY - DrawBox3 ，（HeadX + DrawBox1 ） + DrawBox2 ，HeadY - DrawBox3 ，Color ）;
	DrawLine （pDevice ，bottomX - DrawBox2 ，bottomY - DrawBox3 ，（bottomX + DrawBox1 ） + DrawBox2 ，bottomY - DrawBox3 ，Color ）;
*/

DrawLine ( bottomX - 5 ,bottomY ,bottomX + 5 ,bottomY ,1.5,Color);
DrawLine ( HeadX - 5 ,HeadY ,HeadX + 5 ,HeadY ,1.5,Color);
DrawLine ( HeadX - 5 ,HeadY ,bottomX - 5 ,bottomY ,1.5,Color);
DrawLine ( HeadX + 5 ,HeadY ,bottomX + 5 ,bottomY ,1.5,Color);
DrawLine ( HeadX - 7 ,HeadY - 10 ,bottomX - 7 ,bottomY - 10 ,  1.5,Color);
DrawLine ( bottomX - 5 ,bottomY ,bottomX - 7 ,bottomY - 10 , 1.5, Color);
DrawLine ( HeadX - 5 ,HeadY ,HeadX - 7 ,HeadY - 10 , 1.5, Color);
DrawLine ( (HeadX + 5 ) + 7 ,HeadY - 10 ,(bottomX + 5) + 7 ,bottomY - 10 , 1.5, Color);
DrawLine ( bottomX + 5 ,bottomY ,(bottomX + 5 ) + 7 ,bottomY - 10 , 1.5, Color);
DrawLine ( HeadX + 5 ,HeadY ,(HeadX + 5 ) + 7 ,HeadY - 10 , 1.5, Color);
DrawLine ( HeadX - 7 ,HeadY - 10 ,(HeadX + 5 ) + 7 ,HeadY - 10 , 1.5, Color);
DrawLine ( bottomX - 7 ,bottomY - 10 ,(bottomX + 5 ) + 7 ,bottomY - 10 , 1.5, Color);
}

void DrawLine(float x, float y, float x2, float y2, float width, D3DCOLOR color)
{
	
	D3DTLVERTEX qV[2] =
	{
		{ (float)x, (float)y, 0.0f, 1.0f, color },
	{ (float)x2, (float)y2, 0.0f, 1.0f, color },
	};

	p_Device->SetTexture(0, NULL);
	p_Device->SetRenderState(D3DRS_LIGHTING, FALSE);
	p_Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	p_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, 1);
	p_Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	p_Device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
	p_Device->SetRenderState(D3DRS_FOGENABLE, false);
	p_Device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	p_Device->DrawPrimitiveUP(D3DPT_LINELIST, 1, qV, sizeof(D3DTLVERTEX));
	
}

void DrawString(const char *fmt, int fontsize,int x, int y, D3DCOLOR color)
{
	
	D3DXCreateFont(p_Device,fontsize, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &pFontSmall);
	RECT FontPos;
	FontPos.left = x;
	FontPos.top = y;

	CHAR buf[124] = { '\0' };
	va_list va_alist;
	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	pFontSmall->DrawTextA(0, buf, -1, &FontPos, DT_NOCLIP,  color);
	
}

void DrawFilledRectangle(float x, float y, float w, float h, D3DCOLOR color)
{
	D3DRECT rect = { x, y, w, h };
    p_Device->Clear(1, &rect, D3DCLEAR_TARGET | D3DCLEAR_TARGET, color, 0, 0);
} 


void DrawBorderBox(int x, int y, int w, int h, int thickness, D3DCOLOR color)
{
	DrawFilledRectangle(x, y, w, y + thickness,  color); // x
	DrawFilledRectangle(x, y, x + thickness, h,  color); // y
	DrawFilledRectangle(x, h, w, h + thickness,  color); // w
	DrawFilledRectangle(w, y, w + thickness, h + thickness,  color); // h
}