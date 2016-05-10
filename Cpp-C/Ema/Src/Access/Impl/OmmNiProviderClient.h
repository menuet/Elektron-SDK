/*|-----------------------------------------------------------------------------
 *|            This source code is provided under the Apache 2.0 license      --
 *|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
 *|                See the project's LICENSE.md for details.                  --
 *|           Copyright Thomson Reuters 2015. All rights reserved.            --
 *|-----------------------------------------------------------------------------
 */

#ifndef __thomsonreuters_ema_access_ommNiProviderClient_h
#define __thomsonreuters_ema_access_ommNiProviderClient_h

#include "OmmProviderClient.h"

namespace thomsonreuters {

namespace ema {

namespace access {

class EMA_ACCESS_API OmmNiProviderClient : public OmmProviderClient
{
public :

	OmmNiProviderClient();
	virtual ~OmmNiProviderClient();

private :

	OmmNiProviderClient( const OmmNiProviderClient& );
	OmmNiProviderClient& operator=( const OmmNiProviderClient& );
};

}

}

}

#endif //__thomsonreuters_ema_access_ommNiProviderClient_h
