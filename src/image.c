#include "mlx.h"

void	ft_image(void *mlx_ptr, void *win_ptr)
{
	void *img_ptr;
	int bits_per_pixel;
	int size_line;
	int endian;

	bits_per_pixel = 3;
	size_line = 100;
	endian = 1;
	img_ptr = mlx_new_image(mlx_ptr, 100, 100);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
	mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
}
