#include "minirt.h"
/*
t_vector	transparent(t_scene s, t_vector p, t_vector n)
{
	t_vector direction_refract;
	t_vector transparent_n = n;
	t_vector i_pixel;
	float n1 = 1;
	float n2 = 1.3;
	t_vector tangent;
	float radical;
	t_vector offset;

	vec_display(r.dir);
	i_pixel = vec_init(0,0,0);
	if (dot(r.dir, n) > 0)
	{
		n1 = 1.3;
		n2 = 1;
		transparent_n = vec_multiply_t(-1.0, n);
	}
	radical = 1-sqr(n1/n2)*(1-sqr(dot(transparent_n, r.dir)));
	if (radical > 0)
	{
		tangent = vec_multiply_t((n1/n2), (vec_sub(r.dir,vec_multiply_t(dot(r.dir, transparent_n), transparent_n))));
		offset = vec_multiply_t(0.01, transparent_n);
		direction_refract = vec_sub(tangent, vec_multiply_t(sqrt(radical),transparent_n));
		r = ray_init(vec_add(p, offset), direction_refract);
		i_pixel = raytrace(r, s);
		
	}
	return (i_pixel);
}
*/
float   hit_sp(t_sphere s, t_ray r, t_inter *local)
{
        t_vector oc;
        float a;
        float b;
        float c;
        float discriminant;
        float t;
        float t1;
        float t2;

        oc = vec_sub(r.o, s.c);
        a = 1;
        b = 2.0 * dot(r.dir, oc);
        c = getnorme2(oc) - s.r * s.r;
        discriminant = b*b - 4*a*c;
        t1 = ((b * -1) - sqrt(discriminant)) / (2*a);
        t2 = ((b * -1) + sqrt(discriminant)) / (2*a);

        if (discriminant < 0)
                return (-1.0);
        if (t2 < 0)
                return (-1.0);
        if (t1 > 0)
                t = t1;
        else
                t = t2;
        local->p = vec_add(r.o, vec_multiply_t(t, r.dir));
        local->n = vec_normalize(vec_sub(local->p, s.c));
        return (t);
}

int     sp_inter(t_scene s, t_inter *inter)
{
        t_inter local;
        int	has_inter;

        local.i = 0;
        has_inter = 0;
        while (local.i < s.nbspheres)
        {
                local.t = hit_sp(s.spheres[local.i], s.r, &local);
                if (local.t > 0.0)
                {
                        has_inter = 1;
                        if (local.t < inter->t || inter->t == -1)
                                *inter = local;
                }
                local.i++;
        }
        return (has_inter);
}

t_inter	sphere_color(t_scene s)
{
	t_inter	 inter;
	int has_inter;

	inter.t = -1;
        has_inter = sp_inter(s, &inter);
	if (has_inter)
        {

            /*    if (s.spheres[i].mirror == 1)
                {
                        t_vector direction_miroir;

                        offset = vec_multiply_t(0.01, n);
                        direction_miroir = vec_sub(r.dir, vec_multiply_t(2 *dot(n, r.dir), n));
                        r = ray_init(vec_add(p, offset), direction_miroir);
                        i_pixel = get_color(r, s, nbRebonds - 1);
                }
                else if (s.spheres[i].transparent == 1)
                        i_pixel = transparent(r, s, p, n, nbRebonds);
		else*/
		inter.color = s.spheres[inter.i].albedo;//i_pixel = lighting(r, s, inter);
               	inter.type = 0;
		inter.point = s.spheres[inter.i].c;
        }
	else
		inter.t  = -1;
        return (inter);

}
