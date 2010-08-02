/*
 * tbl-util.h - type table utilities.
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
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/inc/tbl-util.h,v 1.1 1995/07/27 08:55:59 rj Exp $
 * $Log: tbl-util.h,v $
 * Revision 1.1  1995/07/27 08:55:59  rj
 * first check-in after being merged into .../c-lib/.
 *
 */

/*
 * these rely on the TBLTagClass enum starting at zero
 * and being in the order: UNIVERSAL, APPLICATION, CONTEXT, PRIVATE
 */
#define TblTagClassToBer(tblClass) (tblClass << 6)
#define BerTagClassToTbl(berClass) (berClass >> 6)
#define TagsEquiv(asnTag, tblTag) (((tblTag)->encTag == (asnTag)) ||\
         (((tblTag)->form == ANY_FORM) &&\
          ((tblTag)->encTag == DECONSIFY (asnTag))))


char *LoadFile PROTO ((char *tblFileName, unsigned long int *size));

TBL *LoadTblFile PROTO ((char *tblFileName));

TBLTypeDef *TblFindTypeDef PROTO ((TBL *tbl, char *moduleName, char *typeName, TBLModule **tblModHndl));

TBLTypeDef *TblFindTypeDefInMod PROTO ((TBLModule *tbl, char *typeName));

TBLTypeDef *TblFindTypeDefByIndex PROTO ((TBL *tbl,TBLTypeDefId id));

TBLModule *TblFindModule PROTO ((TBL *tbl, char *modName));
