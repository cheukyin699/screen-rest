#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([screen_rest], [0.1.0], [cheukyin699@yahoo.com], [],
        [https://github.com/cheukyin699/screen-rest])
AC_CONFIG_SRCDIR([src/Main.cpp])
AC_CONFIG_HEADERS([config.h])

AC_LANG([C++])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADER([SFML/Audio.hpp], [], [AC_MSG_ERROR([SFML headers not found])])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.

AC_OUTPUT([Makefile])
