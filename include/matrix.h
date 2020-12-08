/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 20:46:35 by bditte            #+#    #+#             */
/*   Updated: 2020/11/17 16:27:35 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "camera.h"

void				get_camtoworld(t_cam cam, float m[4][4]);
t_vector			mult_point_mat(t_vector v, float m[4][4]);
t_vector			mult_vec_mat(t_vector v, float m[4][4]);
#endif
