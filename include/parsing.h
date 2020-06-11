#ifndef PARSING_H
# define PARSING_H

#include "miniRT.h"

typedef struct  s_data
{
        void *img;
        char *addr;
        int bits_per_pixel;
        int line_length;
        int endian;
        void *mlx;
        void *win;
        int     width;
        int     height;
}		t_data;

void    parse_cy(char *line, t_scene *scene);
void    parse_pl(char *line, t_scene *scene);
t_vector        convert_color(t_vector color);
float           ft_atof(char *str);
float           parse_float(char *line, int *i);
t_vector        parse_vec(char *line, int *i);
int     ft_iscoord(char c);
void    count_objects(char *file, t_scene *scene);
void    scene_init(t_scene *scene);
void    parse_sp(char *line, t_scene *data);
int     parse(int ac, char **av, t_scene *data);
void    parse_r(char *line, t_scene *data);
void    parse_tr(char *line, t_scene *scene);
# endif
