#include "miniRT.h"

int	hit_tr(t_ray r, t_triangle triangle, t_inter *inter)
{
	float	t;
	t_matrix a;
	t_matrix b;
	t_matrix c;
	
	inter->n = vec_normalize(cross(vec_sub(triangle.b, triangle.a), vec_sub(triangle.c, triangle.a)));
/*	printf("n : ");
	vec_display(inter->n);
*/	t = dot(vec_sub(triangle.c, r.dir), inter->n) / dot(r.dir, inter->n);
	if (t < 0)
		return (-1);
	inter->p = vec_add(r.o, vec_multiply_t(t, r.dir));
	a.u = vec_sub(triangle.b, triangle.a);
	a.v = vec_sub(triangle.c, triangle.a);
	a.w = vec_sub(inter->p, triangle.a);
	a.m11 = getNorme2(a.u);
	a.m12 = dot(a.u, a.v);
	a.m22 = getNorme2(a.v);
	a.det = a.m11 * a.m22 - a.m12 * a.m12;
	b.m11 = dot(a.w, a.u);
	b.m21 = dot(a.w, a.v);
	b.det = b.m11 * a.m22 - b.m21*a.m12;
	b.beta = b.det / a.det;
	c.m12 = b.m11;
	c.m22 = b.m21;
	c.det = a.m11*c.m22 - a.m12*c.m12;
	c.beta = c.det / a.det;
	a.beta = 1 - b.beta - c.beta;
	if (a.beta < 0 || b.beta < 0 || c.beta < 0)
		return (-1);
	if (a.beta > 1 || b.beta > 1 || c.beta > 1)
		return (-1);	
	inter->t = t;
	return (1);
}

int	tr_inter(t_ray r, t_scene s, t_inter *inter)
{
	int res;
	t_inter local;

	res = 0;
	local.i = 0;
	while (local.i < s.nbTriangles)
	{
		if (hit_tr(r, s.triangles[local.i], &local) == 1)
		{
			res = 1;
			if (local.t < inter->t);
				*inter = local;
		}
		local.i++;
	}
	return (res);
}

t_inter		triangle_color(t_ray r, t_scene s, int nbRebonds)
{
	t_inter		inter;

	inter.t = 2147483647;	
	if (tr_inter(r, s, &inter))
	{
		inter.color = s.triangles[inter.i].color;//result = lighting(r, s, inter);//s.triangles[inter.i].color;
		inter.type = 2;
	}
	else
		inter.t = -1;
	return (inter);
}
