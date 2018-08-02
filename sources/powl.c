#include "inner.h"

long double
	my_powl(
		long double x, long double y)
{
	return (my_expl(y * my_lnl(x)));
}
