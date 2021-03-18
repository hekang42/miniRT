/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:59:16 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 14:00:08 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				vec_each_len(t_vec *a, double l, t_vec *n, t_hit_record *rec)
{
	t_vec		*n_x;
	t_vec		*n_y;
	t_vec		*vup;
	t_vec		len;

	vup = vec_create(1, 0, 0);
	if (vec_is_parallel(vup, n))
	{
		free(vup);
		vup = vec_create(0, 1, 0);
	}
	n_x = vec_unit(vec_cross(vup, n));
	n_y = vec_unit(vec_cross(n, n_x));
	rec->u = vec_dot(a, n_x);
	rec->v = vec_dot(a, n_y);
	len.x = fabs(vec_dot(a, n_x));
	len.y = fabs(vec_dot(a, n_y));
	free(n_x);
	free(n_y);
	free(vup);
	free(a);
	if ((len.x <= l) && (len.y <= l))
		return (TRUE);
	return (FALSE);
}

void			set_square(t_square *sq, t_hit_record *rec, t_vec *p, double t)
{
	reset_hit_record(rec);
	rec->p = p;
	rec->t = t;
	rec->normal = vec_mul_const(sq->normal, 1);
	rec->color = vec_mul_const(sq->color, 1);
}

int				square_hit(void *obj, t_ray *r, t_hit_record *rec)
{
	double		denominator;
	t_square	*sq;
	double		t;
	t_vec		*p;

	sq = ((t_square *)obj);
	denominator = vec_dot(sq->normal, r->dir);
	if (fabs(denominator) < 0.000001)
		return (FALSE);
	p = vec_sub(sq->origin, r->orig);
	t = vec_dot(p, sq->normal) / denominator;
	free(p);
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	p = ray_at(r, t);
	if (vec_each_len(vec_sub(p, sq->origin), sq->size / 2, sq->normal, rec))
	{
		set_square(sq, rec, p, t);
		return (TRUE);
	}
	free(p);
	return (FALSE);
}
