/*
 * compiler/back_ends/c++_gen/gen_any.h
 *
 * MS 92
 * Copyright (C) 1991, 1992 Michael Sample
 *           and the University of British Columbia
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * $Header: /usr/app/odstb/CVS/snacc/compiler/back-ends/c++-gen/gen-any.h,v 1.3 1995/07/25 18:19:12 rj Exp $
 * $Log: gen-any.h,v $
 * Revision 1.3  1995/07/25 18:19:12  rj
 * changed `_' to `-' in file names.
 *
 * Revision 1.2  1994/10/08  03:47:54  rj
 * since i was still irritated by cpp standing for c++ and not the C preprocessor, i renamed them to cxx (which is one known suffix for C++ source files). since the standard #define is __cplusplus, cplusplus would have been the more obvious choice, but it is a little too long.
 *
 * Revision 1.1  1994/08/28  09:47:59  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */

void PrintCxxAnyCode PROTO ((FILE *src, FILE *hdr, CxxRules *r, ModuleList *mods, Module *m));
