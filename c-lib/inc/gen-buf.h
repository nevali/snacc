/*
 * gen_buf.h  - flexible (runtime configurable) buffer mgmt stuff.
 *
 *  These are somewhat slower than the direct approach used in
 *  the compiled stuff.  Since tables are around 4x slower,
 *  the flexibility of the GenBufs can be justified.  This
 *  also allows one enc/dec library to support all buffer types.
 *
 * MS 93
 *
 * Copyright (C) 1993 Michael Sample
 *            and the University of British Columbia
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
 */

#if USE_GEN_BUF

#ifndef _gen_buf_h_
#define _gen_buf_h_

/*
 *  These are the standard buffer routines that the lib
 *  routines need. Note that the Peek routines have be
 *  added to the standard list - they are necessary
 *  to nicely support  the table oriented decoder.
 *  The "void *b" param's real type will be the buffer
 *  type that is used inside the GenBuf
 *  (ie SBuf * or ExpBuf ** have been defined).
 *
 *  Note that macros can not be used for these standard functions
 *  because the GenBuf keeps a pointer to these routines.
 *  Thus the exp_buf.[ch] and sbuf.[ch] files are somewhat
 *  differnt than those in snacc/c_lib and snacc/c_include
 *
 */

typedef unsigned char	(*BufGetByteFcn) PROTO ((void *b));
typedef unsigned char	*(*BufGetSegFcn) PROTO ((void *b, unsigned long int *lenPtr));
typedef long int	(*BufCopyFcn) PROTO ((char *dst, void *b, unsigned long int len));
typedef void		(*BufSkipFcn) PROTO ((void *b, unsigned long int len));
typedef unsigned char	(*BufPeekByteFcn) PROTO ((void *b));
typedef unsigned char	*(*BufPeekSegFcn) PROTO ((void *b, unsigned long int lenPtr));
typedef long int	(*BufPeekCopyFcn) PROTO ((char *dst, void *b, unsigned long int len));
typedef void		(*BufPutByteRvsFcn) PROTO ((void *b, unsigned char byte));
typedef void		(*BufPutSegRvsFcn) PROTO ((void *b, char *data, unsigned long int len));
typedef int		(*BufReadErrorFcn) PROTO ((void *b));
typedef int		(*BufWriteErrorFcn) PROTO ((void *b));


typedef struct GenBuf
{
  BufGetByteFcn		getByte;
  BufGetSegFcn		getSeg;
  BufCopyFcn		copy;
  BufSkipFcn		skip;
  BufPeekByteFcn	peekByte;
  BufPeekSegFcn		peekSeg;
  BufPeekCopyFcn	peekCopy;
  BufPutByteRvsFcn	putByteRvs;
  BufPutSegRvsFcn	putSegRvs;
  BufReadErrorFcn	readError;
  BufWriteErrorFcn	writeError;
  void			*bufInfo;
  void			*spare; /* hack to save space for ExpBuf ** type */
} GenBuf;


#define GenBufGetByte( b)		((b)->getByte (b->bufInfo))
#define GenBufGetSeg( b, lenPtr)	((b)->getSeg (b->bufInfo, lenPtr))
#define GenBufCopy( dst, b, len)	((b)->copy (dst, b->bufInfo, len))
#define GenBufSkip( b, len)		((b)->skip (b->bufInfo,len))
#define GenBufPeekByte( b)		((b)->peekByte (b->bufInfo))
#define GenBufPeekSeg( b, lenPtr)	((b)->peekSeg (b->bufInfo, lenPtr))
#define GenBufPeekCopy( dst, b, len)	((b)->peekCopy (dst, b->bufInfo, len))
#define GenBufPutByteRvs( b, byte)	((b)->putByteRvs (b->bufInfo, byte))
#define GenBufPutSegRvs( b, data, len)	((b)->putSegRvs (b->bufInfo, data, len))
#define GenBufReadError( b)		((b)->readError (b->bufInfo))
#define GenBufWriteError( b)		((b)->writeError (b->bufInfo))


#endif /* _gen_buf_h_ conditional include  */

#endif /* USE_GEN_BUF */
