AC_PREREQ(2.59)
AC_INIT([groonga-help], 0.0.2, [yokoyama@clear-code.com])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([help/help.c])
AM_CONFIG_HEADER([config.h])

AM_INIT_AUTOMAKE(foreign)
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_PROG_CXX

AC_PROG_LIBTOOL

if test "$GCC" = "yes"; then
  CFLAGS="$CFLAGS -Wall -Wextra"
  CFLAGS="$CFLAGS -Wmissing-declarations -Wmissing-prototypes"
fi

AC_ARG_ENABLE(debug,
  [AS_HELP_STRING([--enable-debug],
                  [use debug flags (default=no)])],
  [sample_debug="$enableval"],
  [sample_debug="no"])
if test "x$sample_debug" != "xno"; then
  if test "$CLANG" = "yes"; then
    CFLAGS="$CFLAGS -O0 -g"
  elif test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS -O0 -g3"
  fi
fi

GROONGA_REQUIRED_VERSION=2.0.9
PKG_CHECK_MODULES([GROONGA], [groonga >= ${GROONGA_REQUIRED_VERSION}])

_PKG_CONFIG(GROONGA_PLUGINS_DIR, [variable=pluginsdir],    [groonga])
_PKG_CONFIG(GROONGA,             [variable=groonga],       [groonga])
_PKG_CONFIG(GROONGA_HTTPD,       [variable=groonga_httpd], [groonga])

GROONGA_PLUGINS_DIR="${pkg_cv_GROONGA_PLUGINS_DIR}"
GROONGA="${pkg_cv_GROONGA}"
GROONGA_HTTPD="${pkg_cv_GROONGA_HTTPD}"

AC_SUBST(GROONGA_PLUGINS_DIR)
AC_SUBST(GROONGA)
AC_SUBST(GROONGA_HTTPD)

help_pluginsdir="\${GROONGA_PLUGINS_DIR}/help"
AC_SUBST(help_pluginsdir)

AC_CONFIG_FILES([
  Makefile
  help/Makefile
  help_mruby/Makefile
  test/Makefile
])

# mruby
AC_ARG_ENABLE(mruby,
  [AS_HELP_STRING([--enable-mruby],
    [enable mruby. [default=no]])],
  [enable_mruby="$enableval"],
  [enable_mruby="no"])

AC_MSG_CHECKING([whether enable mruby])
if test "x$enable_mruby" != "xyes"; then
  enable_mruby="no"
fi
AC_MSG_RESULT($enable_mruby)

if test "$enable_mruby" = "yes"; then
  if test ! -f "$srcdir/vendor/mruby/mruby_build.timestamp" -a \
          "$ac_cv_ruby_available" != "yes"; then
    AC_MSG_ERROR(--enable-mruby requires --with-ruby)
  fi
  AC_DEFINE(GRN_WITH_MRUBY, [1], [Define to 1 if mruby is enabled.])
  MRUBY_CFLAGS="-I\$(top_srcdir)/vendor/mruby-source/include"
else
  MRUBY_CFLAGS=""
fi
AC_SUBST(MRUBY_CFLAGS)
AM_CONDITIONAL(WITH_MRUBY, test "$enable_mruby" = "yes")

# plugins check
relative_pluginsdir_base="\$(PACKAGE)/plugins"
AC_SUBST(relative_pluginsdir_base)
expanded_relative_pluginsdir_base="${PACKAGE}/plugins"
AC_SUBST(expanded_relative_pluginsdir_base)

relative_pluginsdir="lib/\$(relative_pluginsdir_base)"
AC_SUBST(relative_pluginsdir)

pluginsdir="\${libdir}/\$(relative_pluginsdir_base)"
AC_SUBST(pluginsdir)
expanded_pluginsdir="\${libdir}/${expanded_relative_pluginsdir_base}"
AC_SUBST(expanded_pluginsdir)

tokenizer_pluginsdir="\${pluginsdir}/tokenizers"
AC_SUBST(tokenizer_pluginsdir)

query_expander_pluginsdir="\${pluginsdir}/query_expanders"
AC_SUBST(query_expander_pluginsdir)

suggest_pluginsdir="\${pluginsdir}/suggest"
AC_SUBST(suggest_pluginsdir)

table_pluginsdir="\${pluginsdir}/table"
AC_SUBST(table_pluginsdir)

ruby_pluginsdir="\${pluginsdir}/ruby"
AC_SUBST(ruby_pluginsdir)

token_filter_pluginsdir="\${pluginsdir}/token_filters"
AC_SUBST(token_filter_pluginsdir)

sharding_pluginsdir="\${pluginsdir}/sharding"
AC_SUBST(sharding_pluginsdir)

function_pluginsdir="\${pluginsdir}/functions"
AC_SUBST(function_pluginsdir)

expression_rewriter_pluginsdir="\${pluginsdir}/expression_rewriters"
AC_SUBST(expression_rewriter_pluginsdir)

AC_MSG_CHECKING(for the suffix of plugin shared libraries)
shrext_cmds=$(./libtool --config | grep '^shrext_cmds=')
eval $shrext_cmds
module=yes eval suffix="$shrext_cmds"
AC_MSG_RESULT($suffix)
if test -z "$suffix"; then
  AC_MSG_ERROR([can't detect plugin suffix])
fi
AC_DEFINE_UNQUOTED(GRN_PLUGIN_SUFFIX, ["$suffix"], "plugin suffix")

AC_OUTPUT

echo "$PACKAGE_NAME $PACKAGE_VERSION configuration:"
echo "-----------------------"
echo "  Compiler:              ${CC}"
echo "  CFLAGS:                ${CFLAGS}"
echo "  CXXFLAGS:              ${CXXFLAGS}"
echo "  Libraries:             ${LIBS}"
echo
echo "groonga-help"
echo "  CFLAGS:                ${GROONGA_CFLAGS}"
echo "  Libraries:             ${GROONGA_LIBS}"
echo "  install directory:     ${help_pluginsdir}"
