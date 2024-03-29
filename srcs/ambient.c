/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 22:32:39 by hekang            #+#    #+#             */
/*   Updated: 2021/03/15 11:56:23 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ambient		*init_ambient(double ratio, t_vec *color)
{
	t_ambient	*result;

	result = (t_ambient *)ft_calloc(1, sizeof(t_ambient));
	result->ratio = ratio;
	result->color = color;
	return (result);
}
