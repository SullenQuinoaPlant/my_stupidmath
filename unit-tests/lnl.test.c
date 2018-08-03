#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_overlay.h"

#include "mystupidmath.h"

#define MAX_ERROR 0.00001

#define ABS(x) \
	((x) < 0 ? -(x) : (x))

int	declare_tests_and_run(int all_of, char *these[])
{
	T(letswatch,
		long double	x;
		long double	diff;
		long double	max_diff;

		for (x = 0.1L; x < 1; x += 0.1)
		{
			diff = lnl(x) - logl(x);
			if (ABS(diff) > ABS(max_diff))
				max_diff = diff;
		}
		assert_true(max_diff < MAX_ERROR);
	)
	return (run_test_arr(all_of, these));
}
