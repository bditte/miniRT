/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 21:14:39 by bditte            #+#    #+#             */
/*   Updated: 2020/11/23 16:05:05 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int				get_fd(int ac, char **av, t_scene *s);
int				ft_iscoord(char c);
int				ft_isint(char *s);
int				ft_isfloat(char *s);
int				ft_iscolor(char *s);
int				ft_isvec(char *s);
void			ft_free(char **tab);
void			count_objects(int fd, t_scene *scene);
void			scene_init(t_scene *scene);
void			parse_sp(char **line, t_scene *data);
int				parse(int ac, char **av, t_scene *data);
void			parse_r(char **line, t_scene *data);
void			parse_l(char **line, t_scene *scene);
void			parse_a(char **line, t_scene *scene);
void			parse_c(char **line, t_scene *scene);
void			parse_tr(char **line, t_scene *scene);
void			parse_cy(char **line, t_scene *scene);
void			parse_sq(char **line, t_scene *scene);
void			parse_pl(char **line, t_scene *scene);
t_vector		parse_vec(char *line);
t_vector		conv_color(t_vector color);
float			ft_atof(char *str);
int				nb_elem(char **line);
int				check_id(char *l);
void			set_to_zero(t_scene *scene);
#endif
