#include "inner.h"

int		my_flog2(uintmax_t x)
{
	int		i;

	i = 0;
	while ((x /= 2))
		i++;
	return (i);
}