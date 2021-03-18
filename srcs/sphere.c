/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:15:49 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 19:45:37 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*init_sphere(t_vec *center, double radius, t_vec *color)
{
	t_sphere	*result;

	result = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	result->center = center;
	result->radius = radius;
	result->color = color;
	return (result);
}

t_sp_set	set_sphere_var(t_sphere *sp, t_ray *r)
{
	t_sp_set	s;

	s.oc = vec_sub(r->orig, sp->center);
	s.a = vec_dot(r->dir, r->dir);
	s.half_b = vec_dot(r->dir, s.oc);
	s.c = vec_dot(s.oc, s.oc) - pow(sp->radius, 2);
	s.discriminant = pow(s.half_b, 2) - s.a * s.c;
	s.sqrtd = sqrt(s.discriminant);
	free(s.oc);
	return (s);
}

int			sphere_hit(void *obj, t_ray *r, t_hit_record *rec)
{
	t_sphere	*sp;
	t_sp_set	s;

	sp = ((t_sphere *)obj);
	s = set_sphere_var(sp, r);
	if (s.discriminant < 0.00001)
		return (FALSE);
	s.root = (-s.half_b - s.sqrtd) / s.a;
	if (s.root < rec->t_min || s.root > rec->t_max)
	{
		s.root = (-s.half_b + s.sqrtd) / s.a;
		if (s.root < rec->t_min || s.root > rec->t_max)
			return (FALSE);
	}
	if ((-s.half_b + s.sqrtd) / s.a < rec->t_min
		|| (-s.half_b - s.sqrtd) / s.a < rec->t_min)
		return (FALSE);
	rec->t = s.root;
	reset_hit_record(rec);
	rec->p = ray_at(r, s.root);
	rec->normal = vec_unit(vec_sub(rec->p, sp->center));
	rec->color = vec_mul_const(sp->color, 1);
	get_sphere_uv(rec);
	return (TRUE);
}
