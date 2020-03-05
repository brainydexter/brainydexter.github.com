#include "StdAfx.h"
#include "Observable.h"

#include "Observer.h"

Observable::Observable(void) : m_Changed(false)
{
}

Observable::~Observable(void)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Subscribes an observer to this source. </summary>
///
/// <remarks>	Priyank, 1/28/2010. </remarks>
///
/// <param name="a_Observer">	[in,out] If non-null, a observer. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Observable::AddObserver(Observer* a_Observer)
{
	m_pObserverlist.push_back( a_Observer );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Unsubscribes the observer described by a_Observer from this observable's list. </summary>
///
/// <remarks>	Priyank, 1/28/2010. </remarks>
///
/// <param name="a_Observer">	[in,out] If non-null, a observer. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Observable::RemoveObserver(Observer* a_Observer)
{
	m_pObserverlist.remove( a_Observer );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	State of the subject changed. </summary>
///
/// <remarks>	Priyank, 1/28/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Observable::StateSetChanged(void)
{
	m_Changed = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Notifies subscribed observers, iff any state change occured (i.e. StateSetChanged() was called) for the given subject. </summary>
///
/// <remarks>	Priyank, 1/28/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Observable::NotifyObservers(void)
{
	if( m_Changed ) {
		std::list< Observer* >::iterator l_pObserver_it;

		for( l_pObserver_it = m_pObserverlist.begin(); l_pObserver_it != m_pObserverlist.end(); l_pObserver_it++ ) {
			Observer* l_pObserver = *l_pObserver_it;
			l_pObserver->UpdateState();
		}

		m_Changed = false;
	}
}

