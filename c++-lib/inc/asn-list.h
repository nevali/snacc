// file: .../c++-lib/inc/asn-list.h
//
//   **** NOTE - this is not used or tested due to problems with gcc ****
//
//  Mike Sample
//  92/07/02
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/asn-list.h,v 1.6 1997/02/16 20:25:38 rj Exp $
// $Log: asn-list.h,v $
// Revision 1.6  1997/02/16 20:25:38  rj
// check-in of a few cosmetic changes
//
// Revision 1.5  1995/07/24  17:46:54  rj
// operator == and != return bool instead of int.
//
// #if TCL ... #endif wrapped into #if META ... #endif
//
// changed `_' to `-' in file names.
//
// Revision 1.4  1995/02/18  14:06:09  rj
// #pragma interface/implementation are GNU specific and need to be wrapped.
//
// Revision 1.3  1994/10/08  04:18:05  rj
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
// Revision 1.2  1994/08/28  10:00:51  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:37  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _asn_list_h_
#define _asn_list_h_

#ifdef __GNUG__
#pragma interface
#endif

#ifdef _IBM_ENC_
#include "shmmgr.h"   // Guido Grassel 5.8.93
#endif /* _IBM_ENC_ */

template <class T>
#ifndef _IBM_ENC_
class AsnList
#else
class AsnList: public MemMgr  // Guido Grassel 12.8.93
#endif /* _IBM_ENC_ */
{
protected:
  unsigned long int		count;
  struct AsnListElmt
  {
    T				elmt;
    AsnListElmt			*next, *prev;
  }				*first, *curr, *last;

#ifdef _IBM_ENC_
    AsnListElmt			*first, *curr, *last;
#endif /* _IBM_ENC_ */

public:
				AsnList():
				  count (0),
				  first (NULL),
				  curr (NULL),
				  last (NULL)
				{}

  friend ostream		&operator << (ostream &os, AsnList &l);

  void				SetCurrElmt (unsigned long int index);
  void				SetCurrToFirst()			{ curr = first; }
  void				SetCurrToLast()				{ curr = last; }

  // reading member fcns
  int				Count()					{ return count; }
  T				*First()				{ return count > 0 ? &first->elmt : NULL; }
  T				*Last()					{ return count > 0 ? &last->elmt : NULL; }
  T				*Curr()					{ return curr ? &curr->elmt : NULL; }
  T				*Next()					{ return curr && curr->next ? &curr->next->elmt : NULL; }
  T				*Prev()					{ return curr && curr->prev ? &curr->prev->elmt : NULL; }

  // routines that move the curr elmt
  T				*GoNext()				{ if (curr) curr = curr->next; return Curr(); }
  T				*GoPrev()				{ if (curr) curr = curr->prev; return Curr(); }

  // write & alloc fcns - returns new elmt
  T				&Append();		// add elmt to end of list
  T				&Prepend();		// add elmt to begginning of list
//    T				&InsertBefore();   insert elmt before current elmt
//    T				&InsertAfter();   insert elmt after current elmt

  // write & alloc & copy - returns list after copying elmt
  AsnList			&AppendAndCopy (T &elmt);	// add elmt to end of list
  AsnList			&PrependAndCopy (T &elmt);	// add elmt to begginning of list
//    AsnList			&InsertBeforeAndCopy (T &elmt);   insert elmt before current elmt
//    AsnList			&InsertAfterAndCopy (T &elmt);  insert elmt after current elmt

  // encode and decode routines
  AsnLen			BEncContent (BUF_TYPE b);
  void				BDecContent (BUF_TYPE b, AsnTag tagId, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);
  AsnLen			BEnc (BUF_TYPE b);
  void				BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);

  PDU_MEMBER_MACROS

#if META
  static const AsnTypeDesc	_desc;

  const AsnTypeDesc		*_getdesc() const;

#if TCL
  int				TclGetVal (Tcl_Interp *) const;
  int				TclSetVal (Tcl_Interp *, const char *val);
#endif /* TCL */
#endif /* META */
};

// This causes gcc2 on C++ to choke

#if 0
template <class T, class U>
int ListsEquiv (AsnList<T> &l1, AsnList<U> &l2);

template <class T, class U>
inline bool operator == (AsnList<T> &l1, AsnList<U> &l2)
{
  return ListsEquiv (l1, l2);
}

template <class T, class U>
inline bool operator != (AsnList<T> &l1, AsnList<U> &l2)
{
  return !ListsEquiv (l1,l2);
}
#endif

#endif /* conditional include */
