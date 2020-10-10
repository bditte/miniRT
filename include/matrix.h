/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 20:46:35 by bditte            #+#    #+#             */
/*   Updated: 2020/10/10 13:45:32 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "camera.h"
typedef	struct		s_matrix
{
	t_vector	u;
	t_vector	v;
	t_vector	w;
	float		m11;
	float		m12;
	float		m21;
	float		m22;
	float		det;
	float		beta;
}					t_matrix;

void		get_camtoworld(t_cam cam, float m[4][4]);
t_vector	mult_vec_mat(t_vector v, float m[4][4]);
t_vector	mult_point_mat(t_vector v, float m[4][4]);
#endif
