/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:36:50 by hekang            #+#    #+#             */
/*   Updated: 2021/03/14 18:46:58 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			free_object(t_hittable *obj)
{
	if (obj->obj_type == OBJ_SPHERE)
		free_sphere(obj->obj);
	if (obj->obj_type == OBJ_PLANE)
		free_plane(obj->obj);
	if (obj->obj_type == OBJ_SQUARE)
		free_square(obj->obj);
	if (obj->obj_type == OBJ_CYLINDER)
		free_cylinder(obj->obj);
	if (obj->obj_type == OBJ_TRIANGLE)
		free_triangle(obj->obj);
}

void			free_obj_list(t_list *list)
{
	while (list->content && list->next)
	{
		free_object(list->content);
		free(list->content);
		list = list->next;
	}
	free(list);
}

void			free_scene(t_scene *scene)
{
	printf("free_obj\n");
	free(scene->img->img);
	free(scene->img);
	printf("free_img\n");
	free_obj_list(scene->obj);
	printf("free_list\n");
	// free_cam_list(scene->cam);
	// printf("free_cam\n");
	// free_light_list(scene->light);
	// printf("free_light\n");
	free(scene->ambient->color);
	free(scene->ambient);
	free(scene);
}