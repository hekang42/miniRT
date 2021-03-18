/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:33:43 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 15:40:13 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list		*init_list(void)
{
	t_list	*result;

	result = (t_list *)ft_calloc(1, sizeof(t_list));
	result->content = NULL;
	result->next = NULL;
	return (result);
}

void		lightlst_add(t_list *lst, t_vec *ori, double ratio, t_vec *color)
{
	if (lst->content)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = init_list();
		lst = lst->next;
	}
	lst->content = init_light(ori, ratio, color);
}

t_light		*init_light(t_vec *ori, double ratio, t_vec *color)
{
	t_light	*result;

	result = (t_light *)ft_calloc(1, sizeof(t_light));
	result->origin = ori;
	result->ratio = ratio;
	result->color = color;
	return (result);
}
