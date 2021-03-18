/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hittable_anti.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:33:09 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 19:57:00 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			insert_color(t_scene *scene, int y, t_draw_var var)
{
	t_hit_record	*rec;
	t_vec			color;
	int				cal;

	var.x = -1;
	while ((++var.x) < scene->img->width)
	{
		var.anti = 0;
		color = (t_vec){0, 0, 0};
		while (var.anti++ < scene->anti)
		{
			var.u = (double)(var.x + ft_random()) / (scene->img->width - 1);
			var.v = (double)(y + ft_random()) / (scene->img->height - 1);
			rec = hit_record_new();
			rec->ray = camera_get_ray(scene->cam->content, var.u, var.v);
			cal = cal_hittable_color(scene, rec);
			color.x += cal >> 16;
			color.y += cal >> 8 & 0b11111111;
			color.z += cal & 0b11111111;
			free_hit_record(rec, 0);
		}
		((t_camera *)(scene->cam->content))->data->img[var.x][y] =
			((int)(color.x / scene->anti) << 16) | ((int)(color.y /
			scene->anti) << 8) | (int)(color.z / scene->anti);
	}
}

void				draw_hittable_anti(t_scene *scene)
{
	t_draw_var		var;
	t_list			*cam_begin;

	var.n = 0;
	var.y = scene->img->height;
	cam_begin = scene->cam;
	while (var.n < scene->n_cam)
	{
		var.y = scene->img->height;
		while ((--var.y) >= 0)
			insert_color(scene, var.y, var);
		scene->cam = scene->cam->next;
		var.y = scene->img->height;
		var.n++;
	}
	scene->cam = cam_begin;
}
