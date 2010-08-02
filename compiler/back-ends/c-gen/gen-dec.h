/*
 * compiler/back-ends/c-gen/gen-dec.h - routines for printing C decoders from type trees
 *
 * Mike Sample
 * 91/09/26
 * Copyright (C) 1991, 1992 Michael Sample
 *            and the University of British Columbia
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * $Header: /usr/app/odstb/CVS/snacc/compiler/back-ends/c-gen/gen-dec.h,v 1.3 1995/07/25 18:41:03 rj Exp $
 * $Log: gen-dec.h,v $
 * Revision 1.3  1995/07/25 18:41:03  rj
 * file name has been shortened for redundant part: c-gen/gen-c-dec -> c-gen/gen-dec.
 *
 * changed `_' to `-' in file names.
 *
 * Revision 1.2  1994/10/08  03:48:10  rj
 * since i was still irritated by cpp standing for c++ and not the C preprocessor, i renamed them to cxx (which is one known suffix for C++ source files). since the standard #define is __cplusplus, cplusplus would have been the more obvious choice, but it is a little too long.
 *
 * Revision 1.1  1994/08/28  09:48:22  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */


void PrintCBerDecoder PROTO ((FILE *src, FILE *hdr, CRules *r, Module *m, TypeDef *td, long int *longJmpVal));


void PrintCBerContentDecoder PROTO ((FILE *src, FILE *hdr, CRules *r, Module *m, TypeDef *td, long int *longJmpVal));
