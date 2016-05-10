/*|-----------------------------------------------------------------------------
 *|            This source code is provided under the Apache 2.0 license      --
 *|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
 *|                See the project's LICENSE.md for details.                  --
 *|           Copyright Thomson Reuters 2015. All rights reserved.            --
 *|-----------------------------------------------------------------------------
 */

#ifndef __thomsonreuters_ema_access_OmmClient_h
#define __thomsonreuters_ema_access_OmmClient_h

#include "OmmConsumerClient.h"
#include "OmmConsumerEvent.h"
#include "OmmNiProviderClient.h"
#include "OmmProviderEvent.h"

namespace thomsonreuters {

namespace ema {

namespace access {

class ClientFunctions
{
public :

	virtual void onAckMsg( const AckMsg&, Item* ) {}
	virtual void onAllMsg( const Msg&, Item* ) {}
	virtual void onGenericMsg( const GenericMsg&, Item* ) {}
	virtual void onRefreshMsg( const RefreshMsg&, Item* ) {}
	virtual void onStatusMsg( const StatusMsg&, Item* ) {}
	virtual void onUpdateMsg( const UpdateMsg&, Item* ) {}

	virtual ~ClientFunctions() {}

protected :

	ClientFunctions() {}

private :

	ClientFunctions( const ClientFunctions& );
	ClientFunctions& operator=( const ClientFunctions& );
};

template< class C >
class OmmClient : public ClientFunctions
{
public:

	void onAckMsg( const AckMsg&, Item* ) {}
	void onAllMsg( const Msg&, Item* ) {}
	void onGenericMsg( const GenericMsg&, Item* ) {}
	void onRefreshMsg( const RefreshMsg&, Item* ) {}
	void onStatusMsg( const StatusMsg&, Item* ) {}
	void onUpdateMsg( const UpdateMsg&, Item* ) {}

	OmmClient( C* c ) : _theClient( c ) {}

	virtual ~OmmClient() {}

private:

	OmmClient();
	OmmClient( const OmmClient& );
	OmmClient& operator=( const OmmClient& );

	C*	_theClient;
};

template<>
class OmmClient< OmmConsumerClient > : public ClientFunctions
{
public:

	void onAckMsg( const AckMsg&, Item* );
	void onAllMsg( const Msg&, Item* );
	void onGenericMsg( const GenericMsg&, Item* );
	void onRefreshMsg( const RefreshMsg&, Item* );
	void onStatusMsg( const StatusMsg&, Item* );
	void onUpdateMsg( const UpdateMsg&, Item* );

	OmmClient( OmmConsumerClient* c ) : _theClient( c ) {}

private:

	OmmClient();
	OmmClient( const OmmClient& );
	OmmClient& operator=( const OmmClient& );

	OmmConsumerClient* _theClient;
};

template<>
class OmmClient< OmmNiProviderClient > : public ClientFunctions
{
public:

	void onAllMsg( const Msg&, Item* );
	void onGenericMsg( const GenericMsg&, Item* );
	void onRefreshMsg( const RefreshMsg&, Item* );
	void onStatusMsg( const StatusMsg&, Item* );

	OmmClient( OmmNiProviderClient* c ) : _theClient( c ) {}

private:

	OmmClient();
	OmmClient( const OmmClient& );
	OmmClient& operator=( const OmmClient& );

	OmmNiProviderClient* _theClient;
};

}

}

}

#endif // __thomsonreuters_ema_access_OmmClient_h
