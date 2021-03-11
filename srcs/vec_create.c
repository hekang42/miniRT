/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:55:14 by hekang            #+#    #+#             */
/*   Updated: 2021/03/11 12:01:43 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		*vec_create(double x, double y, double z)
{
	t_vec	*result;

	result = (t_vec *)malloc(sizeof(t_vec));
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}
