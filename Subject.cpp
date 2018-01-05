#include "Subject.hpp"

Subject::Subject ()
	: m_iNumObservers ( 0 )	
{
	clearObservers ();
}

Subject::~Subject ()
{
	clearObservers ();
}

void Subject::addObserver ( Observer * pObserver )
{
	if ( m_iNumObservers >= ciMAX_OBSERVERS )
	{
		return;
	}

	m_pObservers [ m_iNumObservers ] = pObserver;
	m_iNumObservers++;
}

void Subject::removeObserver ( Observer * pObserver )
{
	//Remove specified observer and rearrange array in the case that a gap is created
	bool bRearrange = false;
	for ( int i = 0; i < m_iNumObservers; i++ )
	{
		if ( bRearrange )
		{
			m_pObservers [ i - 1 ] = m_pObservers [ i ];
			m_pObservers [ i ] = nullptr;
		}
		else if ( m_pObservers [ i ] == pObserver )
		{
			bRearrange = true;
			m_pObservers [ i ] = nullptr;
		}
	}
	m_iNumObservers--;
}

void Subject::notify ( GameObject* pGameObject , const eEvent e )
{
	//Notify subjects of event
	for ( int i = 0; i < m_iNumObservers; i++ )
	{
		m_pObservers [ i ]->onNotify ( pGameObject , e );
	}
}

void Subject::clearObservers ()
{
	for ( int i = 0; i < m_iNumObservers; i++ )
	{
		m_pObservers [ i ] = nullptr;
	}
}
