// file: .../c++-lib/inc/asn-any.h - C++ class for any type
//
// MS 92
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/asn-any.h,v 1.4 1997/01/02 08:39:42 rj Exp $
// $Log: asn-any.h,v $
// Revision 1.4  1997/01/02 08:39:42  rj
// missing prototype added
//
// Revision 1.3  1994/10/08  04:17:56  rj
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
// Revision 1.2  1994/08/28  10:00:43  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:24  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _asn_any_h_
#define _asn_any_h_

#ifdef _IBM_ENC_
#include "shmmgr.h"   // Guido Grassel 4.8.93
#endif /* _IBM_ENC_ */

#include "hash.h"

/* this is put into the hash table with the int or oid as the key */
#ifndef _IBM_ENC_
class AnyInfo
#else
class AnyInfo: public MemMgr   // Guido Grassel 4.8.93
#endif /* _IBM_ENC_ */
{
public:
  int				anyId;	// will be a value from the AnyId enum
  AsnOid			oid;	// will be zero len/null if intId is valid
  AsnInt			intId;
  AsnType			*typeToClone;
};

class AsnAny: public AsnType
{
public:
  static Table			*oidHashTbl;	// all AsnAny class instances
  static Table			*intHashTbl;	// share these tables
  AnyInfo			*ai;		// points to entry in hash tbl for this type
  AsnType			*value;

				AsnAny()				{ ai = NULL; value = NULL; }

  // class level methods
  static void			InstallAnyByInt (AsnInt intId, int anyId, AsnType *type);
  static void			InstallAnyByOid (AsnOid &oid,  int anyId, AsnType *type);

  int				GetId()	const				{ return ai ? ai->anyId : -1; }
  void				SetTypeByInt (AsnInt id);
  void				SetTypeByOid (AsnOid &id);

  AsnLen			BEnc (BUF_TYPE b);
  void				BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);

  PDU_MEMBER_MACROS

  void				Print (ostream &) const;

#if 0
#if TCL
  int				TclGetDesc (Tcl_DString *) const;
  int				TclGetVal (Tcl_DString *) const;
  int				TclSetVal (Tcl_Interp *, const char *val);
  int				TclUnSetVal (Tcl_Interp *, const char *member);
#endif /* TCL */
#endif
};

// AnyDefinedBy is currently the same as AsnAny:
typedef AsnAny			AsnAnyDefinedBy;

#endif /* conditional include */
