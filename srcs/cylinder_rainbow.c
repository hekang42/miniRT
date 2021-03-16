/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_rainbow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 09:09:49 by hekang            #+#    #+#             */
/*   Updated: 2021/03/16 23:07:54 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	normal = vec_mul_const_apply(normal, -1);
	if ((0 < vec_dot(c.cp, cy->normal)) &&
		(vec_dot(c.cp, cy->normal) < cy->height))
	{
		rec->t = c.root;
		if (rec->p)
			free(rec->p);
		rec->p = p;
		if (rec->normal)
			free(rec->normal);
		rec->normal = normal;
		rec->color = vec_mul_const(vec_add(rec->normal, vec_create(1, 1, 1)), 255 / 2);
		free(c.cp);
		return (TRUE);
	}
	free(p);
	free(normal);
	free(c.cp);
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
	normal = vec_mul_const_apply(normal, -1);
	if ((0 < vec_dot(c.cp, cy->normal)) &&
		(vec_dot(c.cp, cy->normal) < cy->height))
	{
		rec->t = c.root;
		if (rec->p)
			free(rec->p);
		rec->p = p;
		if (rec->normal)
			free(rec->normal);
		rec->normal = normal;
		rec->color = vec_mul_const(vec_add(rec->normal, vec_create(1, 1, 1)), 255 / 2);
		free(c.cp);
		return (TRUE);
	}
	free(p);
	free(normal);
	free(c.cp);
	return (FALSE);
}
