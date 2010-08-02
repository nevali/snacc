/*
 * nibble_alloc.h - handles buffer allocation
 * MS 91
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
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/inc/nibble-alloc.h,v 1.2 1995/07/24 21:01:22 rj Exp $
 * $Log: nibble-alloc.h,v $
 * Revision 1.2  1995/07/24 21:01:22  rj
 * changed `_' to `-' in file names.
 *
 * Revision 1.1  1994/08/28  09:21:43  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */

#ifndef _nibble_alloc_h_
#define _nibble_alloc_h_

typedef struct NibbleBuf
{
    char *start;
    char *end;
    char *curr;
    struct NibbleBuf *next;
} NibbleBuf;


typedef struct NibbleMem
{
    NibbleBuf *firstNibbleBuf;
    NibbleBuf *currNibbleBuf;
    unsigned long int incrementSize;
} NibbleMem;



void InitNibbleMem PROTO ((unsigned long int initialSize, unsigned long int incrementSize));

void ShutdownNibbleMem PROTO ((void));

void ServiceNibbleFault PROTO ((unsigned long int size));

void *NibbleAlloc PROTO ((unsigned long int size));

void ResetNibbleMem PROTO ((void));


#endif /* conditional include */
