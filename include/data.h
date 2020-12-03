/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 23:24:39 by bditte            #+#    #+#             */
/*   Updated: 2020/11/17 16:11:16 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef	struct	s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			r;
	int			a;
}				t_data;
#endif
