class Map
{
public:
	LPDIRECT3DVERTEXBUFFER8 m_pVB;//vertex buffer
	LPDIRECT3DTEXTURE8 m_pTexture[2];//
	LPDIRECT3DTEXTURE8 m_pRailingTexture;//rail texture
	LPDIRECT3DTEXTURE8 m_pTreeTexture;//tree texture

	CD3DMesh* m_pSkyBox;//3D mode 
	CD3DMesh* m_pWall;//3D mode
	D3DXVECTOR3 TreeLoc[40];//the location of the objects

	FLOAT m_fLeft;//left boundary
	FLOAT m_fRight;//right boundary

	void Render();//for render
	void InitObject();//to initial all the 3D mode vertex and materials
	void RestoreDeviceObjects(); //restore the device
	void InvalidateDeviceObjects();//release objects
};