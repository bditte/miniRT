/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 21:10:19 by bditte            #+#    #+#             */
/*   Updated: 2020/09/28 14:13:49 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "minirt.h"

t_inter		cylinder_color(t_scene s);
t_inter		plane_color(t_scene s);
t_inter		square_color(t_scene s);
int			pl_inter(t_scene s, t_inter *inter);
int			sp_inter(t_scene s, t_inter *inter);
t_vector	raytrace(t_scene s);
t_inter		triangle_color(t_scene s);
t_inter		sphere_color(t_scene s);
void		assign_inter(t_inter src, t_inter *dst);
t_inter		intersections(t_scene s);
t_ray		get_dir(t_scene s, float x, float y, t_cam cam);
#endif


