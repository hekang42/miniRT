/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:15:37 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 15:38:06 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int					free_tri_set(t_tri_set *tri)
{
	if (tri->v0v1)
		free(tri->v0v1);
	if (tri->v0v2)
		free(tri->v0v2);
	if (tri->pvec)
		free(tri->pvec);
	if (tri->tvec)
		free(tri->tvec);
	if (tri->qvec)
		free(tri->qvec);
	return (0);
}

static t_tri_set	set_tri_v(t_triangle *tr)
{
	t_tri_set		tri_set;

	tri_set.v0v1 = vec_sub(tr->p1, tr->p0);
	tri_set.v0v2 = vec_sub(tr->p2, tr->p0);
	return (tri_set);
}

static void			set_rc(t_triangle *tr, t_hit_record *r, t_vec *p, double t)
{
	reset_hit_record(r);
	r->t = t;
	r->color = vec_mul_const(tr->color, 1);
	r->p = p;
}

int					triangle_hit(void *obj, t_ray *r, t_hit_record *rec)
{
	t_triangle		*tr;
	t_tri_set		tri_set;
	double			u;
	double			v;
	double			t;

	tr = (t_triangle *)obj;
	tri_set = set_tri_v(tr);
	tri_set.pvec = vec_cross(r->dir, tri_set.v0v2);
	tri_set.det = vec_dot(tri_set.v0v1, tri_set.pvec);
	tri_set.invdet = 1 / tri_set.det;
	tri_set.tvec = vec_sub(r->orig, tr->p0);
	u = vec_dot(tri_set.tvec, tri_set.pvec) * tri_set.invdet;
	tri_set.qvec = vec_cross(tri_set.tvec, tri_set.v0v1);
	v = vec_dot(r->dir, tri_set.qvec) * tri_set.invdet;
	if ((u < 0 || u > 1) || (v < 0 || u + v > 1)
		|| fabs(tri_set.det) < 0.000001)
		return (free_tri_set(&tri_set));
	t = vec_dot(tri_set.v0v2, tri_set.qvec) * tri_set.invdet;
	if (t > rec->t_max || t < rec->t_min)
		return (free_tri_set(&tri_set));
	set_rc(tr, rec, ray_at(r, t), t);
	rec->normal = vec_unit(vec_cross(tri_set.v0v1, tri_set.v0v2));
	free_tri_set(&tri_set);
	return (TRUE);
}
