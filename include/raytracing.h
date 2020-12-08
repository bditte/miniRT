/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 21:10:19 by bditte            #+#    #+#             */
/*   Updated: 2020/12/08 14:26:58 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "minirt.h"

t_inter		ray_cylinder(t_scene s);
t_inter		ray_plane(t_scene s);
t_inter		ray_square(t_scene s);
t_inter		ray_triangle(t_scene s);
t_inter		ray_sphere(t_scene s);
t_inter		ray_disk(t_scene s);
t_vector	trace_ray(t_scene s);
t_inter		intersections(t_scene s);
void		display(t_scene *s);
t_vector	get_dir(t_scene s, float x, float y, t_cam cam);
t_vector	get_color(t_scene s, t_inter inter);
#endif
