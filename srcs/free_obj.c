/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:36:50 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 14:54:42 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			free_object(t_hittable *obj)
{
	if (obj->obj_type == OBJ_SPHERE || obj->obj_type == OBJ_SPHERE_CHECKER
		|| obj->obj_type == OBJ_SPHERE_RAINBOW)
		free_sphere(obj->obj);
	if (obj->obj_type == OBJ_PLANE)
		free_plane(obj->obj);
	if (obj->obj_type == OBJ_SQUARE || obj->obj_type == OBJ_SQUARE_CHECKER)
		free_square(obj->obj);
	if (obj->obj_type == OBJ_CYLINDER || obj->obj_type == OBJ_CYLINDER_RAINBOW
										|| obj->obj_type == OBJ_CONE)
		free_cylinder(obj->obj);
	if (obj->obj_type == OBJ_TRIANGLE)
		free_triangle(obj->obj);
}

void			free_obj_list(t_list *list)
{
	t_list		*tmp;

	while (list->content)
	{
		free_object(list->content);
		free(list->content);
		list->content = NULL;
		if (list->next)
		{
			tmp = list->next;
			free(list);
			list = tmp;
		}
	}
	free(list);
}

void			free_scene(t_scene *scene)
{
	free_cam_list(scene->cam);
	free(scene->ambient->color);
	free(scene->ambient);
	free_light_list(scene->light);
	free_obj_list(scene->obj);
	free(scene->img);
	free(scene);
}
