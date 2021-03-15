/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hittable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:18:41 by hekang            #+#    #+#             */
/*   Updated: 2021/03/15 10:41:06 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int					cal_hittable_color(t_scene *scene, t_hit_record *rec)
{
	int				result;

	result = 0;
	if (hitlst_hit(scene->obj, rec))
		result = lightlst_hit(scene, scene->light, rec);
	return (result);
}

t_ray				*camera_get_ray(t_camera *cam, double u, double v)
{
	t_vec			*tmp;
	t_vec			*tmp2;

	tmp2 = vec_mul_const(cam->horizontal, u);
	tmp = vec_add(cam->lower_left_corner, tmp2);
	free(tmp2);
	tmp2 = vec_mul_const(cam->vertical, v);
	vec_add_apply(tmp, tmp2);
	free(tmp2);
	vec_sub_apply(tmp, cam->origin);
	return (create_ray(cam->origin, tmp));
}

void				draw_hittable(t_scene *scene)
{
	t_hit_record	*rec;
	t_draw_var		var;
	t_list			*cam_begin;

	var.n = 0;
	var.y = scene->img->height;
	cam_begin = scene->cam;
	while (var.n < scene->n_cam)
	{
		while ((--var.y) >= 0)
		{
			var.x = -1;
			while ((++var.x) < scene->img->width)
			{
				var.u = (double)var.x / (scene->img->width - 1);
				var.v = (double)var.y / (scene->img->height - 1);
				rec = hit_record_new();
				rec->ray = camera_get_ray(scene->cam->content, var.u, var.v);
				((t_camera *)(scene->cam->content))->data->img[var.x][var.y] =
					cal_hittable_color(scene, rec);
				free_hit_record(rec);
			}
		}
		scene->cam = scene->cam->next;
		var.y = scene->img->height;
		var.n++;
	}
	scene->cam = cam_begin;
}
