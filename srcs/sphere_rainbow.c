/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_rainbow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:26:54 by hekang            #+#    #+#             */
/*   Updated: 2021/03/17 13:29:15 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			sphere_hit_rainbow(void *obj, t_ray *r, t_hit_record *rec)
{
	t_sphere	*sp;
	t_sp_set	s;

	sp = ((t_sphere *)obj);
	s = set_sphere_var(sp, r);
	if (s.discriminant < 0.00001)
		return (FALSE);
	s.sqrtd = sqrt(s.discriminant);
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
	rec->color = vec_mul_const_apply(vec_add_apply(vec_create(1, 1, 1), rec->normal), 255 / 2);
	return (TRUE);
}