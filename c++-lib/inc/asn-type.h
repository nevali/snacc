// file: .../c++-lib/inc/asn-type.h - Abstract class that all ASN.1 types are derived from
//               Design motivated by ANY type.
//
//               Runtime cost in speed and space for virtual fcns will
//               hopefully not be too bad
//
//               If your ASN.1 code does not use ANY or ANY DEFIND BY
//               types then you could  make the BEnc, BDec and Clone
//               non-virtual in the AsnType to improve performance.
//               (undef SUPPORT_ANY_TYPE)
//
//               NOTE: The virtual encode/decode/print etc fcns
//               could be purely virtual (= 0) creating an abstract class
//               but the ANY handling code needs to instantiate the AsnType
//               base class (via Cloning).   Also it allows for default
//               error reporting for ANY types that have not been
//               instantiated properly.
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
// MS 92
//
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/asn-type.h,v 1.6 1997/02/16 20:25:48 rj Exp $
// $Log: asn-type.h,v $
// Revision 1.6  1997/02/16 20:25:48  rj
// check-in of a few cosmetic changes
//
// Revision 1.5  1995/07/24  17:39:00  rj
// _getref() gets an additional optional argument to faciliate the different member access semantics of TclGetVal() and TclSetVal().
//
// _typename() made private, no need to be public.
//
// additional function TclUnsetVal() to delete OPTIONAL members and SEQUENCE OF and SET OF list elements.
//
// #if TCL ... #endif wrapped into #if META ... #endif
//
// getTclPDU() deleted.
//
// changed `_' to `-' in file names.
//
// Revision 1.4  1994/10/08  04:18:10  rj
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
// Revision 1.3  1994/09/13  14:18:52  rj
// inline functions moved from asn_type.h to asn_type.C.
// functions that are called upon error only don't need to be that fast.
//
// Revision 1.2  1994/08/28  10:00:57  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:44  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _asn_type_h_
#define _asn_type_h_

#ifdef _IBM_ENC_
#include "shmmgr.h"   // Guido Grassel 4.8.93
#endif /* _IBM_ENC_ */

#define SUPPORT_ANY_TYPE

#if TCL
#include <tcl.h>
#undef VOID
#endif

#if META
#include "meta.h"
#endif

#ifndef __IBM_ENC_
class AsnType
#else
class AsnType: public MemMgr   // Guido Grassel, 12.8.93
#endif /* __IBM_ENC_ */
{
public:
  virtual			~AsnType();

#ifdef SUPPORT_ANY_TYPE

  virtual AsnType		*Clone() const;

  virtual void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  virtual AsnLen		BEnc (BUF_TYPE b);

#else

  void				BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
									{}
  AsnLen			BEnc (BUF_TYPE b)			{ return 0; }

#endif

  virtual void			Print (ostream &) const;

#if META
  static const AsnTypeDesc	_desc;

  virtual const AsnTypeDesc	*_getdesc() const;
  virtual AsnType		*_getref (const char *membername, bool create=false);

private:
  const char			*_typename() const;

#if TCL
public:
  virtual int			TclGetDesc (Tcl_DString *) const;
  virtual int			TclGetVal (Tcl_Interp *) const;
  virtual int			TclSetVal (Tcl_Interp *, const char *val);
  virtual int			TclUnsetVal (Tcl_Interp *, const char *membernames);
#endif // TCL
#endif // META
};

#endif // conditional include
