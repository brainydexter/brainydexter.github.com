#include "StdAfx.h"
#include "Observer.h"

#include "Observable.h"

Observer::~Observer(void)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor.  Adds this observer to the subscriber-list of the subject Observable</summary>
///
/// <remarks>	Priyank, 1/28/2010. </remarks>
///
/// <param name="a_Observable">	[in,out] If non-null, a observable. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

Observer::Observer(Observable *a_pObservable)
: m_pObservable( a_pObservable )
{
	m_pObservable->AddObserver(this);
}

