/*|-----------------------------------------------------------------------------
 *|            This source code is provided under the Apache 2.0 license      --
 *|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
 *|                See the project's LICENSE.md for details.                  --
 *|           Copyright Thomson Reuters 2015. All rights reserved.            --
 *|-----------------------------------------------------------------------------
 */

#ifndef __thomsonreuters_ema_access_InstanceMap_h
#define __thomsonreuters_ema_access_InstanceMap_h

#include "Mutex.h"

namespace thomsonreuters {

namespace ema {

namespace access {

template< class T >
class InstanceMap
{
public :

	static UInt64 add( T* );
	static void remove( T* );

#ifdef WIN32
	static BOOL WINAPI TermHandlerRoutine( DWORD dwCtrlType );
#else
	static void sigAction( int sig, siginfo_t* pSiginfo, void* pv );
#endif

private :

	static void init();
	static void atExit();

	static Mutex					_listLock;
	static EmaVector< T* >	_clientList;
	static UInt64					_id;
	static bool						_clearSigHandler;

#ifndef WIN32
	static struct sigaction _sigAction;
	static struct sigaction _oldSigAction;
#endif
};

template< class T > EmaVector< T* > InstanceMap< T >::_clientList;
template< class T > Mutex InstanceMap< T >::_listLock;
template< class T > UInt64 InstanceMap< T >::_id = 0;
template< class T > bool InstanceMap< T >::_clearSigHandler = true;

#ifndef WIN32
template< class T > struct sigaction InstanceMap< T >::_sigAction;
template< class T > struct sigaction InstanceMap< T >::_oldSigAction;
#endif

template< class T >
void InstanceMap< T >::init()
{
#ifdef WIN32
	SetConsoleCtrlHandler( &InstanceMap::TermHandlerRoutine, TRUE ) ;
#else
	bzero( &_sigAction, sizeof( _sigAction ) );
	bzero( &_oldSigAction, sizeof( _oldSigAction ) );

	_sigAction.sa_sigaction = sigAction;
	_sigAction.sa_flags = SA_SIGINFO;

	sigaction( SIGINT, &_sigAction, &_oldSigAction );
#endif

	_clearSigHandler = false;
}

template< class T >
UInt64 InstanceMap< T >::add( T* impl )
{
	_listLock.lock();
	if ( _clientList.empty() )
		InstanceMap< T> ::init();

	_clientList.push_back( impl );
	++_id;

	_listLock.unlock();

	return _id;
}

template< class T >
void InstanceMap< T >::remove( T* impl )
{
	_listLock.lock();

	_clientList.removeValue( impl );

	if ( !_clientList.empty() || _clearSigHandler )
	{
		_listLock.unlock();
		return;
	}

#ifdef WIN32
	SetConsoleCtrlHandler( &InstanceMap::TermHandlerRoutine, FALSE );
#else
	sigaction( SIGINT, &_oldSigAction, NULL );
#endif

	_clearSigHandler = true;

	_listLock.unlock();
}

template< class T >
void InstanceMap< T >::atExit()
{
	_listLock.lock();
	UInt32 size = _clientList.size();
	while ( size )
	{
		_clientList[size - 1 ]->setAtExit();
		_clientList[size - 1 ]->uninitialize();
		size = _clientList.size();
	}
	_listLock.unlock();
}

#ifdef WIN32
template< class T >
BOOL WINAPI InstanceMap< T >::TermHandlerRoutine( DWORD dwCtrlType )
{
	switch ( dwCtrlType )
	{
	case CTRL_CLOSE_EVENT:
	case CTRL_BREAK_EVENT:
	case CTRL_SHUTDOWN_EVENT:
	case CTRL_C_EVENT:
		InstanceMap< T >::atExit();
		break;
	}
	return FALSE;
}
#else
template< class T >
void InstanceMap< T >::sigAction( int, siginfo_t*, void* )
{
	InstanceMap< T >::atExit();
}
#endif

}

}

}

#endif // __thomsonreuters_ema_access_InstanceMap_h
