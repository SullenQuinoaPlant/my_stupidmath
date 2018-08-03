#include <stdio.h>
#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include "mystupidmath.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(test1,
		assert_true(4.0 == intpow(2, 2));
	)
	T(test2,
		assert_true(0.5L == intpow(2, -1));
	)
	T(test3,
		assert_true(0.0 == intpow(0, 2));
	)
	T(test4,
		assert_true(1.0L == intpow(2, 0));
	)
	T(test5,
		assert_true(4.0 == uintpow(2, 2));
	)
	T(test2,
		assert_true(0.25L == intpow(0.5L, 2));
	)

	return (run_test_arr(all_of, these));
}
