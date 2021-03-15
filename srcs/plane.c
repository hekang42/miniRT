/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:35:12 by hekang            #+#    #+#             */
/*   Updated: 2021/03/15 17:20:08 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane			*init_plane(t_vec *p, t_vec *normal, t_vec *color)
{
	t_plane		*result;

	result = (t_plane *)ft_calloc(1, sizeof(t_plane));
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
	t_vec		*tmp;

	pl = ((t_plane *)obj);
	denominator = vec_dot(pl->normal, r->dir);
	if (fabs(denominator) < 0.000001)
		return (FALSE);
	oc = vec_sub(pl->p, r->orig);
	t = vec_dot(oc, pl->normal) / denominator;
	free(oc);
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	if (rec->p)
		free(rec->p);
	if (rec->normal)
		free(rec->normal);
	rec->t = t;
	rec->p = ray_at(r, t);
	tmp = vec_mul_const(pl->normal, 0.000001);
	rec->p = vec_add_apply(rec->p, tmp);
	free(tmp);
	rec->normal = vec_create(pl->normal->x, pl->normal->y, pl->normal->z);
	// rec->color = vec_create(pl->color->x, pl->color->y, pl->color->z);
	rec->color = pl->color;
	return (TRUE);
}
