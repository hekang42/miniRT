/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:03:31 by hekang            #+#    #+#             */
/*   Updated: 2021/03/11 12:02:01 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		*vec_add(t_vec *a, t_vec *b)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = a->x + b->x;
	result->y = a->y + b->y;
	result->z = a->z + b->z;
	return (result);
}

t_vec		*vec_sub(t_vec *a, t_vec *b)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = a->x - b->x;
	result->y = a->y - b->y;
	result->z = a->z - b->z;
	return (result);
}

t_vec		*vec_mul_const(t_vec *a, double c)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = a->x * c;
	result->y = a->y * c;
	result->z = a->z * c;
	return (result);
}

t_vec		*vec_div_const(t_vec *a, double c)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = (double)(a->x / c);
	result->y = (double)(a->y / c);
	result->z = (double)(a->z / c);
	return (result);
}

t_vec		*vec_mul_each(t_vec *a, t_vec *b)
{
	t_vec	*result;

	result = (t_vec *)malloc(sizeof(t_vec));
	result->x = (double)a->x * (double)b->x;
	result->y = (double)a->y * (double)b->y;
	result->z = (double)a->z * (double)b->z;
	return (result);
}
