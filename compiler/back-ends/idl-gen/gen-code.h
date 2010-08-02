/*
 * compiler/back_ends/idl_gen/gen_code.h
 *
 * Copyright (C) 1991, 1992 Michael Sample
 *           and the University of British Columbia
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * $Header: /usr/app/odstb/CVS/snacc/compiler/back-ends/idl-gen/gen-code.h,v 1.1 1997/01/01 20:25:35 rj Exp $
 * $Log: gen-code.h,v $
 * Revision 1.1  1997/01/01 20:25:35  rj
 * first draft
 *
 */

void PrintIDLCode PROTO ((FILE *idl, ModuleList *mods, Module *m, IDLRules *r, long int longJmpVal, int printValues));
