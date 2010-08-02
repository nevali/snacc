/*
 * tbl-enc.h - type table encoder
 *
 *
 * Mike Sample
 *
 * Copyright (C) 1993 Michael Sample
 *            and the University of British Columbia
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
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/inc/tbl-enc.h,v 1.1 1995/07/27 08:55:54 rj Exp $
 * $Log: tbl-enc.h,v $
 * Revision 1.1  1995/07/27 08:55:54  rj
 * first check-in after being merged into .../c-lib/.
 *
 */


int TblEncode PROTO ((TBL *tbl, char *modName, char *typeName, BUF_TYPE b, AVal *v, unsigned long int *bytesEncoded));

int TblEncodeType PROTO ((TBLType *tblT, BUF_TYPE b, AVal *v, int implicit, unsigned long int *bytesEncoded));
