//the class of window framwork
//responsible for the build of windows
//deal with message
//build 3D environment
//initial 3D object
//control IO
//render
//and initialization of other objects
class CMyD3DApplication
{
public:
	LPDIRECT3D0 m_pD3D;// Direct3D object
	LPDIRECT3DDEVICE8 m_pd3dDevice;//Direct3D device
	BOOL m_bLoadingApp;//whether the program is loading
	ID3DXFront* m_pD3DXFront;//to display text out
	UserInput m_UserInput;//store input materials
	MainMap* m_pMainMap;//map object, for the whole 3D map
	Pet* m_pPoring[];//pet object, for all the things about pet
	Int m_nRenderIndex[]; //buffer
	Interface* m_pMainIF;//initialization of the IF and drawing
	FLOAT m_fLeft; //left boundary of the map
	FLOAT m_fRight;//right boundary of the map
	FLOAT m_fTop;//top boundary of the map
	FLOAT m_fDown;//down boundary of the map
	FLOAT m_fTheta;//the angle of current view point
	FLOAT m_fMoveSpeed;//the move speed
	FLOAT m_fRotSpeed;//the rotate speed
	D3DXVECTOR3 m_vecCurLoc;//the vector of the current location
	D3DXVECTOR3 m_vecCurLookAt;//the location of the current view
	D3DXVECTOR3 m_vecUp;//the normal vector of current location

	void InitDeviceObjects();//initial device
	void RestoreDeviceObjects();//restore device
	void InvalidateDeviceObjects();//release device
	void DeleteDeviceObjects();//delete device
	void Render();//render
	void FrameMove();//deal with person move
	void FinalCleanUp();//clean all the object when exit
	void ConfirmDevice();//confirm the present device
	void RenderText();//show text out
	void UpdateInput();//update the input
	void ReadSettings();//read the login settings in the windows 
	void WriteSettings();//write the login settings
};