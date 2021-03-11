/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:35:12 by hekang            #+#    #+#             */
/*   Updated: 2021/03/11 14:05:51 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane			*init_plane(t_vec *p, t_vec *normal, t_vec *color)
{
	t_plane		*result;

	result = (t_plane *)malloc(sizeof(t_plane));
	result->p = p;
	result->normal = normal;
	result->color = color;
	return (result);
}

int				plane_hit(void *obj, t_ray *r, t_hit_record *rec)
{
	double		denominator;
	t_plane		*pl;
	t_vec		*oc;
	double		t;

	pl = ((t_plane *)obj);
	denominator = vec_dot(pl->normal, r->dir);
	if (fabs(denominator) < 0.000001)
		return (FALSE);
	oc = vec_sub(pl->p, r->orig);
	t = vec_dot(oc, pl->normal) / denominator;
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(r, t);
	rec->p = vec_add(rec->p, vec_mul_const(pl->normal, 0.000001));
	rec->normal = vec_unit(pl->normal);
	rec->color = vec_create(pl->color->x, pl->color->y, pl->color->z);
	return (TRUE);
}
