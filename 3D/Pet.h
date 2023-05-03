class Pet
{
public:
	LPDIRECT3DVERTEXBUFFER8 m_pVB;//vertex buffer
	LPDIRECT3DTEXTURE8 m_pTexture[8];//
	LPDIRECT3DTEXTURE8 m_pMindTexture[3];
	FLOAT m_fHeight;
	FLOAT m_fWidth;
	FLOAT m_fTheta;//the angle the pet face to
	FLOAT m_fDistance;//diatance from the player
	D3DCOLOR m_Color;//color of the base
	D3DXVECTOR3 m_vecLoc;//location of the pet
	
	STATE MonState;//the state of the pet, includign weight, age, hunger and mood
	int m_nMindMode;//the current mood of the pet
	
	FLOAT m_fRenderTheta; //the reference angle for rendering
	int m_iCtr;//
	int m_iLR;//left || right
	int m_iFB;//front || back
	int m_iWaitTime;//the time pet has waited

	FLOAT m_fMoveX;//x coordinate of moving object
	FLOAT m_fMoveZ;//z coordinate of moving object
	FLOAT m_fLength;//distance of moving
	bool m_bStop;//whether the pet is moving

	void Rendering();//rendering
	void InitObject();//initial the vertex, texture, location, color
	void InvalidateDeviceObjects();//release the objects;

	void RandomMove();//random move
	void Behavior();//interact with the player

	double getLoc();//get the location of the pet
	double getTheta();//get the angle the pet face to
	double getDiatance();//get the distance between the pet and the player
	State getState();//get the State of the pet
};