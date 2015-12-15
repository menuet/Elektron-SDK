///*|-----------------------------------------------------------------------------
// *|            This source code is provided under the Apache 2.0 license      --
// *|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
// *|                See the project's LICENSE.md for details.                  --
// *|           Copyright Thomson Reuters 2015. All rights reserved.            --
///*|-----------------------------------------------------------------------------

package com.thomsonreuters.ema.access;

import java.nio.ByteBuffer;

/**
 * OmmXml represents XML data format in Omm.
 * 
 * <p>Method {@link #string()} can have performance decrease, since it will trigger garbage collection.</p>
 * <p>Objects of this class are intended to be short lived or rather transitional.
 * <br>This class is designed to efficiently perform setting and extracting of XML and its content.
 * <br>Objects of this class are not cache-able.</p>
 * 
 */
public interface OmmXml extends ComplexType
{
	/**
	 * Returns contained XML buffer.
	 * 
	 * @return ByteBuffer containing the XML data
	*/
	public ByteBuffer buffer();

	/**
	 * Returns a string representation of the class instance.
	 * 
	 * @return string representation of the class instance
	 */
	public String string();

	/**
	 * Clears the OmmXml.
	 * Invoking clear() method clears all the values and resets all the defaults.
	 * 
	 * @return reference to this object
	 */
	public OmmXml clear();

	/** 
	 * Specifies Set.
	 * 
	 * @param value specifies XML data using String
	 * @return reference to this object
	 */
	public OmmXml string(String value);

	/**
	 * Specifies Set.
	 * 
	 * @param value specifies XML data using ByteBuffer
	 * @return reference to this object
	 */
	public OmmXml buffer(ByteBuffer value);
}