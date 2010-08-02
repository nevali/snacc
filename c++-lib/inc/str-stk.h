// file: .../c++-lib/inc/str-stk.h - maintains a stack of the components of a bit string or octet string so they can be copied into a single chunk
//
// MS 92/07/06
//
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/str-stk.h,v 1.5 1997/02/16 20:25:56 rj Exp $
// $Log: str-stk.h,v $
// Revision 1.5  1997/02/16 20:25:56  rj
// check-in of a few cosmetic changes
//
// Revision 1.4  1995/07/25  21:09:14  rj
// changed `_' to `-' in file names.
//
// Revision 1.3  1994/10/08  04:15:30  rj
// fixed both Copy()'s name and implementation to CopyOut() that always returns the number of bytes copied out instead of 0 in case less than the requested amount is available.
//
// several `unsigned long int' turned into `size_t'.
//
// Revision 1.2  1994/08/28  10:01:01  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:49  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _str_stk_h_
#define _str_stk_h_

#ifndef _IBM_ENC_
class StrStk
#else
#include "shmmgr.h"   // Guido Grassel 4.8.93

class StrStk: public MemMgr     // Guido Grassel 12.8.93
#endif /* _IBM_ENC_ */
{
public:
  struct Elmt
  {
    char			*str;
    size_t			len;
  }				*stk;
  size_t			size;
  size_t			growSize;
  size_t			nextFreeElmt;
  size_t			totalByteLen;

				StrStk (int stkSize, int growIncrement);

  void				Reset();

  void				Push (char *str, size_t strLen);

  // copy string pieces (buffer refs) into single block.
  // assumes that the buf is at least totalByteLen byte long.
  void				CopyOut (char *buf);

};

#endif /* conditional include */
