#ifndef MY_STUPIDMATH_INNER_H
# define MY_STUPIDMATH_INNER_H

# include "libmyfloatingpoint.h"
# include "mystupidmath.h"

typedef struct	s_int_and_float {
	intmax_t	i;
	long double	f;
}				t_s_iaf;

typedef union	u_arg_then_acc {
	long double *arg;
	long double	*acc;
}				t_u_ata;

#endif
