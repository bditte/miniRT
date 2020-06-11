#include "miniRT.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_window(int keycode, t_data *vars)
{
	if (keycode == 65307)	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}

int main(int ac, char **av)
{
	int height;
	int width;
	t_data data;
	int offset;
	t_vector pixel;
	int x;
	int y;
	int i;
	float u;
	float v;
	float intensite;
	t_vector origin;
	t_vector direction;
	t_vector horizontal;
	t_vector vertical;
	t_vector lower_left_corner;
	t_vector color;
	t_vector position_lumiere;
	t_ray	r;
	t_sphere	s;
	t_scene		scene;
	t_sphere list[7];
	t_plane		plane;
	
	parse(ac, av, &scene);
	i = 0;
	origin = vec_init(0, 0, 0);
	data.height = 500;
	data.width = 500;
	double fov;
	fov = 60 * PI / 180;
	scene.l_int = 100000000;
	scene.l_position = vec_init(0, 100, -40);
	
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.width, data.height, "Window");
	data.img = mlx_new_image(data.mlx, data.width, data.height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0,0);
	y = 0;
	while (y < data.height)
	{
		x = 0;
		while (x < data.width)
		{
			direction = vec_create(x-data.width/2, y-data.height/2, (data.width * -1)/(2*tan(fov/2)));
			r = ray_init(origin, vec_normalize(direction));
			i = 0;
			t_vector i_pixel;
			i_pixel = get_color(r, scene, 6);
			pixel.x = (int)ft_min(255, ft_max(0, pow(i_pixel.x, 1/2.2)));
			pixel.y = (int)ft_min(255, ft_max(0, pow(i_pixel.y, 1/2.2)));
			pixel.z = (int)ft_min(255, ft_max(0, pow(i_pixel.z, 1/2.2)));
			my_pixel_put(&data, x, data.height - y - 1, create_rgb(pixel));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0,0);
	mlx_hook(data.win, 2,1L<<0,close_window, &data);
	mlx_hook(data.win, 17,1L<<17,exit, 1);
	mlx_loop(data.mlx);
}
