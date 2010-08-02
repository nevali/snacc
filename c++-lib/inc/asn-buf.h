// file: .../c++-lib/inc/asn-buf.h - buffer class
//
// MS 92
// Copyright (C) 1992 Michael Sample and the University of British Columbia
//
// This library is free software; you can redistribute it and/or
// modify it provided that this copyright/license information is retained
// in original form.
//
// If you modify this file, you must clearly indicate your changes.
//
// This source code is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/asn-buf.h,v 1.5 1997/02/16 20:25:35 rj Exp $
// $Log: asn-buf.h,v $
// Revision 1.5  1997/02/16 20:25:35  rj
// check-in of a few cosmetic changes
//
// Revision 1.4  1995/07/25  20:18:58  rj
// changed `_' to `-' in file names.
//
// Revision 1.3  1994/10/08  04:15:38  rj
// fixed both Copy()'s name and implementation to CopyOut() that always returns the number of bytes copied out instead of 0 in case less than the requested amount is available.
//
// several `unsigned long int' turned into `size_t'.
//
// Revision 1.2  1994/08/28  10:00:46  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:28  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _asn_buf_h_
#define _asn_buf_h_

class AsnBuf
{
protected:
    char *dataStart;
    char *dataEnd;
    char *blkStart;
    char *blkEnd;
    char *readLoc;
    bool writeError;
    bool readError;

public:
    // install data for reading or blank blk for writing in buffer
    // must be followed by 'mode' setting method call
    void Init (char *data, size_t dataLen)
    {
	readError = writeError = 1;
	blkStart = data;
	blkEnd = data + dataLen;
	dataStart = dataEnd = readLoc = blkEnd;
    }

    void ResetInReadMode()
    {
	readLoc = dataStart;
	readError = false;
	writeError = true;
    }

    void ResetInWriteRvsMode()
    {
	dataStart = dataEnd = blkEnd;
	writeError = false;
	readError = true;
    }

    void InstallData (char *data, size_t dataLen)
    {
	Init (data, dataLen);
	dataStart = blkStart;
	ResetInReadMode();
    }

    size_t			DataLen()		{ return dataEnd - dataStart; }
    char			*DataPtr()		{ return dataStart; }
    size_t			BlkLen()		{ return blkEnd - blkStart; }
    char			*BlkPtr()		{ return blkStart; }
    bool			Eod()			{ return readLoc >= dataEnd; }
    bool			ReadError()		{ return readError; }
    bool			WriteError()		{ return writeError; }

    void Skip (size_t skipLen)
    {
	if ((readLoc + skipLen) > dataEnd)
	{
	    readLoc = dataEnd;
	    readError = true;
	}
	else
	    readLoc += skipLen;
    }

    size_t CopyOut (char *dst, size_t copyLen)
    {
	if (readLoc + copyLen > dataEnd)
	{
	    copyLen = dataEnd - readLoc;
	    readError = 1;
	}
	memcpy (dst, readLoc, copyLen);
	readLoc += copyLen;
	return copyLen;
    }

    unsigned char PeekByte()
    {
	if (Eod())
	{
	    readError = true;
	    return 0;
	}
	else
	    return *readLoc;
    }

    char *GetSeg (size_t *lenPtr)
    {
	char *retVal = readLoc;
	if ((readLoc + *lenPtr) > dataEnd)
	{
	    *lenPtr = dataEnd - readLoc;
	    readLoc = dataEnd;
	    return retVal;
	}
	else
	{
	    readLoc += *lenPtr;
	    return retVal;
	}
    }

    void PutSegRvs (char *seg, size_t segLen)
    {
	if ((dataStart - segLen) < blkStart)
	    writeError = true;
	else
	{
	    dataStart -= segLen;
	    memcpy (dataStart, seg, segLen);
	}
    }

    unsigned char GetByte()
    {
	if (Eod())
	{
	    readError = true;
	    return 0;
	}
	else
	    return *(readLoc++);
    }

    void PutByteRvs (unsigned char byte)
    {
	if (dataStart <= blkStart)
	    writeError = true;
	else
	    *(--dataStart) = byte;
    }
};

#endif /* conditional include */
