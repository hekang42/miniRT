/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:38:04 by hekang            #+#    #+#             */
/*   Updated: 2021/03/14 18:38:29 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			free_cam(t_camera *cam)
{
	if (cam->data)
	{
		free(cam->data->img);
		free(cam->data);
	}
	if (cam->horizontal)
		free(cam->horizontal);
	if (cam->lower_left_corner)
		free(cam->lower_left_corner);
	if (cam->normal)
		free(cam->normal);
	if (cam->origin)
		free(cam->origin);
	if (cam->vertical)
		free(cam->vertical);
}

void			free_cam_list(t_list *list)
{
	while (list->content && list->next)
	{
		free_cam(list->content);
		list->content = NULL;
		free(list->content);
		list = list->next;
	}
	printf("free cam list\n");
	// free_cam(list->content);
	free(list);
}

void			free_light(t_light *light)
{
	printf("color : %f \n", light->color->x);
	printf("origin : %f \n", light->origin->x);
	if (light->color)
		free(light->color);
	if (light->origin)
		free(light->origin);
}

void			free_light_list(t_list *list)
{
	while (list->content && list->next)
	{
		printf("start light list\n");
		free_light(list->content);
		printf("13\n");
		list->content = NULL;
		printf("14\n");
		free(list->content);
		list = list->next;
	}
	free(list);
}
