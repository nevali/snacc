/*
 * tbl-free.h - frees data structs returned by type table driven decoder.
 *
 *
 * Mike Sample
 *
 * Copyright (C) 1993 Michael Sample
 *            and the University of British Columbia
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
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/inc/tbl-free.h,v 1.1 1995/07/27 08:55:55 rj Exp $
 * $Log: tbl-free.h,v $
 * Revision 1.1  1995/07/27 08:55:55  rj
 * first check-in after being merged into .../c-lib/.
 *
 */


void TblFree PROTO ((TBL *tbl, char *modName, char *typeName, AVal *v));

void TblFreeType PROTO ((TBLType *tblT, AVal *v));
