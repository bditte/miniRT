/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:10:22 by bditte            #+#    #+#             */
/*   Updated: 2020/12/08 14:17:17 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISK_H
# define DISK_H

typedef	struct	s_disk
{
	t_vector	c;
	t_vector	n;
	float		r;
	t_vector	color;
}		t_disk;

#endif
