
//create a window
//initial the window
INT WINAPI WinMain( HINSTANCE hInst, 
				   HINSTANCE, 
				   LPSTR, INT)
{
	//regist window class
	WNDCLASSEX wc={ sizeof(WNDCLASSEX), 
		CS_CLASSDC,
		MsgProc, 
		0L, 
		0L,
		GetModuleHandle(NULL),
		NULL, NULL, NULL, NULL,
		"D3D app", 
		NULL};
	RegisterClassEx (&wc);
	//create app window
	HWND hWnd= CreateWindow("D3D app", 
		"D3D app", 
		WS_OVERLAPPEDWINDOW,
		100, 100, 300, 300, 
		GetDesktopWindow(), 
		NULL, 
		wc.hInstance,
		NULL);
}
//initial D3D
//create a Direct3D object
g_pD3D = Direct3DCreate8( D3D_SDK_VERSION );
//get display mode
D3DDISPLAYMODE d3ddm;
g_pD3D -> GetAdapterDisplayMode(
								D3DADAPTER_DEFAULT, &d3ddm);
//set parameter
D3DPRESENT_PARAMETERS d3dpp;
ZeroMemory( &d3dpp, sizeof(d3dpp));
d3dpp.Windowed =TRUE;
d3dpp.SwapEffect = D3DWAPEFFECT_DISCARD;
d3dpp.BackBufferFormat = d3ddm.Format;
//create device
g_pD3D->CreateDevice(
					 D3DADAPTER_DEFAULT,
					 D3DDEVTYPE_HAL,
					 hWnd,
					 D3DCCREATE_SOFTWARE_VERTEXPROCESSING,
					 &d3dpp,
					 &g_pd3dDevice )

//deal system massage
MSG msg;
while (GetMessage (&msg, MULL, 0, 0))
{
	TranslateMessage( &msg );
	DispatchMessage( &msg );
}


LRESULT WINAPI MsgProc( HWND hWnd, UNIT msg, WPARAM wParam, LPARAM lParam)
{
	switch ( msg )
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
		Render();
		ValidateRect( hWnd, NULL );
		return 0;
	}
	return DefWindowProc( hWnd, msg, wParam, lParam);
}

//define vertex type
struct CUSTOMVERTEX
{
	FLOAT x,y,z;
	DWORD color;
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)

//create buffer

CUSTOMVERTEX g_Vertices[]=
{
	{ 10.0f, 0.0f, 0.5f, 0xffff0000,},
	{ 0.0f, 10.0f, 0.5f, 0xff00ff00,},
	{ -10.0f, 0.0f, 0.5f, 0xff00ffff,},
};
if(FAILED( g_pd3dDevice->CreateVertexBuffer( 
   3*sizeof(CUSTOMVERTEX), 
   0, 
   D3DFVF_CUSTOMVERTEX, 
   D3DPOLL_DEFAULT, &g_pVB)))
   return E_FALL;

VOID* pVerticas;
if( FAILED( g_pVB->Lock( 0,sizeof (g_Vertices), (BYTE **)&pVertices, 0)))
	return E_FAIL;
memcpy( pVertices, g_Vertices, sizeof(g+Vertices));
g_pVB->Unlock();

//draw
g_pd3dDevice->Clear( 0,
					NULL,
					D3DCLEAR_TARGET,
					D3DCOLOR_XRGB(0,0,255),
					1.0f, 0L );
g_pd3dDevice->BeginScene();
g_pd3dDecive->SetStreamSource(
							  0,g_pVB,sizeof(CUSTOMVERTEX) );
g_pd3dDevice->SetVertexShader(
							  D3DFVF_CUSTOMVERTEX ); 
g_pd3dDevice->DrawPrimitive(
							D3DPT_TRIANGLELIST,
							0,
							1 );
g_pd3dDevice->EndScene();
//finish
 VOID Cleanup()
 {
	 if( g_pd3dDevice != NULL)
		 g_pd3dDevice->Release();
	 if( g_pD3D != NULL)
		 g_pD3D->Release();
 }