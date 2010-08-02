// file: .../c++-lib/inc/print.h
//
// MS 92
//
// Copyright (C) 1992 Michael Sample and the University of British Columbia
//
// This library is free software; you can redistribute it and/or
// modify it provided that this copyright/license information is retained
// in original form.
//
// If you modify this file, you must clearly indicate your changes.
//
// This source code is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/print.h,v 1.4 1997/02/16 20:25:54 rj Exp $
// $Log: print.h,v $
// Revision 1.4  1997/02/16 20:25:54  rj
// check-in of a few cosmetic changes
//
// Revision 1.3  1994/10/08  04:18:13  rj
// code for meta structures added (provides information about the generated code itself).
//
// code for Tcl interface added (makes use of the above mentioned meta code).
//
// virtual inline functions (the destructor, the Clone() function, BEnc(), BDec() and Print()) moved from inc/*.h to src/*.C because g++ turns every one of them into a static non-inline function in every file where the .h file gets included.
//
// made Print() const (and some other, mainly comparison functions).
//
// several `unsigned long int' turned into `size_t'.
//
// Revision 1.2  1994/08/28  10:01:00  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:47  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _snacccpp_print_h_
#define _snacccpp_print_h_

extern unsigned short int	indentG;
extern unsigned short int	stdIndentG;

void				Indent (ostream &os, unsigned short int i);

ostream				&operator << (ostream &os, const AsnType &a);

#endif /* conditional include */
