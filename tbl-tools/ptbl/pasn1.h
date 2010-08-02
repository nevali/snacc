/*
 * file: .../tbl-tools/ptbl/pasn1.h
 *
 * $Header: /usr/app/odstb/CVS/snacc/tbl-tools/ptbl/pasn1.h,v 1.1 1997/02/15 19:26:22 rj Exp $
 * $Log: pasn1.h,v $
 * Revision 1.1  1997/02/15 19:26:22  rj
 * first check-in
 *
 */


void PrintTblTypeDefInAsn1 PROTO ((FILE *f, TBL *tbl, TBLTypeDef *td));

void PrintTblTypeInAsn1 PROTO ((FILE *f, TBL *tbl, TBLTypeDef *td, TBLType *t));

void PrintTblInAsn1 PROTO ((FILE *f, TBL *tbl));
