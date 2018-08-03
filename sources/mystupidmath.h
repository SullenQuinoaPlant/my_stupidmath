#ifndef MYSTUPIDMATH_H
# define MYSTUPIDMATH_H

# include <stdint.h>

/*computation options :*/
/*# define LNL_SERIES_DEPTH 9000 //see lnl.c*/


/*mathematical constants :*/

# define M_E 2.718281828459045235360287471352662498L
# define M_LN2 0.693147180559945309417232121458176568L


/*functions :*/

long double
	expl(
		long double x);

int
	flog2(
		uintmax_t);

long double
	intpow(
		long double x, intmax_t n);

long double
	lnl(
		long double x);

long double
	powl(
		long double x, long double y);

long double
	uintpow(
		long double x, uintmax_t n);

#endif
