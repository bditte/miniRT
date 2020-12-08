/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:01:37 by bditte            #+#    #+#             */
/*   Updated: 2020/12/01 16:48:32 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_scene(t_scene *s)
{
	if (s->nblights > 0)
		free(s->lights);
	if (s->nbtriangles > 0)
		free(s->triangles);
	if (s->nbplanes > 0)
		free(s->planes);
	if (s->nbspheres > 0)
		free(s->spheres);
	if (s->nbcylinders > 0)
		free(s->cylinders);
	if (s->nbsquares > 0)
		free(s->squares);
	if (s->nbcams > 0)
		free(s->cams);
}
