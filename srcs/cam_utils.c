/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:26:06 by hekang            #+#    #+#             */
/*   Updated: 2021/03/15 16:12:34 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void			camlst_add(t_scene *scene, t_camera *cam)
// {
// 	t_list		*begin;
// 	int			cnt;

// 	cnt = scene->n_cam;
// 	begin = scene->cam;
// 	if (scene->cam->content)
// 	{
// 		while (cnt--)
// 			scene->cam = scene->cam->next;
// 		scene->cam->next = init_list();
// 		scene->cam->next->content = cam;
// 		scene->cam->next->next = begin;
// 	}
// 	else
// 	{
// 		scene->cam->content = cam;
// 		scene->cam->next = scene->cam;
// 	}
// 	cam->data = create_img_data(scene->img->width, scene->img->height);
// 	scene->cam = begin;
// }

void			camlst_add(t_scene *scene, t_list *lst, t_camera *cam)
{
	if (lst->content)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = init_list();
		lst = lst->next;
	}
	lst->content = cam;

	((t_camera *)(lst->content))->data = create_img_data(scene->img->width, scene->img->height);
}

void			set_camera_llc(t_camera *cam, t_vec *lookat)
{
	t_vec		*tmp;

	vec_div_const_apply(cam->horizontal, 2.0);
	vec_div_const_apply(cam->vertical, 2.0);
	tmp = vec_add(cam->horizontal, cam->vertical);
	vec_add_apply(tmp, lookat);
	cam->lower_left_corner = vec_sub(cam->origin, tmp);
	free(tmp);
	vec_mul_const_apply(cam->horizontal, 2.0);
	vec_mul_const_apply(cam->vertical, 2.0);
}

t_camera		*init_cam(t_scene *scene, t_vec *lookfrom,
	t_vec *lookat, double hfov)
{
	t_camera	*result;
	double		view_h;
	double		view_w;
	t_vec		*vup;

	lookat = vec_unit(vec_mul_const_apply(lookat, -1.0));
	vup = vec_create(0, 1, 0);
	if (vec_is_parallel(vup, lookat))
	{
		free(vup);
		vup = vec_create(1, 0, 0);
	}

	result = (t_camera *)ft_calloc(1, sizeof(t_camera));
	result->fov = hfov;
	view_w = 2 * tan(hfov / 2.0);
	view_h = view_w / (scene->img->width) * scene->img->height;
	result->horizontal = vec_unit(vec_cross(vup, lookat));
	free(vup);
	result->vertical = vec_mul_const_apply(
							vec_cross(lookat, result->horizontal), view_h);
	vec_mul_const_apply(result->horizontal, view_w);
	result->origin = lookfrom;
	set_camera_llc(result, lookat);
	free(lookat);
	return (result);
}
