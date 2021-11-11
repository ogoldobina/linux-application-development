#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([rhasher], [1.0], [goldobina-olga.7@mail.ru])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([rhash], [rhash_library_init], [], [AC_MSG_ERROR([rhash is not installed])])
AC_ARG_WITH([readline], AS_HELP_STRING([--without-readline], [disable readline]),
    	    [], AC_CHECK_LIB([readline], [readline]))

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h stdio.h ctype.h errno.h rhash.h readline/readline.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([strcspn strerror])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
