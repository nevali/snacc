/*
 * print.h
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
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/inc/print.h,v 1.2 1995/07/24 21:01:23 rj Exp $
 * $Log: print.h,v $
 * Revision 1.2  1995/07/24 21:01:23  rj
 * changed `_' to `-' in file names.
 *
 * Revision 1.1  1994/08/28  09:45:38  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */

#ifndef _snaccc_print_h_
#define _snaccc_print_h_

extern unsigned short int stdIndentG;

void Indent PROTO ((FILE *f, unsigned short int i));


#endif /* conditional include */
