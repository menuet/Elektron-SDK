///*|-----------------------------------------------------------------------------
// *|            This source code is provided under the Apache 2.0 license      --
// *|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
// *|                See the project's LICENSE.md for details.                  --
// *|           Copyright Thomson Reuters 2015. All rights reserved.            --
///*|-----------------------------------------------------------------------------

package com.thomsonreuters.ema.access.impl;

import java.nio.ByteBuffer;

import com.thomsonreuters.ema.access.OmmUtf8;
import com.thomsonreuters.ema.access.DataType.DataTypes;
import com.thomsonreuters.upa.codec.CodecFactory;
import com.thomsonreuters.upa.codec.CodecReturnCodes;


class OmmUtf8Impl extends DataImpl implements OmmUtf8
{
	OmmUtf8Impl()
	{
		_rsslBuffer = CodecFactory.createBuffer();
	}

	@Override
	public int dataType()
	{
		return DataTypes.UTF8;
	}

	@Override
	public String string()
	{
		//TODO
		return null;
	}
	
	@Override
	public ByteBuffer buffer()
	{
		// TODO Auto-generated method stub
				return null;
	}
	
	@Override
	public String toString()
	{
		if (DataCode.BLANK == code())
			return BLANK_STRING;
		else
			return _rsslBuffer.toString();
	}

	@Override
	void decode(com.thomsonreuters.upa.codec.Buffer rsslBuffer, com.thomsonreuters.upa.codec.DecodeIterator dIter)
	{
		if (_rsslBuffer.decode(dIter) == CodecReturnCodes.SUCCESS)
			_dataCode = DataCode.NO_CODE;
		else
			_dataCode = DataCode.BLANK;
	}
}