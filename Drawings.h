#ifndef DRAWINGS_H
#define DRAWINGS_H


#include "DirectX.h"

#pragma warning( disable : 4244 )
#pragma warning( disable : 4996 )


#include <d3dx9.h>
#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

void Box3D(int HeadX, int HeadY, int bottomX, int bottomY, D3DCOLOR Color);
void DrawLine(float x, float y, float x2, float y2, float width, D3DCOLOR color);
void DrawString(const char *fmt, int fontsize, int x, int y, D3DCOLOR color);
void DrawFilledRectangle(float x, float y, float w, float h, D3DCOLOR color);
void DrawBorderBox(int x, int y, int w, int h, int thickness, D3DCOLOR color);

#endif