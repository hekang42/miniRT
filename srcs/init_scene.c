/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:12:51 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 16:59:04 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene			*init_scene(void)
{
	t_scene		*result;

	result = (t_scene *)ft_calloc(1, sizeof(t_scene));
	result->n_cam = 0;
	result->obj = init_list();
	result->cam = init_list();
	result->light = init_list();
	result->sepia = FALSE;
	result->anti = 0;
	result->resolution = 0;
	result->amb = 0;
	return (result);
}
