#include "miniRT.h"

t_inter         intersections(t_ray r, t_scene s, int nbRebonds)
{
        float           t;
        t_inter         res;
        t_inter         last_inter;

      	res.t = 1000000000;
	res.type = -1;
        if (s.nbSpheres > 0)
        {       last_inter = sphere_color(r, s, nbRebonds);
		if (last_inter.t > 0)
                        res = last_inter;
        }
	if (s.nbPlanes > 0)
        {
                last_inter = plane_color(r, s, nbRebonds);
                if (last_inter.t < res.t && last_inter.t > 0)
			res = last_inter;
        }
	if (s.nbTriangles > 0)
        {
                last_inter = triangle_color(r, s, nbRebonds);
                if (last_inter.t < res.t && last_inter.t > 0)
                        res = last_inter;
        }
	if (s.nbCylinders > 0)
	{
		last_inter = cylinder_color(r, s, nbRebonds);
		if (last_inter.t < res.t && last_inter.t > 0)
			res = last_inter;
	}
        return (res);
}

t_vector        get_color(t_ray r, t_scene s, int nbRebonds)
{
        t_vector color;
        t_inter inter;
        inter = intersections(r, s, nbRebonds);
	if (inter.t > 0)
        {
                return(lighting(r, s, inter));
        }
}

