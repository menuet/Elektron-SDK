/*|-----------------------------------------------------------------------------
 *|            This source code is provided under the Apache 2.0 license      --
 *|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
 *|                See the project's LICENSE.md for details.                  --
 *|           Copyright Thomson Reuters 2015. All rights reserved.            --
 *|-----------------------------------------------------------------------------
 */

#include "OmmClient.h"

using namespace thomsonreuters::ema::access;

void OmmClient<OmmConsumerClient>::onAckMsg( const AckMsg& msg, Item* item )
{
	OmmConsumerEvent event;
	event._pItem = item;
	_theClient->onAckMsg( msg, event );
}

void OmmClient<OmmConsumerClient>::onAllMsg( const Msg& msg, Item* item )
{
	OmmConsumerEvent event;
	event._pItem = item;
	_theClient->onAllMsg( msg, event );
}

void OmmClient<OmmConsumerClient>::onGenericMsg( const GenericMsg& msg, Item* item )
{
	OmmConsumerEvent event;
	event._pItem = item;
	_theClient->onGenericMsg( msg, event );
}

void OmmClient<OmmConsumerClient>::onRefreshMsg( const RefreshMsg& msg, Item* item )
{
	OmmConsumerEvent event;
	event._pItem = item;
	_theClient->onRefreshMsg( msg, event );
}

void OmmClient<OmmConsumerClient>::onStatusMsg( const StatusMsg& msg, Item* item )
{
	OmmConsumerEvent event;
	event._pItem = item;
	_theClient->onStatusMsg( msg, event );
}

void OmmClient<OmmConsumerClient>::onUpdateMsg( const UpdateMsg& msg, Item* item )
{
	OmmConsumerEvent event;
	event._pItem = item;
	_theClient->onUpdateMsg( msg, event );
}

void OmmClient<OmmNiProviderClient>::onAllMsg( const Msg& msg, Item* item )
{
	OmmProviderEvent event;
	event._pItem = item;
	_theClient->onAllMsg( msg, event );
}

void OmmClient<OmmNiProviderClient>::onGenericMsg( const GenericMsg& msg, Item* item )
{
	OmmProviderEvent event;
	event._pItem = item;
	_theClient->onGenericMsg( msg, event );
}

void OmmClient<OmmNiProviderClient>::onRefreshMsg( const RefreshMsg& msg, Item* item )
{
	OmmProviderEvent event;
	event._pItem = item;
	_theClient->onRefreshMsg( msg, event );
}

void OmmClient<OmmNiProviderClient>::onStatusMsg( const StatusMsg& msg, Item* item )
{
	OmmProviderEvent event;
	event._pItem = item;
	_theClient->onStatusMsg( msg, event );
}
