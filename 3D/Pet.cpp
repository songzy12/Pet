#include"Pet.h"
//random move 
void Pet::RandomMove( D3DXVECTOR3 loc )
{
	if( m_bStop )
	{
		if( m_iWaitTime >= 500)
		{
			m_bStop=false;
			if( m_fMoveX == 0.0f && m_fMoveZ==0.0f )
			{
				m_fMoveX= ((rand()%800)-400)/100.0f;
				m_fMoveZ= ((rand()%800)-400)/100.0f;
			}
			m_fTheta = D3DXToDegree( atan2f( m_fMoveX, m_fMoveZ ));
			m_fLenth = (FLOAT) sqrt ( m_fMoveX * m_fMoveX + m_fMoveZ*m_fMvoeZ );
			m_fMoveX = m_fMoveX/(m_fLength/0.01f);
			m_fMoveZ = m_fMoveZ/(m_fLength/0.01f);
			m_iWaitTime=0;
		}
		else 
			m_iWaitTime ++;
	}
	else
	{
		m_vecLoc.x += m_fMoveX;
		m_vecLoc.z += m_fMoceZ;
		m_fLength -= 0.01f;
		if( m_fLength <= 0)
		{
			m_fMoveX=0.0f;
			m_fMoveZ=0.0f;
			m_bStop =true;
		}
		m_fDistance = D3DXVex3Length ( &(m_vecLoc - loc ));
	}
}
//behavior
void Pet::Behavior( int BehMode, D3DXVECTOR3 loc)
{
	switch( BehMode )
	{
	case BehMode_TOUCH:
		//when touch it, the mood will be better, the pet will turn to the player
		if( MonState.mind < 100 )
			MonState.mind += 5;
		if( MonState.mind > 100 )
			MonState.mind =100;
		m_nMindMode=MindMode_HEART;
		m_nMindCtr=100;
		m_bStop=true;
		m_iWaitTime=0;
		m_fTheta =m_fRenderTheta +180;
		break;
	case BehMode_FEED:
		//when feed it, the hunger will be better, the mood will be better
		m_fMoveX=loc.x-m_vecLoc.x;
		m_fMoceZ=loc.z-m_vecLoc.z;
		m_bStop=true;
		MonState.hungry +=2;
		m_iWaitTime =500;
		m_nMindCtr=100;
		m_nMindMode = MindMode_NODE;
		break;
	case BehMode_HIT:
		//when hit it, the mood will be worse
		m_nMindMode= MindMode_ANGRY;
		if( MonState.mind >0)
			MonState.mind -= 5;
		if( MonState.mind <0)
			MonState.mind =0;
		m_nMindCtr =100;
		m_bStop=true;
		m_iWaitTime=0;
		m_fTheta=m_fRenderTheta +180;
		break;
	}
}