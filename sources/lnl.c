# include "inner.h"

/*big is used to avoid lest good approximations
**near x=2; Not sure it's worth it considering 
**the loss of precision.*/
static
t_s_iaf
	split_x(
		long double x)
{
	t_s_iaf	ret;
	t_s_dfp	dec;
	uint64_t	const big = (uint64_t)1 << 40;

	decompose_ldouble(&x, &dec);
	ret.i = dec.exp;
	ret.f = make_ldouble(0, dec.mant, -LDB_MANT_PRECISION);
	if (dec.mant > big)
	{
		ret.i++;
		ret.f /=2;
	}
	return (ret);
}

#define SERIES_DEPTH 50
static
void
	rec(
		int rank, long double delta_pow,
		t_u_ata delta_ret)
{
	if (!(rank <= SERIES_DEPTH && delta_pow))
		*delta_ret.acc = 0;
	else
		rec(rank + 1, delta_pow * *delta_ret.arg, delta_ret);
	if (rank & 1)
		*delta_ret.acc += (delta_pow / rank);
	else
		*delta_ret.acc -= (delta_pow / rank);
}

static
long double
	series(
		long double xx)
{
	long double	ret;

	ret = xx - 1;
	rec(1, ret, (t_u_ata.arg)&ret);
	return (ret);
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
