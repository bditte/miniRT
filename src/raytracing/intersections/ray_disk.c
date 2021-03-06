/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_disk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:22:52 by bditte            #+#    #+#             */
/*   Updated: 2020/12/16 19:16:00 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hit_ds(t_ray r, t_disk ds, t_inter *inter)
{
	t_plane		pl;
	t_vector	pc;

	pl.n = ds.n;
	pl.c = ds.c;
	if (!hit_pl(pl, r, inter))
		return (0);
	pc = vec_sub(inter->p, ds.c);
	if ((sqrt(getnorme2(pc)) > ds.r))
		return (0);
	return (1);
}

int	ds_inter(t_scene s, t_inter *inter)
{
	t_inter		local_inter;
	int		has_inter;
	
	has_inter = 0;
	local_inter.i = 0;
	while (local_inter.i < s.nbdisks)
	{
		if (hit_ds(s.r, s.disks[local_inter.i], &local_inter))
		{
			has_inter = 1;
			if (local_inter.t < inter->t || inter->t == -1)
				*inter = local_inter;
		}
		local_inter.i++;
	}
	return (has_inter);
}

t_inter	ray_disk(t_scene s)
{
	t_inter	inter;

	inter.t = -1;
	if (ds_inter(s, &inter))
	{
		inter.color = s.disks[inter.i].color;
		inter.type = DISK;
	}
	return (inter);
	
}
