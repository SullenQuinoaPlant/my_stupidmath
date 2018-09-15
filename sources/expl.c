/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:09:11 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/15 07:53:34 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

#ifdef EXP_SERIES_DEPTH
# define SERIES_DEPTH EXP_SERIES_DEPTH
#else
# define SERIES_DEPTH 100
#endif

/*
static void					rec(
	int rank,
	long double acc,
	t_u_ata delta_ret)
{
	if (acc)
	{
		rec(rank + 1, acc * *delta_ret.arg / rank, delta_ret);
		*delta_ret.acc += acc;
	}
	else
		delta_ret.acc = 0;
}
*/

static void					rec(
	int rank,
	long double delta_pow,
	t_u_ata delta_ret)
{
	if (rank <= SERIES_DEPTH)
	{
		rec(rank + 1, delta_pow * *delta_ret.arg, delta_ret);
		*delta_ret.acc += delta_pow;
		*delta_ret.acc /= rank;
	}
	else
		delta_ret.acc = 0;
}

static long double			series(
		long double x)
{
	long double	ret;

	ret = x;
	rec(1, ret, (t_u_ata){&ret});
	ret += (x + 1.0);
	return (ret);
}

long double					my_expl(
	long double x)
{
	if (x == compose_minf())
		return (0);
	else if (x == compose_pinf())
		return (compose_pinf());
	return (series(x));
}
