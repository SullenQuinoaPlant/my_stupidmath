#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "my_overlay.h"

#include "mystupidmath.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(test0,
		assert_true(0 == my_flog2(0));
	)
	T(test1,
		assert_true(0 == my_flog2(1));
	)
	T(test2,
		assert_true(1 == my_flog2(2));
	)
	T(test3,
		assert_true(1 == my_flog2(3));
	)
	T(test4,
		assert_true(2 == my_flog2(4));
	)
	return (run_test_arr(all_of, these));
}
