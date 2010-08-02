/*
 * asn_bool.h
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
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/inc/asn-bool.h,v 1.2 1995/07/24 21:01:10 rj Exp $
 * $Log: asn-bool.h,v $
 * Revision 1.2  1995/07/24 21:01:10  rj
 * changed `_' to `-' in file names.
 *
 * Revision 1.1  1994/08/28  09:21:24  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */

#ifndef _asn_bool_h_
#define _asn_bool_h_

typedef unsigned char AsnBool;


AsnLen BEncAsnBool PROTO ((BUF_TYPE b, AsnBool *data));

void BDecAsnBool PROTO ((BUF_TYPE b, AsnBool *result, AsnLen *bytesDecoded, ENV_TYPE env));

AsnLen BEncAsnBoolContent PROTO ((BUF_TYPE b, AsnBool *data));

void BDecAsnBoolContent PROTO ((BUF_TYPE b, AsnTag tag, AsnLen len, AsnBool *result, AsnLen *bytesDecoded, ENV_TYPE env));

/* do nothing  */
#define FreeAsnBool( v)

void PrintAsnBool PROTO ((FILE *f, AsnBool *b, unsigned short int indent));

#endif
