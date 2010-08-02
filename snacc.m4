dnl Copyright (c) 1999 BBN Corporation
dnl
dnl Permission to use, copy, modify, and distribute this software
dnl and its documentation for any purpose is hereby granted without
dnl fee, provided that the above copyright notice and this permission
dnl appear in all copies and in supporting documentation, and that the
dnl name of BBN Corporation not be used in advertising or publicity
dnl pertaining to distribution of the software without specific,
dnl written prior permission. BBN makes no representations about the
dnl suitability of this software for any purposes.  It is provided "AS
dnl IS" without express or implied warranties.
dnl
dnl This software and its documentation was written by BBN Corporation
dnl under sponsorship by the Defense Advanced Research Projects Agency.

dnl $Header: /IR-CVS/snacc/snacc.m4,v 1.1 1999/12/03 17:11:37 fredette Exp $
dnl $Author: fredette $
dnl $Date: 1999/12/03 17:11:37 $
dnl $Id: snacc.m4,v 1.1 1999/12/03 17:11:37 fredette Exp $
dnl $Revision: 1.1 $

dnl AM_PATH_SNACC(BUFFER-TYPE [, MINIMUM-VERSION, [ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]]])
undefine(AM_PATH_SNACC)
AC_DEFUN(AM_PATH_SNACC,
[dnl
AC_ARG_WITH(snacc-prefix,
[  --with-snacc-prefix=DIR prefix where snacc is installed (optional)],
[ with_snacc_prefix=`cd $with_snacc_prefix 2>/dev/null && pwd` ], [ ])
AC_ARG_WITH(snacc-exec-prefix,
[  --with-snacc-exec-prefix=DIR  exec prefix where snacc is installed (optional)],
[ with_snacc_exec_prefix=`cd $with_snacc_exec_prefix 2>/dev/null && pwd` ], [ ])
AC_ARG_WITH(snacc, 
[  --with-snacc=DIR        use an uninstalled snacc in DIR (optional)],
[ with_snacc=`cd $with_snacc 2>/dev/null && pwd` ], [ ])
SNACC_DEPS=
if test x$with_snacc != x; then
  if $SHELL -c "$with_snacc/snacc-config --version" >/dev/null 2>&1; then
    SNACC_CONFIG_UN="$with_snacc/snacc-config --uninstalled=$with_snacc"
    SNACC_CONFIG="`$with_snacc/snacc-config --exec-prefix`/bin/snacc-config"
    for dep in `$SNACC_CONFIG_UN --libs --libtool $1`; do
      case $dep in
      -l*) ;; -L*) ;;
      *) SNACC_DEPS="${SNACC_DEPS-} $dep" ;;
      esac
    done
  else
    SNACC_CONFIG_UN=no
    SNACC_CONFIG=no
  fi
else
  if test x$with_snacc_prefix != x; then
    snacc_config_args="${snacc_config_args-} --prefix=$with_snacc_prefix"
    if test x$with_snacc_exec_prefix = x; then 
      with_snacc_exec_prefix=$with_snacc_prefix
    fi
  fi
  if test x$with_snacc_exec_prefix != x; then 
    snacc_config_args="${snacc_config_args-} --exec-prefix=$with_snacc_exec_prefix"
    SNACC_CONFIG="$with_snacc_exec_prefix/bin/snacc-config $snacc_config_args"
  else
    AC_PATH_PROGS(SNACC_CONFIG, snacc-config, no)
  fi
  SNACC_CONFIG_UN=$SNACC_CONFIG
fi
if test "$SNACC_CONFIG_UN" != no && \
   $SHELL -c "$SNACC_CONFIG_UN --version" >/dev/null 2>&1; then 
  SNACC=`$SNACC_CONFIG_UN --compiler`
  SNACC_ASN1SPECS=`$SNACC_CONFIG_UN --asn1specs`
  SNACC_CFLAGS=`$SNACC_CONFIG_UN --cflags $1`
  SNACC_LIBS=`$SNACC_CONFIG_UN --libs --libtool $1`
  $3
else
  SNACC=no
  SNACC_CONFIG=no
  SNACC_CONFIG_UN=no
  SNACC_DEPS=
  $4
fi
AC_SUBST(SNACC)
AC_SUBST(SNACC_ASN1SPECS)
AC_SUBST(SNACC_CONFIG)
AC_SUBST(SNACC_CONFIG_UN)
AC_SUBST(SNACC_CFLAGS)
AC_SUBST(SNACC_LIBS)
AC_SUBST(SNACC_DEPS)
])dnl

