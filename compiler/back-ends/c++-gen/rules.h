/*
 * compiler/back_ends/c++_gen/rules.h
 *
 * Copyright (C) 1991, 1992 Michael Sample
 *           and the University of British Columbia
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * $Header: /usr/app/odstb/CVS/snacc/compiler/back-ends/c++-gen/rules.h,v 1.3 1995/07/25 18:24:21 rj Exp $
 * $Log: rules.h,v $
 * Revision 1.3  1995/07/25 18:24:21  rj
 * file name has been shortened for redundant part: c++-gen/c++-rules -> c++-gen/rules.
 *
 * Revision 1.2  1994/10/08  03:47:50  rj
 * since i was still irritated by cpp standing for c++ and not the C preprocessor, i renamed them to cxx (which is one known suffix for C++ source files). since the standard #define is __cplusplus, cplusplus would have been the more obvious choice, but it is a little too long.
 *
 * Revision 1.1  1994/08/28  09:47:55  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */

/* see asn1module.h for CxxTDI (C++ type def info) */

typedef struct CxxRules
{
    int  maxDigitsToAppend;
    char *choiceIdFieldName;   /* name of choiceId field */
    char *choiceIdEnumName;  /* name (tag) for choiceId enum def name */
    char *choiceUnionFieldName; /* what the name of the choice's union is */
    char *choiceUnionName;  /* name (tag) for choice union def name */
    int   capitalizeNamedElmts;
    char *encodeBaseName;
    char *decodeBaseName;
    char *encodeContentBaseName;
    char *decodeContentBaseName;
    char *encodePduBaseName;
    char *decodePduBaseName;
    CxxTDI typeConvTbl[BASICTYPE_MACRODEF + 1];
}  CxxRules;

extern CxxRules cxxRulesG;
