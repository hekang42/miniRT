/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 09:09:49 by hekang            #+#    #+#             */
/*   Updated: 2021/03/17 13:00:36 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cy_set		set_cylinder_var(t_cylinder *cy, t_ray *r, int type)
{
	t_cy_set	c;
	t_vec		*oc;

	oc = vec_sub(r->orig, cy->origin);
	c.a = vec_dot(r->dir, r->dir) - pow(vec_dot(r->dir, cy->normal), 2);
	c.b = 2 * (vec_dot(r->dir, oc) - vec_dot(r->dir, cy->normal)
		* vec_dot(oc, cy->normal));
	c.c = vec_dot(oc, oc) - pow(vec_dot(oc, cy->normal), 2)
		- pow(cy->diameter / 2, 2);
	c.discriminant = pow(c.b, 2) - 4 * c.a * c.c;
	if (type == 1)
		c.root = (-c.b + pow(c.discriminant, 0.5)) / 2 / c.a;
	else if (type == 2)
		c.root = (-c.b - pow(c.discriminant, 0.5)) / 2 / c.a;
	free(oc);
	return (c);
}

int				cylinder_hit_2(void *obj, t_ray *r, t_hit_record *rec)
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
	normal = vec_mul_const_apply(normal, -1);
	if ((0 < vec_dot(c.cp, cy->normal)) &&
		(vec_dot(c.cp, cy->normal) < cy->height))
	{
		rec->t = c.root;
		reset_hit_record(rec);
		rec->p = p;
		rec->normal = normal;
		rec->color = vec_mul_const(cy->color, 1);
		free(c.cp);
		return (TRUE);
	}
	free(p);
	free(normal);
	free(c.cp);
	return (FALSE);
}

int				cylinder_hit(void *obj, t_ray *r, t_hit_record *rec)
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
	normal = vec_mul_const_apply(normal, -1);
	if ((0 < vec_dot(c.cp, cy->normal)) &&
		(vec_dot(c.cp, cy->normal) < cy->height))
	{
		rec->t = c.root;
		reset_hit_record(rec);
		rec->p = p;
		rec->normal = normal;
		rec->color = vec_mul_const(cy->color, 1);
		free(c.cp);
		return (TRUE);
	}
	free(p);
	free(normal);
	free(c.cp);
	return (FALSE);
}
