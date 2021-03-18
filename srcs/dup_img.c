/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:10:37 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 19:59:28 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				**create_img(int width, int height)
{
	int			**result;
	int			w;
	int			h;

	w = -1;
	result = (int **)ft_calloc(width, sizeof(int *));
	while (++w < width)
	{
		result[w] = (int *)ft_calloc(height, sizeof(int));
		h = -1;
		while (++h < height)
			result[w][h] = 0;
	}
	return (result);
}

static void		init_img(t_scene *scene, t_img_data *img)
{
	int x;
	int y;

	y = scene->img->height;
	while (--y >= 0)
	{
		x = -1;
		while (++x < scene->img->width)
			img->img[x][y] = ((t_camera *)(scene->cam->content))
				->data->img[x][y];
	}
}

void			create_img_lst(t_img_data *img, t_list **lst, t_list *begin)
{
	if ((*lst)->content)
	{
		(*lst)->next = init_list();
		(*lst)->next->content = img;
		(*lst)->next->next = begin;
		(*lst) = (*lst)->next;
	}
	else
	{
		(*lst)->content = img;
		(*lst)->next = (*lst);
	}
}

t_list			*dup_img(t_scene *scene)
{
	t_list		*lst;
	t_list		*begin;
	t_img_data	*img;
	t_list		*cam_begin;

	lst = init_list();
	begin = lst;
	cam_begin = scene->cam;
	while (scene->n_cam--)
	{
		img = create_img_data(scene->img->width, scene->img->height);
		init_img(scene, img);
		create_img_lst(img, &lst, begin);
		scene->cam = scene->cam->next;
	}
	scene->cam = cam_begin;
	lst = lst->next;
	return (lst);
}
