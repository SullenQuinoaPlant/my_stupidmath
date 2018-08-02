#ifndef MYSTUPIDMATH_H
# define MYSTUPIDMATH_H

# include <stdint.h>

/*constants*/

# define M_El 2.718281828459045235360287471352662498L


/*functions*/

long double
	my_expl(
		long double x);

int
	my_ilog2(
		uintmax_t);

long double
	my_lnl(
		long double x);

long double
	my_powl(
		long double x, long double y);

#endif
