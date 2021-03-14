/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:13:39 by hekang            #+#    #+#             */
/*   Updated: 2021/03/14 17:50:25 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	write_int(t_frame_saver *sv, unsigned int val)
{
	sv->buf[sv->index++] = val >> 0;
	sv->buf[sv->index++] = val >> 8;
	sv->buf[sv->index++] = val >> 16;
	sv->buf[sv->index++] = val >> 24;
}

void	write_file_header(t_frame_saver *sv)
{
	sv->buf[sv->index++] = 'B';
	sv->buf[sv->index++] = 'M';
	write_int(sv, sv->size);
	write_int(sv, 0x00000000);
	sv->buf[sv->index++] = 54;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 0;
}

void	write_file_info(t_img_data *img, t_frame_saver *sv)
{
	int				i;

	sv->buf[sv->index++] = 40;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 0;
	write_int(sv, img->width);
	write_int(sv, img->height);
	sv->buf[sv->index++] = 1;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 24;
	sv->buf[sv->index++] = 0;
	i = 0;
	while (i < 24)
	{
		sv->buf[sv->index++] = 0;
		i++;
	}
}

void	write_body(t_img_data *img, t_frame_saver *sv)
{
	int				x;
	int				y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			sv->buf[sv->index++] = img->img[x][y] >> 0;
			sv->buf[sv->index++] = img->img[x][y] >> 8;
			sv->buf[sv->index++] = img->img[x][y] >> 16;
			x++;
		}
		x = 0;
		while (x < (4 - (img->width * 3) % 4) % 4)
		{
			sv->buf[sv->index++] = 0;
			x++;
		}
		y++;
	}
}

int		save_first_frame(t_img_data *img, char *filename)
{
	int				fd;
	t_frame_saver	sv;

	sv = (t_frame_saver) { 0 };
	sv.size = 54 + 3 * img->width * img->height +
		((4 - (img->width * 3) % 4) % 4) * img->height;
	sv.buf = malloc(sv.size);
	if ((fd = open(filename, O_WRONLY | O_CREAT)) < 0)
		return (0);
	write_file_header(&sv);
	write_file_info(img, &sv);
	write_body(img, &sv);
	write(fd, sv.buf, sv.size);
	close(fd);
	return (1);
}
