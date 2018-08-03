#include "inner.h"

long double
	intpow(
		long double x, intmax_t n)
{
	if (n < 0)
		return (uintpow(x ? 1 / x : x, -n));
	else
		return (uintpow(x, n));
}

static
void
	recursion(
		uintmax_t power, long double val,
		uintmax_t *n, long double *res)
{
	if (*n & power)
		*res *= val;
	if (power < *n)
	recursion(power * 2, val * val, n, res);
}

long double
	uintpow(
		long double x, uintmax_t n)
{
	long double	ret;

	if (!n)
		return (1.0L);
	else if (!x)
		return (0);
	ret = 1;
	recursion(1, x, &n, &ret);
	return (ret);
}
