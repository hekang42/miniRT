/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:36:52 by hekang            #+#    #+#             */
/*   Updated: 2021/02/16 16:52:34 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

t_vec 	*clamp_vec(t_vec *vec, double min, double max)
{
	if (vec->x < min)
		vec->x = min;
	else if (vec->x > max)
		vec->x = max;
	if (vec->y < min)
		vec->y = min;
	else if (vec->y > max)
		vec->y = max;
	if (vec->z < min)
		vec->z = min;
	else if (vec->z > max)
		vec->z = max;
	return (vec);
}