/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:38:04 by hekang            #+#    #+#             */
/*   Updated: 2021/03/15 13:07:47 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			free_cam(t_camera *cam)
{
	printf("cam origin %f\n", cam->origin->z);
	// if (cam->data)
	// {
		free_array((void **)cam->data->img);
		free(cam->data);
	// }
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
	while (list->content)
	{
		free_cam(list->content);
		list->content = NULL;
		free(list->content);
		if (list->next)
			list = list->next;
	}
	printf("free cam list\n");
	free(list);
}

void			free_light(t_light *light)
{
	free(light->color);
	free(light->origin);
}

void			free_light_list(t_list *list)
{
	while (list->content)
	{
		free_light(list->content);
		list->content = NULL;
		free(list->content);
		if (list->next)
			list = list->next;
	}
	free(list);
}
