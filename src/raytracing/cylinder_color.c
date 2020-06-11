#include "miniRT.h"

int	quadratic_solve(t_vector abc, float *x1, float *x2)
{
	float	delta;
	float	q;
	float	temp;

	delta = abc.y * abc.y - 4.0 * abc.x * abc.z;
	if (delta < 0)
		return (0);
	if (delta == 0)
	{
		*x1 = -0.5 * abc.y / (abc.x);
		*x2 = *x1;
	}
	else
	{
		*x1 = (-abc.y + sqrt(delta)) / (2.0 * abc.x);
		*x2 = (-abc.y - sqrt(delta)) / (2.0 * abc.x);
	}
	return (2);
}

t_cyl_vars	get_cyl_vars(t_ray r, t_cylinder cyl)
{
	t_cyl_vars	vars;

	vars.p = r.o;
	vars.v = r.dir;
	vars.pa = cyl.c;
	vars.va = cyl.axis;
	vars.oc = vec_sub(vars.p, vars.pa);
	vars.utils1 = vec_sub(vars.v, vec_multiply_t(dot(vars.v, vars.va), vars.va));
	vars.utils2 = vec_sub(vars.oc, vec_multiply_t(dot(vars.oc, vars.va), vars.va));
	vars.abc.x = getNorme2(vars.utils1);
	vars.abc.y = 2.0 * dot(vars.utils1, vars.utils2);
	vars.abc.z = getNorme2(vars.utils2) - cyl.r * cyl.r;
	vars.vec1 = vec_sub(vars.pa, vec_multiply_t(cyl.h / 2, vars.va));
	vars.vec2 = vec_add(vars.pa, vec_multiply_t(cyl.h / 2, vars.va));
	return (vars);
}

t_vector	invert(t_vector vec)
{
	t_vector res;

	res.x = vec.x * -1;
	res.y = vec.y * -1;
	res.z = vec.z * -1;

	return (res);
}

t_vector	get_normal(t_ray r, t_vector normal)
{
	float res;
	t_vector	temp;
	
	res = dot(r.dir, normal);
	if (res < 0)
		return (normal);
	return (invert(normal));
}

void	get_cyl_data(t_ray r, float res, t_cylinder cyl, t_inter *inter)
{
	t_vector pc;
	
	pc = vec_sub(inter->p, cyl.c);
	inter->t = res;
	inter->color = cyl.color;
	inter->p = vec_add(r.o, vec_multiply_t(res, r.dir));
	inter->n = //get_normal(r, cyl.axis);
	vec_sub(pc, vec_multiply_t(dot(cyl.axis, pc), cyl.axis));
	/*
 *
 *	inter->p = 
 *	inter->n =  
*/
}

int	hit_cy(t_ray r, t_cylinder cyl, t_inter *inter)
{
	t_vector	q;
	t_cyl_vars	vars;
	float		res;

	res = -1;
	vars = get_cyl_vars(r, cyl);
	if (quadratic_solve(vars.abc, &cyl.x1, &cyl.x2))
	{
		q = vec_add(vars.p, vec_multiply_t(cyl.x1, vars.v));
		if (cyl.x1 > 0 && dot(vars.va, vec_sub(q, vars.vec1)) > 0 \
			&& dot(vars.va, vec_sub(q, vars.vec2)) < 0)
			res = cyl.x1;	
		q = vec_add(vars.p, vec_multiply_t(cyl.x2, vars.v));
		if (cyl.x1 > 0 && dot(vars.va, vec_sub(q, vars.vec1)) > 0 \
                        && dot(vars.va, vec_sub(q, vars.vec2)) < 0)
			res = res != -1 ? fmin(cyl.x1, cyl.x2) : cyl.x1;
	}
	if (res > 0)
		get_cyl_data(r, res, cyl, inter);
	return (res != -1);

		
}

int	cy_inter(t_ray r, t_scene s, t_inter *inter)
{
	int	res;
	t_inter	local;

	local.t = 214748364700;
	local.i = 0;
	res = 0;
	while (local.i < s.nbCylinders)
	{
		if (hit_cy(r, s.cylinders[local.i], &local))
		{
			res = 1;
			if (local.t < inter->t && local.t > 0)
				*inter = local;
		}
		local.i++;
	}
	return (res);
}

t_inter	cylinder_color(t_ray r, t_scene s, int nbRebonds)
{
	t_inter	inter;

	inter.t = 2147483647;
	if (cy_inter(r, s, &inter))
	{
		inter.color = s.cylinders[inter.i].color;
		inter.type = 3;
	}
	else
		inter.t = -1;
	return (inter);
}

