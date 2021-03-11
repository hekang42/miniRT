/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:13:39 by hekang            #+#    #+#             */
/*   Updated: 2021/03/11 09:41:50 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    write_int(t_frame_saver *sv, unsigned int val)
{
    sv->buf[sv->index++] = val >> 0;
    sv->buf[sv->index++] = val >> 8;
    sv->buf[sv->index++] = val >> 16;
    sv->buf[sv->index++] = val >> 24;
}
/*
** file header
**
** "BM" (2o)
** file size (4o)
** null (2o)
** null (2o)
** 54,0,0,0 (4o)
*/
void    write_file_header(t_frame_saver *sv)
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

void	write_file_info(t_scene *s, t_frame_saver *sv)
{
	int i;

	sv->buf[sv->index++] = 40;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 0;
	write_int(sv, s->img->width);
	write_int(sv, s->img->height);
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

void	write_body(t_scene *s, t_frame_saver *sv)
{
	int x;
	int y;
	t_img_data *img;

    img = ((t_camera *)(s->cam->content))->data;
	// y = img->height - 1;
	y = 0;
	// while (y >= 0)
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
		// y--;
		y++;
	}
}

int		save_first_frame(t_scene *s, char *filename)
{
	int				fd;
	t_frame_saver	sv;

	// render(s);
	sv = (t_frame_saver) { 0 };
	sv.size = 54 + 3 * s->img->width * s->img->height +
		((4 - (s->img->width * 3) % 4) % 4) * s->img->height;
	sv.buf = malloc(sv.size);
	if ((fd = open(filename, O_WRONLY | O_CREAT)) < 0)
		return (0);
	write_file_header(&sv);
	write_file_info(s, &sv);
	printf("1\n");
	write_body(s, &sv);
	printf("2\n");
	write(fd, sv.buf, sv.size);
	printf("3\n");
	close(fd);
	return (1);
}