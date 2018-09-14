/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intpow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:26:39 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 12:27:32 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

long double						my_intpowl(
	long double x,
	intmax_t n)
{
	if (n < 0)
		return (my_uintpowl(x ? 1 / x : x, -n));
	else
		return (my_uintpowl(x, n));
}

static void						recursion(
	uintmax_t power,
	long double val,
	uintmax_t *n,
	long double *res)
{
	if (*n & power)
		*res *= val;
	if (power < *n)
	recursion(power * 2, val * val, n, res);
}

long double						my_uintpowl(
	long double x,
	uintmax_t n)
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
