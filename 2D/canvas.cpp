#include "stdafx.h"  
//global viarant
HINSTANCE hInst;  
HBITMAP bg;
HBITMAP dra;//two bit map handle, background and drangon
HDC  mdc;//memory device controller,to buffer the bit map  
//global function  
ATOM     MyRegisterClass(HINSTANCE hInstance);  
BOOL     InitInstance(HINSTANCE, int);  
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);  
void     MyPaint(HDC hdc);  
//the main function
int APIENTRY WinMain(HINSTANCE hInstance,  
                     HINSTANCE hPrevInstance,  
                     LPSTR     lpCmdLine,  
                     int       nCmdShow)  
{  
MSG msg;  
MyRegisterClass(hInstance);  
if (!InitInstance (hInstance, nCmdShow))   
{  
return FALSE;  
}  
//message loop  
while (GetMessage(&msg, NULL, 0, 0))   
{  
TranslateMessage(&msg);  
DispatchMessage(&msg);  
}  
return msg.wParam;  
}  
//register window class 
ATOM MyRegisterClass(HINSTANCE hInstance)  
{  
WNDCLASSEX wcex;  
wcex.cbSize = sizeof(WNDCLASSEX);   
wcex.style   = CS_HREDRAW | CS_VREDRAW;  
wcex.lpfnWndProc    = (WNDPROC)WndProc;  
wcex.cbClsExtra  = 0;  
wcex.cbWndExtra  = 0;  
wcex.hInstance   = hInstance;  
wcex.hIcon   = NULL;  
wcex.hCursor     = NULL;  
wcex.hCursor     = LoadCursor(NULL, IDC_ARROW);  
wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);  
wcex.lpszMenuName   = NULL;  
wcex.lpszClassName  = "canvas";  
wcex.hIconSm     = NULL;  
return RegisterClassEx(&wcex);  
}  
//initial the functions
//create a memory DC compitable with the window DC
//load the background bitmap and dragon bitmap from the files
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)  
{  
HWND hWnd;  
HDC hdc;  
hInst = hInstance;  
hWnd = CreateWindow("canvas", "little dragon" , WS_OVERLAPPEDWINDOW,  
CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);  
if (!hWnd)  
{  
return FALSE;  
}  
MoveWindow(hWnd,10,10,600,450,true);  
ShowWindow(hWnd, nCmdShow);  
UpdateWindow(hWnd);  
hdc = GetDC(hWnd);//get the window DC
mdc = CreateCompatibleDC(hdc);//create a memory DC compatible with the window DC
bg = (HBITMAP)LoadImage(NULL,"bg.bmp",IMAGE_BITMAP,600,450,LR_LOADFROMFILE);   
//load the back ground to the bg  
dra = (HBITMAP)LoadImage(NULL,"dra.bmp",IMAGE_BITMAP,170,99,LR_LOADFROMFILE);   
//load the dragon to dra
MyPaint(hdc);  
ReleaseDC(hWnd,hdc);  
return TRUE;  
}  
//the paint function  
//transparent the texture
void MyPaint(HDC hdc)  
{  
SelectObject(mdc,bg);  
BitBlt(hdc,0,0,600,450,mdc,0,0,SRCCOPY);//show the background to the window
SelectObject(mdc,dra);//select dragon to memory DC 
BitBlt(hdc,280,320,85,99,mdc,85,0,SRCAND);
//and the mask bit map and the background bitmap,the mask map is at（85,0），set the last parameter of BitBlt() function to SRCAND
BitBlt(hdc,280,320,85,99,mdc,0,0,SRCPAINT);
}
//OR the frontground bitmap and the background bitmap,the frontground bitmap is at (0,0),set the last parameter of BitBlt() function to SRCPAINT

//message dealing function 
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)  
{  
PAINTSTRUCT ps;  
HDC hdc;  
switch (message)  
{  
case WM_PAINT:   //repaint the window
hdc = BeginPaint(hWnd, &ps);  
MyPaint(hdc);  
EndPaint(hWnd, &ps);  
break;  
case WM_DESTROY:     //destroy the window
DeleteDC(mdc);  
DeleteObject(bg);  
DeleteObject(dra);  
PostQuitMessage(0);  
break;  
default:     //other message
return DefWindowProc(hWnd, message, wParam, lParam);  
   }  
   return 0;  
}  