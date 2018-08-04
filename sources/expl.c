#include "inner.h"

#ifdef EXP_SERIES_DEPTH
# define SERIES_DEPTH EXP_SERIES_DEPTH
#else
# define SERIES_DEPTH 100
#endif

static
void
	rec(
		int rank, long double delta_pow,
		t_u_ata delta_ret)
{
	if (!(rank <= SERIES_DEPTH))
		*delta_ret.acc = 1;
	else
		rec(rank + 1, delta_pow * *delta_ret.arg, delta_ret);
	*delta_ret.acc += delta_pow;
	*delta_ret.acc /= rank;
}

static
long double
	series(
		long double x)
{
	long double	ret;

	ret = x;
	rec(1, ret, (t_u_ata){&ret});
	return (ret);
}

long double
	expl(
		long double x)
{
	t_s_iaf	split;

	if (x == compose_minf())
		return (0);
	else if (x == compose_pinf())
		return (compose_pinf());
	return (series(x));
}
