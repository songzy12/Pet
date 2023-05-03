//view point movement
D3DXMATRIX matView;
if( m_UserInput.bRotateLeft && !m_UserInput.bRotateRight)//turn left
{
	m_fTheta += m_fRotSpeed;
	D3DMatrixRotationY( &matView, D3DXToRadian(-m_fRotSpeed));
	D3DVec3TransformNormal(
		&m_vecCurLookAt, 
		&(m_vecCurLookAt-m_vecCurloc),
		&matView);
	m_vecCurLookAt += m_vecCurLoc;
}
else if( m_UserInput.bRotateRight && !m_UserInput.bRotateLeft )//turn right
{
	m_fTheta -= m_fRotSpeed;//angle of turn 
	D3DXMatrixRotationY( &matView, D3DToRadian(m_fRotSpeed));//create the rotation matrix

	D3DVec3TransformNormal(
		&m_vecCurLookAt,
		&(m_vecCurLookAt-m_vecCurLoc),
		&matView);//act on the rotation matrix
	v_vecCurLookAt += m_vecCurloc;
}
if( m_UserInput.bRotateUp && !m_UserInput.bRotateDown )//move forward
{
	D3DXVECTOR3 offset = D3DXVECTOR3(
		m_fMoveSpeed*cosf(D3DToRadian(m_fTheta)),
		0.0f,
		m_fMoveSpeed*sinf(D3DToRadian(m_fTheta)) );//the offset
	m_vecCurLoc +=offset;
	m_vecCurLookAt += offset;
}
else if( m_UserInput.bRotateDown && !m_UserInput.bRotateUp )//move backward
{
	D3DVECTOR3 offset = D3DXVECTOR3(
		m_fMoveSpeed*cosf(D3DXToRadian(m_fTheta)),
		0.0f,
		m_fMoveSpeed*sinf(D3DXToRadian(m_fTheta)) );
	m_vecCurLoc -= offset;
	m_vecCurLookAt -= offset;
}

D3DMatrixLookAtLH ( &matView, &m_vecCurLoc, &m_vecCurLookAt, &m_vecUp);//create the view transform matrix
m_pd3dDevice->SetTransform( D3DTS_VIEW, &matView);//set the view matrix.

//construct 3D scene
struct ThreeDVERTEX
{
	D3DXVECTOR3 position;//position for the vertex
	D3DCOLOR color;//color
	FLOAT tu,tv;//the position for the texture
}
#define D3DFVF_ThreeDVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX1)
ThreeDVERTEX* pVertices;
if( FAILED( hr = m_pVB->Lock( 0, 0, (BYTE**)&pVertices, 0 )))
return DXTRACE_ERR_NOMSGBOX("Lock", hr);//lock before load in mode material
FLOAT range = m_fRight - m_fLeft;
//a floor mode
for( int i=0; i<4; i++)
{
	pVertices[i].position = D3DXVECTOR3(
		(float)pow(-1,i/2)* -range*5.0f,
		0.0f,
		(float)pow(-1,i+1)*range*5.0f );
	pVertices[i].color = 0xffffffff;
	pVertices[i].tu =(i/2)*range*2.0f;
	pVertices[i].tv =((i+1)%2)*range*2.0f;
}
//tree mode
for( i=4;i<8;i++)
{
	pVertices[i].position =D3DXVECTOR3(
		0.0f,
		(i%2)*3.02f*2.0f,
		(float)pow(-1,i/2)*1.33f*2.0f );
	pVertices[i].color =0xffffffff;
	pVertices[i].tu =((i-4)/2)*1.0f;
	pVertices[i].tv =((i+1)%2)*1.0f;
}
//load in grass texture file
D3DXCreateTextureFromFile( pd3dDevice,
						  "grass.jpg",
						  &m_pTexture[0] );
//load in trees texture file
D3DXCreateTextureFromFile( pd3dDevice,
						  "trees.tga",
						  &m_pTreeTexture );
//set view transform
D3DMatrixIdentity( &matWorld );
pd3dDevice->SetTransform( D3DTS_WORLD, &matWorld );
//set texture
pd3dDevice->SetTexture( 0, m_pTexture[0] );
//draw primitive
pd2dDevice->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2);
//set ALPHA blenderable
pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE);
//set AlPHA state
pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
//set ALPHA test
pd3dDevice->SetRenderState( D3DRS_ALPHATESTENABLE, TRUE);
//set ALPHA value
pd3dDevice->SetRenderState( D3DRS_ALPHAREF, 0x08 );
pd3dDevice->SetRenderState( D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);

//draw trees
pd3dDevice->SetTexture( 0, m_pTreeTexture );
for(int j=0; j<40; j++)
{

	D3DXMatrixRotationY( &matRotWorld, -D3DToRadian( theta ));
	D3DXMatrixTranslation( &matWorld, TreeLoc[j].x, 0.0f, TreeLoc[j].z);//change the location of the tree based on random value
	D3DXMatrixMultiply( &matWorld, &matRotWorld, &matWorld);
	pd3dDevice->SetTransForm( D3DTS_WORLD, &matWorld );//set world matrix
	pd3dDevice->DrawPrimitive( D3DPT_TRIANGLESTRIP, 8, 2);//draw
	D3DXMatrixIdentity( &matWorld );
	pd3dDevice->SetTransform( D3DTS_WORLD, &matWorld);
}