/*
 * asn_enum.h
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
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/inc/asn-enum.h,v 1.2 1995/07/24 21:01:12 rj Exp $
 * $Log: asn-enum.h,v $
 * Revision 1.2  1995/07/24 21:01:12  rj
 * changed `_' to `-' in file names.
 *
 * Revision 1.1  1994/08/28  09:21:26  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */

#ifndef _asn_enum_h_
#define _asn_enum_h_

typedef AsnInt AsnEnum;

/*
 * ENUMERATED have a UNIVERSAL tag that is diff from INTEGERS
 * so need diff encoding routine tho content stuff is the same
 */
AsnLen BEncAsnEnum PROTO ((BUF_TYPE b, AsnEnum *data));

void BDecAsnEnum PROTO ((BUF_TYPE b, AsnEnum *result, AsnLen *bytesDecoded, ENV_TYPE env));

#define BEncAsnEnumContent BEncAsnIntContent

#define BDecAsnEnumContent BDecAsnIntContent

#define FreeAsnEnum FreeAsnInt

#define PrintAsnEnum PrintAsnInt


#endif /* conditional include */
