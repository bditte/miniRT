#include "miniRT.h"

int     hit_pl(t_plane pl, t_ray r, t_inter *inter)
{
        float	denom;
	float	t;
        denom = dot(r.dir, pl.n);
	if (denom > 0.000001)
        {
                t = dot(vec_sub(pl.c, r.o), pl.n) * -1 / denom;
		if (t > 0)
		{
			inter->n = pl.n;
			inter->p = vec_multiply_t(t, vec_normalize(r.dir));
			inter->t = t;
                        return (1);
		}
        }
        return (0);
}

int	pl_inter(t_ray r, t_scene s, t_inter *inter)
{
	t_inter local_inter;
	int has_inter;

	if (inter->type == -3)
		local_inter.type = -3;
	has_inter = 0;
	local_inter.i = 0;
	while (local_inter.i < s.nbPlanes)
	{
		if (hit_pl(s.planes[local_inter.i], r, &local_inter))
		{
			has_inter = 1;
			if (local_inter.t < inter->t)
				*inter = local_inter;
		}
		local_inter.i++;
	}
	return (has_inter);
}

t_inter		plane_color(t_ray r, t_scene s, int nbRebonds)
{
        t_inter	inter;
        t_vector p;
        t_vector vec_l;
        t_vector offset;
        t_ray   ray_light;
	int	i;
	int     has_inter;

	if (nbRebonds == 6)
		inter.type = -3;
	inter.t = 2147483647;
	has_inter = pl_inter(r, s, &inter);
	if (has_inter)
        {
		inter.color = s.planes[inter.i].color;
       		inter.type = 1;
	}
        else
                inter.t = -1;
	return (inter);
}
