/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:01:07 by hekang            #+#    #+#             */
/*   Updated: 2021/01/14 10:01:40 by hekang           ###   ########.fr       */
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

//t_vec	*vec_unit_apply(t_vec *a)
//{
//	return (vec_div_const_apply(a, vec_length(a)));
//}
