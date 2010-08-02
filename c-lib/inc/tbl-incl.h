/*
 * tbl-incl.h  - wraps all nec tbl stuff in one file
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
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/inc/tbl-incl.h,v 1.2 1997/05/07 15:18:34 wan Exp $
 * $Log: tbl-incl.h,v $
 * Revision 1.2  1997/05/07 15:18:34  wan
 * Added (limited) size constraints, bitstring and enumeration names to tables
 *
 * Revision 1.1  1995/07/27 08:55:57  rj
 * first check-in after being merged into .../c-lib/.
 *
 */

#define TTBL	3

#include "asn-incl.h"
#include "tbl.h"

typedef void AVal;

typedef AVal *AStructVal;  /* an array of AVal ptrs */

typedef struct AChoiceVal
{
    enum { achoiceval_notused } choiceId;
    AVal *val;
} AChoiceVal;


#include "tbl-util.h"
#include "tbl-enc.h"
#include "tbl-dec.h"
#include "tbl-print.h"
#include "tbl-free.h"

/*
 * TblError (char *str) - configure error handler
 */
#define TblError( str)		fprintf (stderr, "%s", str)
