/*
 * hash.h
 *
 * Based on hashing stuff from UBC Raven Code (Terry Coatta & Don Acton)
 *
 * MS 92
 * Copyright (C) 1992 the University of British Columbia
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
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/inc/hash.h,v 1.3 1997/02/28 13:39:49 wan Exp $
 * $Log: hash.h,v $
 * Revision 1.3  1997/02/28 13:39:49  wan
 * Modifications collected for new version 1.3: Bug fixes, tk4.2.
 *
 * Revision 1.2  1995/07/24 21:01:19  rj
 * changed `_' to `-' in file names.
 *
 * Revision 1.1  1994/08/28  09:21:41  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */

#ifndef _asn_hash_h_
#define _asn_hash_h_

#define TABLESIZE 256
#define INDEXMASK 0xFF
#define INDEXSHIFT 8

typedef void *Table[TABLESIZE];

typedef unsigned int Hash;

typedef struct HashSlot
{
  int    leaf;
  Hash   hash;
  void  *value;
  Table *table;
} HashSlot;

Hash MakeHash PROTO ((char *str, unsigned long int len));

Table *InitHash PROTO((void));

int Insert PROTO ((Table *table, void *element, Hash hash));

int CheckFor PROTO ((Table *table, Hash hash));

int CheckForAndReturnValue PROTO ((Table *table, Hash hash, void **value));


#endif /* conditional include */
