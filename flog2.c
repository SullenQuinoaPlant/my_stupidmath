#include "inner.h"

int		flog2(uintmax_t x)
{
	int		i;

	i = 0;
	while ((x /= 2))
		i++;
	return (i);
}
