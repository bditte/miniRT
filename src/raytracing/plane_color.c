#include "minirt.h"

int     hit_pl(t_plane pl, t_ray r, t_inter *inter)
{
        float	denom;
	float	t;
        float	a;
	denom = dot(r.dir, pl.n);
	a = dot(vec_sub(r.o, pl.c), pl.n);
	if (denom == 0 || (a < 0 && denom < 0) || (a > 0 && denom > 0))
		return (0);
	t = -a / denom;
	if (t > 0)
	{
		inter->n = pl.n;
		inter->p = vec_multiply_t(t, vec_normalize(r.dir));
		inter->t = t;
                return (1);
	}
        return (0);
}

int	pl_inter(t_scene s, t_inter *inter)
{
	t_inter local_inter;
	int has_inter;

	if (inter->type == -3)
		local_inter.type = -3;
	has_inter = 0;
	local_inter.i = 0;
	while (local_inter.i < s.nbplanes)
	{
		if (hit_pl(s.planes[local_inter.i], s.r, &local_inter))
		{
			has_inter = 1;
			if (local_inter.t < inter->t || inter->t == -1)
				*inter = local_inter;
		}
		local_inter.i++;
	}
	return (has_inter);
}

t_inter		plane_color(t_scene s)
{
        t_inter	inter;
	int     has_inter;

	inter.t = -1;
	has_inter = pl_inter(s, &inter);
	if (has_inter)
        {
		inter.color = s.planes[inter.i].color;
       		inter.type = 1;
		inter.point = s.planes[inter.i].c;
	}
	return (inter);
}
