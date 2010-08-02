// file: .../c++-lib/src/str-stk.C
//
// MS 92/07/06
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/src/str-stk.C,v 1.5 1997/02/16 20:26:11 rj Exp $
// $Log: str-stk.C,v $
// Revision 1.5  1997/02/16 20:26:11  rj
// check-in of a few cosmetic changes
//
// Revision 1.4  1995/07/24  20:34:57  rj
// changed `_' to `-' in file names.
//
// Revision 1.3  1994/10/08  04:15:22  rj
// fixed both Copy()'s name and implementation to CopyOut() that always returns the number of bytes copied out instead of 0 in case less than the requested amount is available.
//
// several `unsigned long int' turned into `size_t'.
//
// Revision 1.2  1994/08/28  10:01:24  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:21:13  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#include "asn-config.h"
#include "str-stk.h"

// global for use by AsnBits and AsnOcts

StrStk strStkG (128, 64);

StrStk::StrStk (int stkSize, int growIncrement)
{
  stk = new struct Elmt[stkSize];
  size = stkSize;
  growSize = growIncrement;
}

void StrStk::Reset()
{
  nextFreeElmt = 0;
  totalByteLen = 0;
}

void StrStk::Push (char *str, size_t strLen)
{
  if (nextFreeElmt >= size)
  {
    struct Elmt *tmpStk;
    // alloc bigger stack and copy old elmts to it
    tmpStk = new struct Elmt[size + growSize];
    for (int i = 0; i < size; i++)
      tmpStk[i] = stk[i];
    delete stk;
    stk = tmpStk;
    size += growSize;
  }
  totalByteLen += strLen;
  stk[nextFreeElmt].str = str;
  stk[nextFreeElmt++].len = strLen;
}

/*
 * copy string pieces (buffer refs) into single block.
 * assumes that the buf is at least totalByteLen byte long.
 */
void StrStk::CopyOut (char *buf)
{
  unsigned long int curr;
  char *bufCurr;

  bufCurr = buf;
  for (curr = 0; curr < nextFreeElmt; curr++)
  {
      memcpy (bufCurr, stk[curr].str, stk[curr].len);
      bufCurr += stk[curr].len;
  }
}
