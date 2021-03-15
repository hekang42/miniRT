/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:38:04 by hekang            #+#    #+#             */
/*   Updated: 2021/03/15 16:41:59 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			free_cam(t_camera *cam)
{
	printf("cam origin %f\n", cam->origin->z);
	free_array((void **)cam->data->img);
	printf("cam origin %f\n", cam->origin->z);
		free(cam->data);
	// cam->data = NULL;
	// if (cam->horizontal)
		free(cam->horizontal);
	// if (cam->lower_left_corner)
		free(cam->lower_left_corner);
	// if (cam->origin)
		free(cam->origin);
	// if (cam->vertical)
		free(cam->vertical);
	printf("free cam\n");
}

void			free_cam_list(t_list *list)
{
	t_list		*tmp;

	while (list->content)
	{
		free_cam(list->content);
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

void			free_light(t_light *light)
{
	free(light->color);
	free(light->origin);
}

void			free_light_list(t_list *list)
{
	t_list		*tmp;


	while (list->content)
	{
		printf("ligghgghght\n");
		free_light(list->content);
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
