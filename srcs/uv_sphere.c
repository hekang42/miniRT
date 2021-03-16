/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:10:08 by hekang            #+#    #+#             */
/*   Updated: 2021/03/16 17:14:26 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			uv_sphere_hit(void *obj, t_ray *r, t_hit_record *rec)
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
	if (rec->p)
		free(rec->p);
	rec->p = ray_at(r, s.root);
	if (rec->normal)
		free(rec->normal);
	rec->normal = vec_unit(vec_sub(rec->p, sp->center));
	get_sphere_uv(rec);
	if (rec->u / 10 / 2 == 1 && rec->v / 10 / 2 ==1)
		rec->color = vec_create(0,0,0);
	else
		rec->color = vec_create(255,255,255);
	free(sp->color);
	// rec->color = sp->color;

	return (TRUE);
}
