/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc_apply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:01:07 by hekang            #+#    #+#             */
/*   Updated: 2021/03/11 13:43:33 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	*vec_add_apply(t_vec *a, t_vec *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	return (a);
}

t_vec	*vec_sub_apply(t_vec *a, t_vec *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
	return (a);
}

t_vec	*vec_mul_const_apply(t_vec *a, double c)
{
	a->x *= c;
	a->y *= c;
	a->z *= c;
	return (a);
}

t_vec	*vec_div_const_apply(t_vec *a, double c)
{
	a->x /= c;
	a->y /= c;
	a->z /= c;
	return (a);
}

int		vec_is_parallel(t_vec *a, t_vec *b)
{
	double	dot;
	double	length;

	dot = vec_dot(a, b);
	dot = ((dot < 0) ? (-1 * dot) : dot);
	length = vec_len(a) * vec_len(b);
	return ((dot == length) ? TRUE : FALSE);
}
