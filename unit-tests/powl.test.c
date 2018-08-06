#define HOW_MANY_TESTS 10
#include "cmocka/my_overlay.h"

#include "math_ref.h"
#include "mystupidmath.h"

#define MAX_ERROR 0.00001L

#define ABS(x) (x < 0 ? -x : x)
	

static
long double
	powl_diff(
		long double x, long double y)
{
	long double	ref = lm_powl(x, y);
	long double tst = powl(x, y);
	return (tst - ref);
}

int	declare_tests_and_run(int all_of, char *these[])
{
	T(testtest,
		if (&lm_powl == &powl)
			fail();
	)
	T(error,
		long double	x;
		long double	y = 1.5;
		long double	diff;
		long double	max_diff;

		max_diff = 0;
		for (x = 0.1L; x < 1; x += 0.1)
		{
			diff = ABS(powl_diff(x, y));
			if (diff > max_diff)
				max_diff = diff;
		}
		assert_true(max_diff < MAX_ERROR);
	)
	T(error01,
		long double	x;
		long double	y = 1.5;
		long double	diff;
		long double	max_diff;

		max_diff = 0;
		for (x = 0.1L; x < 1; x += 0.1)
		{
			diff = ABS(powl_diff(x, y));
			if (diff > max_diff)
				max_diff = diff;
		}
		assert_true(max_diff < MAX_ERROR * 0.1L);
	)
	T(error001,
		long double	x;
		long double	y = 1.5;
		long double	diff;
		long double	max_diff;

		max_diff = 0;
		for (x = 0.1L; x < 1; x += 0.1)
		{
			diff = ABS(powl_diff(x, y));
			if (diff > max_diff)
				max_diff = diff;
		}
		assert_true(max_diff < MAX_ERROR * 0.01L);
	)
	T(bigger,
		long double	x;
		long double	y = 1.5;
		long double	diff;
		long double	max_diff;

		max_diff = 0;
		for (x = 10.0L; x < 1000000000000; x *= 10)
		{
			diff = ABS(powl_diff(x, y));
			if (diff > max_diff)
				max_diff = diff;
		}
		assert_true(max_diff < MAX_ERROR);
	)
	T(bigger01,
		long double	x;
		long double	y = 1.5;
		long double	diff;
		long double	max_diff;

		max_diff = 0;
		for (x = 10.0L; x < 1000000000000; x *= 10)
		{
			diff = ABS(powl_diff(x, y));
			if (diff > max_diff)
				max_diff = diff;
		}
		assert_true(max_diff < MAX_ERROR * 0.1L);
	)
	T(bigger001,
		long double	x;
		long double	y = 1.5;
		long double	diff;
		long double	max_diff;

		max_diff = 0;
		for (x = 10.0L; x < 1000000000000; x *= 10)
		{
			diff = ABS(powl_diff(x, y));
			if (diff > max_diff)
				max_diff = diff;
		}
		assert_true(max_diff < MAX_ERROR * 0.01L);
	)
	T(weirder,
		long double	x;
		long double	y = 1.5;
		long double	diff;
		long double	max_diff;

		max_diff = 0;
		for (x = 0.1L; x < 11000000000000; x *= 10.12)
		{
			diff = ABS(powl_diff(x, y));
			if (diff > max_diff)
				max_diff = diff;
		}
		assert_true(max_diff < MAX_ERROR);
	)
	T(weirder01,
		long double	x;
		long double	y = 1.5;
		long double	diff;
		long double	max_diff;

		max_diff = 0;
		for (x = 0.1L; x < 11000000000000; x *= 10.12)
		{
			diff = ABS(powl_diff(x, y));
			if (diff > max_diff)
				max_diff = diff;
		}
		assert_true(max_diff < MAX_ERROR * 0.1L);
	)
	T(weirder001,
		long double	x;
		long double	y = 1.5;
		long double	diff;
		long double	max_diff;

		max_diff = 0;
		for (x = 0.1L; x < 11000000000000; x *= 10.12)
		{
			diff = ABS(powl_diff(x, y));
			if (diff > max_diff)
				max_diff = diff;
		}
		assert_true(max_diff < MAX_ERROR * 0.01L);
	)
	T(test1,
		long double	diff;

		diff = ABS(powl_diff(10, -0.96488972683081529815862786847446841));
		assert_true(diff < MAX_ERROR);
	)
	T(test2,
		long double	diff;

		diff = ABS(powl_diff(10, 0.96488972683081529815862786847446841));
		assert_true(diff < MAX_ERROR);
	)
	T(test3,
		long double	diff;

		diff = ABS(powl_diff(10.1, -0.96488972683081529815862786847446841));
		assert_true(diff < MAX_ERROR);
	)
	return (run_test_arr(all_of, these));
}
