/*
 * asn_octs.h
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
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/inc/asn-octs.h,v 1.3 1995/07/24 21:01:17 rj Exp $
 * $Log: asn-octs.h,v $
 * Revision 1.3  1995/07/24 21:01:17  rj
 * changed `_' to `-' in file names.
 *
 * Revision 1.2  1994/12/11  21:49:38  rj
 * argument order of BDecAsnOctsContent() fixed.
 *
 * Revision 1.1  1994/08/28  09:21:32  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */


#ifndef _asn_octs_h_
#define _asn_octs_h_

typedef struct AsnOcts
{
  unsigned long int	octetLen;
  char			*octs;
} AsnOcts;

#define ASNOCTS_PRESENT( aocts)	((aocts)->octs != NULL)



AsnLen BEncAsnOcts PROTO ((BUF_TYPE b, AsnOcts *data));

void BDecAsnOcts PROTO ((BUF_TYPE b, AsnOcts *result, AsnLen *bytesDecoded, ENV_TYPE env));

AsnLen BEncAsnOctsContent PROTO ((BUF_TYPE b, AsnOcts *octs));

void BDecAsnOctsContent PROTO ((BUF_TYPE b, AsnTag tagId, AsnLen len, AsnOcts *result, AsnLen *bytesDecoded, ENV_TYPE env));

void FreeAsnOcts PROTO ((AsnOcts *o));

void PrintAsnOcts PROTO ((FILE *f, AsnOcts *o, unsigned short int indent));

int AsnOctsEquiv PROTO ((AsnOcts *o1, AsnOcts *o2));


#endif /* conditional include */
