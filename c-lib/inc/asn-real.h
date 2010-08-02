/*
 * asn_real.h
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
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/inc/asn-real.h,v 1.2 1995/07/24 21:01:18 rj Exp $
 * $Log: asn-real.h,v $
 * Revision 1.2  1995/07/24 21:01:18  rj
 * changed `_' to `-' in file names.
 *
 * Revision 1.1  1994/08/28  09:21:35  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */


#ifndef _asn_real_h_
#define _asn_real_h_

typedef double AsnReal;

extern AsnReal PLUS_INFINITY;
extern AsnReal MINUS_INFINITY;


void InitAsnInfinity PROTO((void));

AsnLen BEncAsnReal PROTO ((BUF_TYPE b, AsnReal *data));

void BDecAsnReal PROTO ((BUF_TYPE b, AsnReal *result, AsnLen *bytesDecoded, ENV_TYPE env));

AsnLen BEncAsnRealContent PROTO ((BUF_TYPE b, AsnReal *data));

void BDecAsnRealContent PROTO ((BUF_TYPE b, AsnTag tag, AsnLen len, AsnReal *result, AsnLen *bytesDecoded, ENV_TYPE env));

/* do nothing */
#define FreeAsnReal( v)

void PrintAsnReal PROTO ((FILE *f, AsnReal *b, unsigned short int indent));

#endif
