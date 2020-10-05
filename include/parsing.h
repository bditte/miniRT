/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 21:14:39 by bditte            #+#    #+#             */
/*   Updated: 2020/06/25 19:22:23 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int				get_fd(int ac, char **av, t_scene *s);
void			parse_cy(char *line, t_scene *scene);
void			parse_sq(char *line, t_scene *scene);
void			parse_pl(char *line, t_scene *scene);
t_vector		conv_color(t_vector color);
float			ft_atof(char *str);
float			parse_float(char *l, int *i);
t_vector		parse_vec(char *line, int *i);
int				ft_iscoord(char c);
int				ft_isdigit(char c);
int			parse_int(char *line, int *i);
void			count_objects(char *file, t_scene *scene);
void			scene_init(t_scene *scene);
void			parse_sp(char *line, t_scene *data);
int				parse(int ac, char **av, t_scene *data);
void			parse_r(char *line, t_scene *data);
void			parse_l(char *line, t_scene *scene);
void			parse_a(char *line, t_scene *scene);
void			parse_tr(char *line, t_scene *scene);
void			parse_c(char *line, t_scene *scene);
#endif
