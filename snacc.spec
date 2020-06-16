Name:           snacc
Version:        1.3
Release:        4%{?dist}
Summary:        Sample Neufeld ASN.1 to C Compiler

Group:          Applications/System
License:        GPLv2+
URL:            http://packages.debian.org/source/sid/snacc
Source0:        https://github.com/nevali/snacc/archive/snacc-1.3.1.tar.gz

BuildRequires:  autoconf automake libtool flex bison

%description
Snacc is Sample Neufeld ASN.1 to C compiler that can produce C, C++ routines
or type tables for BER encoding, decoding, printing and freeing.

%package devel
Summary:        Header files for snacc development
Group:          Development/Libraries
Requires:       %{name} = %{version}-%{release} 

%description devel
The %{name}-devel package contains the header files
for snacc development.

%prep
%setup -qn snacc-snacc-1.3.1
%{__mkdir} -p c-lib/Cebuf c-lib/ebuf c-lib/mbuf c-lib/sbuf c-lib/tbl c++-lib/c++

%build
AUTOMAKE=automake ACLOCAL=aclocal autoreconf -fi
%configure
%{__make}

%install
%{__rm} -rf %{buildroot}
%{__make} INSTALL="%{_bindir}/install -p" install DESTDIR=%{buildroot}
%{__rm} -f `find %{buildroot} -name *.a`
%{__rm} -f `find %{buildroot} -name *.la`

%clean
%{__rm} -rf %{buildroot}

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%defattr(-,root,root,-)
%doc README COPYING doc/snacc-a5.ps
%dir %{_includedir}/%{name}/
%{_includedir}/%{name}/asn1
%{_bindir}/%{name}
%{_bindir}/berdecode
%{_bindir}/mkchdr
%{_bindir}/ptbl
%{_bindir}/pval
%{_mandir}/man1/mkchdr.1.gz
%{_mandir}/man1/ptbl.1.gz
%{_mandir}/man1/pval.1.gz
%{_mandir}/man1/snacc.1.gz
%{_mandir}/man1/snacced.1.gz
%{_mandir}/mann/snacc.n.gz
%{_libdir}/libasn1c++.so.0.0.0
%{_libdir}/libasn1cCebuf.so.0.0.0
%{_libdir}/libasn1cebuf.so.0.0.0
%{_libdir}/libasn1cmbuf.so.0.0.0
%{_libdir}/libasn1csbuf.so.0.0.0
%{_libdir}/libasn1ctbl.so.0.0.0
%{_libdir}/libasn1c++.so.0
%{_libdir}/libasn1cCebuf.so.0
%{_libdir}/libasn1cebuf.so.0
%{_libdir}/libasn1cmbuf.so.0
%{_libdir}/libasn1csbuf.so.0
%{_libdir}/libasn1ctbl.so.0

%files devel
%defattr(-,root,root,-)
%doc c-examples/ c++-examples/
%{_bindir}/snacc-config
%{_datadir}/aclocal/snacc.m4
%{_includedir}/%{name}/c
%{_includedir}/%{name}/c++
%{_libdir}/libasn1c++.so
%{_libdir}/libasn1cCebuf.so
%{_libdir}/libasn1cebuf.so
%{_libdir}/libasn1cmbuf.so
%{_libdir}/libasn1csbuf.so
%{_libdir}/libasn1ctbl.so
%{_libdir}/pkgconfig/snacc-c-ebuf.pc

%changelog
* Sat Sep 26 2009 Shakthi Kannan <shakthimaan [AT] gmail DOT com> 1.3-4
- Removed --without-tcl as it doesn not affect configure.
- snacc-configure.patch will not build c++-lib/tcl/Makefile as tcl is not
  required. 

* Thu Sep 24 2009 Shakthi Kannan <shakthimaan [AT] gmail DOT com> 1.3-3
- Removed -libs package, and moved them to -base package.
- s/sample/Sample in package description.
- Directory ownership in base package for includedir/name.
- snacc.m4 moved to -devel package.
- Patch names start with snacc-.
- Removed .tex and .bib files as .ps is already shipped.

* Wed Sep 23 2009 Shakthi Kannan <shakthimaan [AT] gmail DOT com> 1.3-2
- Fixed spelling mistake s/dample/sample.
- Added {c, c++}-examples to devel package.
- Moved *.asn1 files to base package.
- Created separate libs package.
- Call ldconfig for post, postun for libs package.

* Mon Sep 21 2009 Shakthi Kannan <shakthimaan [AT] gmail DOT com> 1.3-1
- First snacc package.
