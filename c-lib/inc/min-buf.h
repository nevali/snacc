/*
 * .../c-lib/inc/min-buf.h - trivial buffer routines.
 *             only use these for
 *                encoding - if you know you 'buffer' is big enough
 *                            to hold the encoded value
 *
 *                decoding - if you know that the encoding is error
 *                           free.
 *
 *
 * The minimal buffer is simply a block of mem referenced
 * by a char **(ie BUF_TYPE char**).  These are very efficient
 * but should only be used when it is safe (see above) or you're
 * willing to risk reading past the end of the buffer or writing
 * 'past' the beginning (segmentation faults/bus errors etc).
 *
 * No checks for reading or writing past the buffer are done.
 * every operation is assumed to succeed.
 * MS 92
 *
 * Copyright (C) 1992 Michael Sample and the University of British Columbia
 *
 * This library is free software; you can redistribute it and/or
 * modify it provided that this copyright/license information is retained
 * in original form.
 *
 * If you modify this file, you must clearly indicate your changes.
 *
 * This source code is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/inc/min-buf.h,v 1.2 1995/07/24 21:01:21 rj Exp $
 * $Log: min-buf.h,v $
 * Revision 1.2  1995/07/24 21:01:21  rj
 * changed `_' to `-' in file names.
 *
 * Revision 1.1  1994/08/28  09:21:42  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */

#ifndef _min_buf_h_
#define _min_buf_h_

#define MinBufGetByte(b)\
    (unsigned char)(*((*(b))++))

#define MinBufGetSeg( b, lenPtr)\
    *(b);\
    (*b) += *lenPtr;

#define MinBufCopy( dst, b, len)\
    memcpy ((dst), *(b), (len));\
    (*(b)) += (len);

#define MinBufSkip( b, len) ((*(b)) += len)

#define MinBufPeekByte( b)  (**(b))


#define MinBufPutByteRvs( b,  byte)\
    (*(--(*(b))) = (byte))

#define MinBufPutSegRvs( b, data, len)\
    ((*(b)) = (*(b)) - (len));\
    memcpy (*(b), (data), (len));


#define MinBufReadError( b)	0  /* always false */
#define MinBufWriteError( b)	0  /* always false */

#endif /* conditional include */
