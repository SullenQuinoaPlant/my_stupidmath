#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_overlay.h"

#include <math.h>
#include "mystupidmath.h"

#define MAX_ERROR 0.00001L

#define ABS(x) ((x < 0) ? -1.0L * x : x)
	

static
long double
	ln_diff(
		long double x)
{
	long double	ref = logl(x);
	long double tst = lnl(x);
	return (tst - ref);
}

int	declare_tests_and_run(int all_of, char *these[])
{
	T(macro,
		int		i = -2;

		i = ABS(i);
		printf("i is : %d\n", i);
		assert_true(i == 2);
	)

	T(letswatch,
		long double	x;
		long double	diff;
		long double	max_diff;

		max_diff = 0;
		for (x = 0.1L; x < 1; x += 0.1)
		{
			diff = ln_diff(x);
			printf("diff is :%f\n", diff);
			if (ABS(diff) > max_diff)
				max_diff = ABS(diff);
		}
printf("max_diff : %f, abs of :%f\n", max_diff, ABS(max_diff));
printf("%f comp : %d : error : %f\n", max_diff, (max_diff < MAX_ERROR), MAX_ERROR);
		assert_true(max_diff < MAX_ERROR);
	)
	return (run_test_arr(all_of, these));
}
