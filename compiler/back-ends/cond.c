/*
 * compiler/back_ends/cond.c - generate conditional include for C(++) hdr files
 *
 * MS 92
 * Copyright (C) 1991, 1992 Michael Sample
 *            and the University of British Columbia
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * $Header: /usr/app/odstb/CVS/snacc/compiler/back-ends/cond.c,v 1.1 1995/07/25 19:13:49 rj Exp $
 * $Log: cond.c,v $
 * Revision 1.1  1995/07/25 19:13:49  rj
 * PrintConditionalIncludeOpen() and PrintConditionalIncludeClose() moved from back-ends/c-gen/gen-code.[ch].
 *
 */

#include "asn-incl.h"
#include "cond.h"


void
PrintConditionalIncludeOpen PARAMS ((f, fileName),
    FILE *f _AND_
    char *fileName)
{
    char hdrFileDefSym[256];
    int i;

    strcpy (hdrFileDefSym, fileName);
    for (i = 0; i < strlen (hdrFileDefSym); i++)
        if (hdrFileDefSym[i] == '-' || hdrFileDefSym[i] == '.')
            hdrFileDefSym[i] = '_';

    fprintf (f, "#ifndef _%s_\n", hdrFileDefSym);
    fprintf(f, "#define _%s_\n\n\n", hdrFileDefSym);
} /* PrintConditionalIncludeOpen */


void
PrintConditionalIncludeClose PARAMS ((f, fileName),
    FILE *f _AND_
    char *fileName)
{
    fprintf (f, "\n#endif /* conditional include of %s */\n", fileName);

} /* PrintConditionalIncludeClose */
