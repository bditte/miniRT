#include "minirt.h"

void	assign_inter(t_inter src, t_inter *dst)
{
	dst->p = src.p;
	dst->i = src.i;
	dst->n = src.n;
	dst->t = src.t;
}
