/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:15:37 by hekang            #+#    #+#             */
/*   Updated: 2021/03/17 13:03:59 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		free_tri_set(t_tri_set *tri)
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

int		triangle_hit(void *obj, t_ray *r, t_hit_record *rec)
{
	t_triangle		*tr;
	t_tri_set		tri_set;
	double			u;
	double			v;
	double			t;

	tr = (t_triangle *)obj;
	tri_set.v0v1 = vec_sub(tr->p1, tr->p0);
	tri_set.v0v2 = vec_sub(tr->p2, tr->p0);
	tri_set.pvec = vec_cross(r->dir, tri_set.v0v2);
	tri_set.det = vec_dot(tri_set.v0v1, tri_set.pvec);
	tri_set.invdet = 1 / tri_set.det;
	tri_set.tvec = vec_sub(r->orig, tr->p0);
	u = vec_dot(tri_set.tvec, tri_set.pvec) * tri_set.invdet;
	tri_set.qvec = vec_cross(tri_set.tvec, tri_set.v0v1);
	v = vec_dot(r->dir, tri_set.qvec) * tri_set.invdet;
	if ((u < 0 || u > 1) || (v < 0 || u + v > 1) || fabs(tri_set.det) < 0.000001)
		return (free_tri_set(&tri_set));
	t = vec_dot(tri_set.v0v2, tri_set.qvec) * tri_set.invdet;
	if (t > rec->t_max || t < rec->t_min)
		return (free_tri_set(&tri_set));
	rec->t = t;
	reset_hit_record(rec);
	rec->color = vec_mul_const(tr->color, 1);
	rec->p = ray_at(r, rec->t);
	rec->normal = vec_unit(vec_cross(tri_set.v0v1, tri_set.v0v2));
	free_tri_set(&tri_set);
	return (TRUE);
}
