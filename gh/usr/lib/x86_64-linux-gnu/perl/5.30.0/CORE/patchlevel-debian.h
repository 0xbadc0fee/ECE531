	,"DEBPKG:debian/cpan_definstalldirs - Provide a sensible INSTALLDIRS default for modules installed from CPAN."
	,"DEBPKG:debian/db_file_ver - https://bugs.debian.org/340047 Remove overly restrictive DB_File version check."
	,"DEBPKG:debian/doc_info - Replace generic man(1) instructions with Debian-specific information."
	,"DEBPKG:debian/enc2xs_inc - https://bugs.debian.org/290336 Tweak enc2xs to follow symlinks and ignore missing @INC directories."
	,"DEBPKG:debian/errno_ver - https://bugs.debian.org/343351 Remove Errno version check due to upgrade problems with long-running processes."
	,"DEBPKG:debian/libperl_embed_doc - https://bugs.debian.org/186778 Note that libperl-dev package is required for embedded linking"
	,"DEBPKG:fixes/respect_umask - Respect umask during installation"
	,"DEBPKG:debian/writable_site_dirs - Set umask approproately for site install directories"
	,"DEBPKG:debian/extutils_set_libperl_path - EU:MM: set location of libperl.a under /usr/lib"
	,"DEBPKG:debian/no_packlist_perllocal - Don't install .packlist or perllocal.pod for perl or vendor"
	,"DEBPKG:debian/fakeroot - Postpone LD_LIBRARY_PATH evaluation to the binary targets."
	,"DEBPKG:debian/instmodsh_doc - Debian policy doesn't install .packlist files for core or vendor."
	,"DEBPKG:debian/ld_run_path - Remove standard libs from LD_RUN_PATH as per Debian policy."
	,"DEBPKG:debian/libnet_config_path - Set location of libnet.cfg to /etc/perl/Net as /usr may not be writable."
	,"DEBPKG:debian/perlivp - https://bugs.debian.org/510895 Make perlivp skip include directories in /usr/local"
	,"DEBPKG:debian/squelch-locale-warnings - https://bugs.debian.org/508764 Squelch locale warnings in Debian package maintainer scripts"
	,"DEBPKG:debian/patchlevel - https://bugs.debian.org/567489 List packaged patches for 5.30.0-9ubuntu0.3 in patchlevel.h"
	,"DEBPKG:fixes/document_makemaker_ccflags - https://bugs.debian.org/628522 [rt.cpan.org #68613] Document that CCFLAGS should include $Config{ccflags}"
	,"DEBPKG:debian/find_html2text - https://bugs.debian.org/640479 Configure CPAN::Distribution with correct name of html2text"
	,"DEBPKG:debian/perl5db-x-terminal-emulator.patch - https://bugs.debian.org/668490 Invoke x-terminal-emulator rather than xterm in perl5db.pl"
	,"DEBPKG:debian/cpan-missing-site-dirs - https://bugs.debian.org/688842 Fix CPAN::FirstTime defaults with nonexisting site dirs if a parent is writable"
	,"DEBPKG:fixes/memoize_storable_nstore - [rt.cpan.org #77790] https://bugs.debian.org/587650 Memoize::Storable: respect 'nstore' option not respected"
	,"DEBPKG:debian/makemaker-pasthru - https://bugs.debian.org/758471 Pass LD settings through to subdirectories"
	,"DEBPKG:debian/makemaker-manext - https://bugs.debian.org/247370 Make EU::MakeMaker honour MANnEXT settings in generated manpage headers"
	,"DEBPKG:debian/kfreebsd-softupdates - https://bugs.debian.org/796798 Work around Debian Bug#796798"
	,"DEBPKG:fixes/autodie-scope - https://bugs.debian.org/798096 Fix a scoping issue with \"no autodie\" and the \"system\" sub"
	,"DEBPKG:fixes/memoize-pod - [rt.cpan.org #89441] Fix POD errors in Memoize"
	,"DEBPKG:debian/hurd-softupdates - https://bugs.debian.org/822735 Fix t/op/stat.t failures on hurd"
	,"DEBPKG:fixes/math_complex_doc_great_circle - https://bugs.debian.org/697567 [rt.cpan.org #114104] Math::Trig: clarify definition of great_circle_midpoint"
	,"DEBPKG:fixes/math_complex_doc_see_also - https://bugs.debian.org/697568 [rt.cpan.org #114105] Math::Trig: add missing SEE ALSO"
	,"DEBPKG:fixes/math_complex_doc_angle_units - https://bugs.debian.org/731505 [rt.cpan.org #114106] Math::Trig: document angle units"
	,"DEBPKG:fixes/cpan_web_link - https://bugs.debian.org/367291 CPAN: Add link to main CPAN web site"
	,"DEBPKG:debian/hppa_op_optimize_workaround - https://bugs.debian.org/838613 Temporarily lower the optimization of op.c on hppa due to gcc-6 problems"
	,"DEBPKG:debian/installman-utf8 - https://bugs.debian.org/840211 Generate man pages with UTF-8 characters"
	,"DEBPKG:fixes/getopt-long-4 - https://bugs.debian.org/864544 [rt.cpan.org #122068] Fix issue #122068."
	,"DEBPKG:debian/hppa_opmini_optimize_workaround - https://bugs.debian.org/869122 Lower the optimization level of opmini.c on hppa"
	,"DEBPKG:debian/sh4_op_optimize_workaround - https://bugs.debian.org/869373 Also lower the optimization level of op.c and opmini.c on sh4"
	,"DEBPKG:debian/perldoc-pager - https://bugs.debian.org/870340 [rt.cpan.org #120229] Fix perldoc terminal escapes when sensible-pager is less"
	,"DEBPKG:debian/prune_libs - https://bugs.debian.org/128355 Prune the list of libraries wanted to what we actually need."
	,"DEBPKG:debian/mod_paths - Tweak @INC ordering for Debian"
	,"DEBPKG:debian/configure-regen - https://bugs.debian.org/762638 Regenerate Configure et al. after probe unit changes"
	,"DEBPKG:debian/deprecate-with-apt - https://bugs.debian.org/747628 Point users to Debian packages of deprecated core modules"
	,"DEBPKG:debian/disable-stack-check - https://bugs.debian.org/902779 [perl #133327] Disable debugperl stack extension checks for binary compatibility with perl"
	,"DEBPKG:fixes/eumm-usrmerge - https://bugs.debian.org/913637 Avoid mangling /bin non-perl shebangs on merged-/usr systems"
	,"DEBPKG:debian/perlbug-editor - https://bugs.debian.org/922609 Use \"editor\" as the default perlbug editor, as per Debian policy"
	,"DEBPKG:fixes/gid-parsing - [79e302e] https://bugs.debian.org/941985 [perl #134169] (perl #134169) mg.c reset endptr after use"
	,"DEBPKG:fixes/CVE-2020-10543.patch - [PATCH v530 1/4] regcomp.c: Prevent integer overflow from nested regex quantifiers."
	,"DEBPKG:fixes/CVE-2020-10878-1.patch - [PATCH v530 2/4] study_chunk: extract rck_elide_nothing"
	,"DEBPKG:fixes/CVE-2020-10878-2.patch - [PATCH v530 3/4] regcomp: use long jumps if there is any possibility of overflow"
	,"DEBPKG:fixes/CVE-2020-12723.patch - [PATCH v530 4/4] study_chunk: avoid mutating regexp program within GOSUB"
	,"DEBPKG:CVE-2020-16156-1.patch - [PATCH] bugfix: signature verification type CANNOT_VERIFY was not recognized"
	,"DEBPKG:CVE-2020-16156-2.patch - [PATCH] Add two new failure modes based on cpan_path"
	,"DEBPKG:CVE-2020-16156-3.patch - [PATCH] use gpg --verify --output ... to disentangle data and signature"
	,"DEBPKG:CVE-2020-16156-4.patch - [PATCH] replacing die with mydie in three spots"
	,"DEBPKG:CVE-2020-16156-5.patch - [PATCH] disambiguate the call to gpg --output by adding --verify"
	,"DEBPKG:CVE-2020-16156-6.patch - [PATCH] s/gpg/$gpg/ in system, add quotes where needed"
	,"DEBPKG:CVE-2020-16156-7.patch - [PATCH] s,/dev/null,$devnull,"
