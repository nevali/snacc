/*
 * print.c - library routines for printing ASN.1 values.
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
 * $Header: /usr/app/odstb/CVS/snacc/c-lib/src/print.c,v 1.3 1997/03/13 09:15:19 wan Exp $
 * $Log: print.c,v $
 * Revision 1.3  1997/03/13 09:15:19  wan
 * Improved dependency generation for stupid makedepends.
 * Corrected PeekTag to peek into buffer only as far as necessary.
 * Added installable error handler.
 * Fixed small glitch in idl-code generator (Markku Savela <msa@msa.tte.vtt.fi>).
 *
 * Revision 1.2  1995/07/24 21:04:55  rj
 * changed `_' to `-' in file names.
 *
 * Revision 1.1  1994/08/28  09:46:08  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */

#include "asn-config.h"
#include "print.h"

unsigned short int stdIndentG = 4;


void
Indent PARAMS ((f, i),
    FILE *f _AND_
    unsigned short int i)
{
    for (; i > 0; i--)
        fputc (' ', f);  /* this may be slow */
}

void Asn1DefaultErrorHandler PARAMS ((str, severity),
    char* str _AND_
    int severity)
{
    fprintf(stderr,"%s",str);
}

static Asn1ErrorHandler asn1CurrentErrorHandler = Asn1DefaultErrorHandler;

void
Asn1Error PARAMS ((str),
    char* str)
{
    (*asn1CurrentErrorHandler)(str,1);
}

void
Asn1Warning PARAMS ((str),
    char* str)
{
    (*asn1CurrentErrorHandler)(str,0);
}

Asn1ErrorHandler
Asn1InstallErrorHandler PARAMS ((handler),
    Asn1ErrorHandler handler)
{
    Asn1ErrorHandler former = asn1CurrentErrorHandler;
    asn1CurrentErrorHandler = handler;
    return former;
}

