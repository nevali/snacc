/*
 * asn_null.h
 *
 * MS 92
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
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/inc/asn-null.h,v 1.2 1995/07/24 21:01:16 rj Exp $
 * $Log: asn-null.h,v $
 * Revision 1.2  1995/07/24 21:01:16  rj
 * changed `_' to `-' in file names.
 *
 * Revision 1.1  1994/08/28  09:21:31  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */

#ifndef _asn_null_h_
#define _asn_null_h_

typedef char AsnNull;


AsnLen BEncAsnNull PROTO ((BUF_TYPE b, AsnNull *data));

void BDecAsnNull PROTO ((BUF_TYPE b, AsnNull *result, AsnLen *bytesDecoded, ENV_TYPE env));


/* 'return' length of encoded NULL value, 0 */
#define BEncAsnNullContent(b, data) 0

void BDecAsnNullContent PROTO ((BUF_TYPE b, AsnTag tag, AsnLen len, AsnNull *result, AsnLen *bytesDecoded, ENV_TYPE env));

 /* do nothing */
#define FreeAsnNull( v)

void PrintAsnNull PROTO ((FILE *f, AsnNull * b, unsigned short int indent));

#endif /* conditional include */
