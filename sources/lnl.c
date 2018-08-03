# include "inner.h"

static
t_s_iaf
	split_x(
		long double x)
{
	t_s_iaf	ret;

	(void)x;
	ret = (t_s_iaf){0, 0};
	return (ret);
}

static
long double
	series(
		long double xx)
{
	(void)xx;
	return (0);
}

long double
	lnl(
		long double x)
{
	t_s_iaf	split;

	if (x < 0.0L)
		return (compose_nan());
	else if (x == 0.0L)
		return (compose_minf());
	split = split_x(x);
	return (intpow(M_LN2, split.i) * series(split.f));
}
