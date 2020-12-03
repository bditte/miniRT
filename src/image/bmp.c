/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:10:38 by bditte            #+#    #+#             */
/*   Updated: 2020/12/01 15:10:14 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	bmp_fileheader(int fd, int padding, t_data *data)
{
	unsigned char	*header;
	int				size;

	if (!(header = ft_calloc(14, sizeof(char))))
		error(-3);
	size = 54 + data->height * (data->bpp / 8 * data->width + padding);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(size);
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
	free(header);
}

void	bmp_infoheader(int fd, t_data *data)
{
	unsigned char *header;

	if (!(header = ft_calloc(40, sizeof(char))))
		error(-3);
	header[0] = (unsigned char)(40);
	header[4] = (unsigned char)(data->width);
	header[5] = (unsigned char)(data->width >> 8);
	header[6] = (unsigned char)(data->width >> 16);
	header[7] = (unsigned char)(data->width >> 24);
	header[8] = (unsigned char)(data->height);
	header[9] = (unsigned char)(data->height >> 8);
	header[10] = (unsigned char)(data->height >> 16);
	header[11] = (unsigned char)(data->height >> 24);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(data->bpp);
	write(fd, header, 40);
	free(header);
}

int		save_bmp(t_data *data)
{
	int				i;
	int				padding_len;
	unsigned char	padding[3];
	int				fd;

	padding[0] = 0;
	padding[1] = 0;
	padding[2] = 0;
	padding_len = (4 - (data->width * data->bpp / 8) % 4) % 4;
	if (!(fd = open("bmp_save.bmp", O_CREAT | O_WRONLY, S_IRWXU)))
		error(-7);
	bmp_fileheader(fd, padding_len, data);
	bmp_infoheader(fd, data);
	i = data->height;
	while (i >= 0)
	{
		write(fd, data->addr + (data->width * i * data->bpp / 8)
					, data->line_length);
		write(fd, padding, padding_len);
		i--;
	}
	close(fd);
	return (1);
}
