/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 20:49:18 by bditte            #+#    #+#             */
/*   Updated: 2020/12/20 18:39:00 by bditte           ###   ########.fr       */
/*   Updated: 2020/11/30 18:40:05 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "plane.h"
# include "vector.h"
# include "sphere.h"
# include "triangle.h"
# include "cylinder.h"
# include "square.h"
# include "light.h"
# include "data.h"
# include "camera.h"
# include "disk.h"

typedef	struct	s_scene
{
	t_ray			r;
	t_cam			*cams;
	int				nbcams;
	int				current_cam;
	t_square		*squares;
	int				nbsquares;
	t_cylinder		*cylinders;
	int				nbcylinders;
	t_sphere		*spheres;
	int				nbspheres;
	t_plane			*planes;
	int				nbplanes;
	t_triangle		*triangles;
	int				nbtriangles;
	t_disk			*disks;
	int				nbdisks;
	t_light			*lights;
	int				nblights;
	t_vector		l_position;
	int				l_int;
	float			ambient_int;
	t_vector		ambient_color;
	t_data			data;
	int				save_bmp;
	int				anti_aliasing;
}				t_scene;
#endif
