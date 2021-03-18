/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:23:46 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 14:51:10 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cy_set		set_cone_var(t_cylinder *cy, t_ray *r, int type)
{
	t_cy_set	c;
	t_vec		*oc;
	double		m;

	m = pow(cy->diameter / 2, 2) / pow(cy->height, 2);
	oc = vec_sub(r->orig, cy->origin);
	c.a = vec_dot(r->dir, r->dir) -
		pow(vec_dot(r->dir, cy->normal), 2) * (m + 1);
	c.b = 2 * (vec_dot(r->dir, oc) - vec_dot(r->dir, cy->normal)
		* vec_dot(oc, cy->normal) * (m + 1));
	c.c = vec_dot(oc, oc) - pow(vec_dot(oc, cy->normal), 2) * (m + 1);
	c.discriminant = pow(c.b, 2) - 4 * c.a * c.c;
	if (type == 1)
		c.root = (-c.b + pow(c.discriminant, 0.5)) / 2 / c.a;
	else if (type == 2)
		c.root = (-c.b - pow(c.discriminant, 0.5)) / 2 / c.a;
	free(oc);
	return (c);
}

void			set_rc(t_cylinder *cone, t_hit_record *rec, t_vec *p, double t)
{
	rec->t = t;
	reset_hit_record(rec);
	rec->p = p;
	rec->color = vec_mul_const(cone->color, 1);
}

int				cone_hit(void *obj, t_ray *r, t_hit_record *rec)
{
	t_cylinder	*cone;
	t_cy_set	c;
	t_vec		*p;
	t_vec		*normal;
	t_vec		*tmp;

	cone = (t_cylinder *)obj;
	c = set_cone_var(cone, r, 2);
	if (c.discriminant < 0.00001 || c.root < rec->t_min || c.root > rec->t_max)
		return (FALSE);
	p = ray_at(r, c.root);
	c.cp = vec_sub(p, cone->origin);
	tmp = vec_mul_const(cone->normal, vec_dot(c.cp, cone->normal));
	normal = vec_mul_const_apply(vec_unit(vec_sub_apply(vec_add_apply(tmp,
		cone->origin), p)), -1);
	if ((0 < vec_dot(c.cp, cone->normal)) &&
		(vec_dot(c.cp, cone->normal) < cone->height))
	{
		set_rc(cone, rec, p, c.root);
		rec->normal = normal;
		free(c.cp);
		return (TRUE);
	}
	free_3(p, normal, c.cp);
	return (FALSE);
}
