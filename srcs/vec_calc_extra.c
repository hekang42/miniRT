/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:01:34 by hekang            #+#    #+#             */
/*   Updated: 2021/02/08 16:20:36 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double      vec_dot(t_vec *u, t_vec *v)
{
    return (u->x * v->x + u->y * v->y + u->z * v->z);
}

t_vec       *vec_cross(t_vec *u, t_vec *v)
{
    t_vec   *result;

    result = (t_vec *)malloc(sizeof(t_vec));
    result->x = u->y * v->z - u->z * v->y;
    result->y = u->z * v->x - u->x * v->z;
    result->z = u->x * v->y - u->y * v->x;
    return (result);
}

double      vec_len(t_vec *u)
{
    return (sqrt(vec_len_sqrt(u)));
}

double      vec_len_sqrt(t_vec *u)
{
    return (pow(u->x, 2.0) + pow(u->y, 2.0) + pow(u->z, 2.0));
}

double	vec_length(t_vec *a)
{
	return (sqrt(vec_len_sqrt(a)));
}

t_vec       *vec_unit(t_vec *u)
{
    t_vec   *result;

    result = (t_vec *)malloc(sizeof(t_vec));
    result = vec_div_const(u, vec_len(u));
    return (result);
}
int			vec_is_parallel(t_vec *a, t_vec *b)
{
	double	dot;
	double	length;

	dot = vec_dot(a, b);
	dot = ((dot < 0) ? (-1 * dot) : dot);
	length = vec_length(a) * vec_length(b);
	return ((dot == length) ? TRUE : FALSE);
}