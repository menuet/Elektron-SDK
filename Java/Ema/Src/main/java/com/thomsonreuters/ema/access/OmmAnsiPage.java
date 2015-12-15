///*|-----------------------------------------------------------------------------
// *|            This source code is provided under the Apache 2.0 license      --
// *|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
// *|                See the project's LICENSE.md for details.                  --
// *|           Copyright Thomson Reuters 2015. All rights reserved.            --
///*|-----------------------------------------------------------------------------

package com.thomsonreuters.ema.access;

import java.nio.ByteBuffer;

/**
 * OmmAnsiPage represents AnsiPage data format in Omm.
 */
public interface OmmAnsiPage extends ComplexType
{
	/**
	 * Returns AnsiPage string.
	 * 
	 * @return String containing the AnsiPage data
	 */
	public String string();

	/**
	 * Returns AnsiPage buffer.
	 * 
	 * @return ByteBuffer containing the AnsiPage data
	 */
	public ByteBuffer buffer();

	/**
	 * Clears the OmmAnsiPage.
	 * <br>Invoking clear() method clears all the values and resets all the defaults.
	 */
	public OmmAnsiPage clear();

	/**
	 * Specifies Set.
	 * @param value specifies AnsiPage data using String
	 * 
	 * @return reference to this object
	 */
	public OmmAnsiPage string(String value);

	/**
	 * Specifies Set.
	 * 
	 * @param value specifies AnsiPage data using ByteBuffer
	 * 
	 * @return reference to this object
	 */
	public OmmAnsiPage buffer(ByteBuffer value);
}