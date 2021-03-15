/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:33:21 by hekang            #+#    #+#             */
/*   Updated: 2021/03/15 13:31:54 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		mlx_draw_by_img_data(t_mlx_data *mlx_data, t_img_data *img_data)
{
	int		width;
	int		height;
	char	*dst;
	int		next;

	width = -1;
	while ((++width) < img_data->width)
	{
		height = -1;
		while ((++height) < img_data->height)
		{
			next = (img_data->height - height - 1) * mlx_data->line_length;
			next += width * (mlx_data->bits_per_pixel / 8);
			dst = mlx_data->addr + next;
			*(unsigned int*)dst = img_data->img[width][height];
		}
	}
}

void		mlx_show(t_vars vars, t_mlx_data *img, t_img_data *data)
{
	mlx_draw_by_img_data(img, data);
	mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
}

/*
**	mlx_get_data_addr()은 생성된 이미지에 대한 정보를 반환하며, 나중에 사용자가 수정할 수 있습니다.
**	img_ptr 파라미터는 사용할 이미지를 지정합니다. 다음 3개의 파리미터는 3개의 서로 다른 유효한 정수의 주소입니다.
**	bits_per_pixel은 픽셀의 색상을 표현하는데 필요한 비트의 수로 채워집니다
**	(색 깊이(depth of the image)라고도 불립니다).
**	size_line은 메모리 안에서 이미지 한 줄을 저장하는데 필요한 바이트의 수입니다.
**	이 정보는 이미지의 한 줄에서 다른 줄로 이동하는데 사용합니다. endian은 이미지의
**	픽셀 색상을 little (endian == 0) 또는 big (endian == 1)에 저장해야하는지 여부를 의미합니다.
*/
