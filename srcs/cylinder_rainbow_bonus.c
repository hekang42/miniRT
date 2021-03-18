/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_rainbow_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 09:09:49 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 16:32:35 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		set_rec(t_hit_record *rec, t_vec *p, t_vec *normal, double t)
{
	reset_hit_record(rec);
	rec->p = p;
	rec->normal = vec_mul_const_apply(normal, -1);
	rec->color = vec_mul_const_apply(vec_add_apply(vec_create(1, 1, 1),
				rec->normal), 255 / 2);
	rec->t = t;
}

int				cylinder_hit_rainbow_2(void *obj, t_ray *r, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_cy_set	c;
	t_vec		*p;
	t_vec		*normal;
	t_vec		*tmp;

	cy = (t_cylinder *)obj;
	c = set_cylinder_var(cy, r, 1);
	if (c.discriminant < 0.00001 || c.root < rec->t_min
		|| c.root > rec->t_max)
		return (FALSE);
	p = ray_at(r, c.root);
	c.cp = vec_sub(p, cy->origin);
	tmp = vec_mul_const(cy->normal, vec_dot(c.cp, cy->normal));
	normal = vec_unit(vec_sub_apply(vec_add_apply(tmp, cy->origin), p));
	if ((0 < vec_dot(c.cp, cy->normal)) &&
		(vec_dot(c.cp, cy->normal) < cy->height))
	{
		set_rec(rec, p, normal, c.root);
		free(c.cp);
		return (TRUE);
	}
	free_3(p, normal, c.cp);
	return (FALSE);
}

int				cylinder_hit_rainbow(void *obj, t_ray *r, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_cy_set	c;
	t_vec		*p;
	t_vec		*normal;
	t_vec		*tmp;

	cy = (t_cylinder *)obj;
	c = set_cylinder_var(cy, r, 2);
	if (c.discriminant < 0.00001 || c.root < rec->t_min
		|| c.root > rec->t_max)
		return (FALSE);
	p = ray_at(r, c.root);
	c.cp = vec_sub(p, cy->origin);
	tmp = vec_mul_const(cy->normal, vec_dot(c.cp, cy->normal));
	normal = vec_unit(vec_sub_apply(vec_add_apply(tmp, cy->origin), p));
	if ((0 < vec_dot(c.cp, cy->normal)) &&
		(vec_dot(c.cp, cy->normal) < cy->height))
	{
		set_rec(rec, p, normal, c.root);
		free(c.cp);
		return (TRUE);
	}
	free_3(p, normal, c.cp);
	return (FALSE);
}
