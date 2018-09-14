/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:27:41 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 12:52:53 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inner.h"

/*
**big is used to avoid least good approximations
**near x=2; Not sure it's worth it considering 
**the loss of precision.
*/

static t_s_iaf							split_x(
	long double x)
{
	t_s_iaf		ret;
	t_s_dfp		dec;
	long double	const big = 1.9375L;

	decompose_ldouble(&x, &dec);
	ret.i = dec.exp;
	ret.f = make_ldouble(0, dec.mant, -LDB_MANT_PRECISION);
	if (ret.f > big)
	{
		ret.i++;
		ret.f /=2;
	}
	return (ret);
}

#ifdef LNL_SERIES_DEPTH
# define SERIES_DEPTH LNL_SERIES_DEPTH
#else
# define SERIES_DEPTH 100
#endif

static void								rec(
	int rank,
	long double delta_pow,
	t_u_ata delta_ret)
{
	if (!(rank <= SERIES_DEPTH))
		*delta_ret.acc = 0;
	else
		rec(rank + 1, delta_pow * *delta_ret.arg, delta_ret);
	if (rank & 1)
		*delta_ret.acc += (delta_pow / rank);
	else
		*delta_ret.acc -= (delta_pow / rank);
}


stati clong double						series(
	long double xx)
{
	long double	ret;

	ret = xx - 1;
	rec(1, ret, (t_u_ata){&ret});
	return (ret);
}

long double								my_lnl(
	long double x)
{
	t_s_iaf	split;

	if (x < 0.0L || x == compose_minf())
		return (compose_nan());
	else if (x == 0.0L)
		return (compose_minf());
	else if (x == compose_pinf())
		return (compose_pinf());
	split = split_x(x);
	return (M_LN2l * split.i + series(split.f));
}
