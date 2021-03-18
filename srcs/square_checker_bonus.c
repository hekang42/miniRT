/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_checker_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:21:07 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 14:43:18 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		set_rec(t_square *sq, t_hit_record *rec, t_vec *p, double t)
{
	reset_hit_record(rec);
	rec->p = p;
	rec->t = t;
	rec->normal = vec_create(sq->normal->x, sq->normal->y, sq->normal->z);
	get_square_uv(rec, sq);
	if ((int)(floor(rec->u * 20) + floor(rec->v * 20)) % 2 == 1)
		rec->color = vec_mul_const(sq->color, 1);
	else
		rec->color = vec_create(255, 255, 255);
}

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
		set_rec(sq, rec, p, t);
		return (TRUE);
	}
	free(p);
	return (FALSE);
}
