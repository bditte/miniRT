#ifndef SCENE_H
# define SCENE_H

# include "plane.h"
# include "vector.h"
# include "sphere.h"
# include "triangle.h"
# include "cylinder.h"

typedef struct  s_scene
{
	t_cylinder	*cylinders;
	int		nbCylinders;
        t_sphere        *spheres;
        int             nbSpheres;
        t_plane         *planes;
        int             nbPlanes;
	t_triangle	*triangles;
	int		nbTriangles;
        t_vector        l_position;
        int             l_int;
        int             width;
        int             height;
}               t_scene;

# endif
