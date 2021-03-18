/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_sphere_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:10:08 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 14:16:31 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		set_rec(t_sphere *sp, t_hit_record *rec, t_vec *p, double t)
{
	rec->t = t;
	reset_hit_record(rec);
	rec->p = p;
	rec->normal = vec_unit(vec_sub(rec->p, sp->center));
	get_sphere_uv(rec);
	if (rec->u / 10 / 2 == 1 && rec->v / 10 / 2 == 1)
		rec->color = vec_mul_const(sp->color, 1);
	else
		rec->color = vec_create(255, 255, 255);
}

int			uv_sphere_hit(void *obj, t_ray *r, t_hit_record *rec)
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
	set_rec(sp, rec, ray_at(r, s.root), s.root);
	return (TRUE);
}
