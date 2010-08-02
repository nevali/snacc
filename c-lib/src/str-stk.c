/*
 * str_stk.c  - maintains a stack of the components of a bit string
 *        or octet string so they can be copied into a single chunk
 *
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
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/src/str-stk.c,v 1.2 1995/07/24 21:04:57 rj Exp $
 * $Log: str-stk.c,v $
 * Revision 1.2  1995/07/24 21:04:57  rj
 * changed `_' to `-' in file names.
 *
 * Revision 1.1  1994/08/28  09:46:09  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */

#include "asn-config.h"
#include "str-stk.h"

/* global for use by AsnBits and AsnOcts */

StrStk strStkG = { NULL, 128, 0, 64, 0, 0 };
