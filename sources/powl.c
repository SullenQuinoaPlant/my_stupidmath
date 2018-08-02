#include "inner.h"

long double
	powl(
		long double x, long double y)
{
	return (expl(y * lnl(x)));
}
