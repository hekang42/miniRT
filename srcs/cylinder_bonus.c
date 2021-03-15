/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:03:43 by hekang            #+#    #+#             */
/*   Updated: 2021/03/15 17:32:15 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				draw_circle(t_vec *a, double r, t_vec *n)
{
	t_vec		*n_x;
	t_vec		*n_y;
	t_vec		*vup;
	t_vec		len;

	vup = vec_create(1, 0, 0);
	if (vec_is_parallel(vup, n))
	{
		free(vup);
		vup = vec_create(0, 1, 0);
	}
	n_x = vec_unit(vec_cross(vup, n));
	n_y = vec_unit(vec_cross(n, n_x));
	len.x = fabs(vec_dot(a, n_x));
	len.y = fabs(vec_dot(a, n_y));
	free(vup);
	free(n_x);
	free(n_y);
	free(a);
	if (len.x * len.x + len.y * len.y < r * r)
		return (TRUE);
	return (FALSE);
}

int				cylinder_hit_top_cap(void *obj, t_ray *r, t_hit_record *rec)
{
	t_cylinder	*cy;
	double		denominator;
	double		t;
	t_vec		*c;
	t_vec		*p;
	t_vec		*tmp;

	cy = (t_cylinder *)obj;
	denominator = vec_dot(cy->normal, r->dir);
	if (fabs(denominator) < 0.000001)
		return (FALSE);
	p = vec_mul_const(cy->normal, cy->height);
	c = vec_add(cy->origin, p);
	free(p);
	p = vec_sub(c, r->orig);
	t = vec_dot(p, cy->normal) / denominator;
	free(p);
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	p = ray_at(r, t);
	tmp = vec_sub(p, c);
	if (draw_circle(tmp, cy->diameter / 2, cy->normal))
	{
		if (rec->p)
			free(rec->p);
		if (rec->normal)
			free(rec->normal);
		rec->p = p;
		rec->t = t;
		rec->normal = vec_unit(vec_create(cy->normal->x, cy->normal->y, cy->normal->z));
		rec->color = cy->color;
		free(c);
		return (TRUE);
	}
	free(c);
	return (FALSE);
}

int				cylinder_hit_bottom_cap(void *obj, t_ray *r, t_hit_record *rec)
{
	t_cylinder	*cy;
	double		denominator;
	t_vec		*oc;
	double		t;
	t_vec		*p;

	cy = (t_cylinder *)obj;
	denominator = vec_dot(cy->normal, r->dir);
	if (fabs(denominator) < 0.000001)
		return (FALSE);
	oc = vec_sub(cy->origin, r->orig);
	t = vec_dot(oc, cy->normal) / denominator;
	free(oc);
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	p = ray_at(r, t);
	oc = vec_sub(p, cy->origin);
	if (draw_circle(oc, cy->diameter / 2, cy->normal))
	{
		if (rec->p)
			free(rec->p);
		if (rec->normal)
			free(rec->normal);
		rec->p = p;
		rec->t = t;
		rec->normal = vec_unit(vec_create(cy->normal->x, cy->normal->y, cy->normal->z));
		rec->color = cy->color;
		return (TRUE);
	}
	return (FALSE);
}
