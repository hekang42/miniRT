/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:21:07 by hekang            #+#    #+#             */
/*   Updated: 2021/03/16 22:39:51 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				square_hit_checker(void *obj, t_ray *r, t_hit_record *rec)
{
	double		denominator;
	t_square	*sq;
	t_vec		*oc;
	double		t;
	t_vec		*p;

	sq = ((t_square *)obj);
	denominator = vec_dot(sq->normal, r->dir);
	if (fabs(denominator) < 0.000001)
		return (FALSE);
	oc = vec_sub(sq->origin, r->orig);
	t = vec_dot(oc, sq->normal) / denominator;
	free(oc);
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	p = ray_at(r, t);
	if (vec_each_len(vec_sub(p, sq->origin), sq->size / 2, sq->normal, rec))
	{
		if (rec->p)
			free(rec->p);
		rec->p = p;
		if (rec->normal)
			free(rec->normal);
		rec->t = t;
		rec->normal = vec_create(sq->normal->x, sq->normal->y, sq->normal->z);
		get_square_uv(rec, sq);
		if ((int)(floor(rec->u * 20) + floor(rec->v * 20)) % 2 == 1)
			rec->color = sq->color;
		else
			rec->color = vec_create(255,255,255);
		return (TRUE);
	}
	free(p);
	return (FALSE);
}