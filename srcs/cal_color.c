/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:48:50 by hekang            #+#    #+#             */
/*   Updated: 2021/03/11 16:23:00 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec				*diffuse_color(t_light *light, t_hit_record *rec)
{
	t_vec			*color;
	t_vec			*diffuse_l;
	t_vec			*diffuse_n;

	diffuse_l = vec_unit(vec_sub(light->origin, rec->p));
	diffuse_n = rec->normal;
	color = vec_mul_const(light->color,
		vec_dot(diffuse_l, diffuse_n) * light->ratio);
	return (vec_div_const(clamp_vec(color, 0, 255), 255.0));
}

t_vec				*specular_color(t_light *light, t_hit_record *rec)
{
	t_vec			*color;
	double			ks;
	t_specular_var	var;

	ks = light->ratio;
	var.v = vec_unit(vec_sub(rec->p, rec->ray->orig));
	var.l = vec_sub(light->origin, rec->p);
	var.l_rev = vec_sub(rec->p, light->origin);
	var.r = vec_unit(vec_add(var.l_rev, vec_mul_const(rec->normal,
		2 * clamp(vec_dot(var.l, rec->normal), 0, INFINITY))));
	var.reflection = 0;
	if (vec_dot(var.v, var.r) < 0)
		var.reflection = pow(vec_dot(var.v, var.r), 100);
	color = vec_mul_const(light->color, var.reflection * ks);
	return (vec_div_const(clamp_vec(color, 0, 255), 255.0));
}

t_vec				*ambient_color(t_scene *scene)
{
	return (vec_mul_const(scene->ambient->color,
		scene->ambient->ratio / 255.0));
}

int					lightlst_hit(t_scene *scene, t_list *lst, t_hit_record *rec)
{
	t_vec			*color;
	t_light			*light;
	t_vec			*diffuse;
	t_vec			*specular;

	color = rec->color;
	diffuse = vec_create(0, 0, 0);
	specular = vec_create(0, 0, 0);
	while (lst && lst->content)
	{
		light = (t_light *)(lst->content);
		if (!in_shadow(scene, light, rec))
		{
			diffuse = vec_add(diffuse, diffuse_color(light, rec));
			specular = vec_add(specular, specular_color(light, rec));
		}
		lst = lst->next;
	}
	color = vec_mul_each(color, vec_add(diffuse, specular));
	vec_add_apply(color, vec_mul_each(rec->color, ambient_color(scene)));
	return (get_color(color));
}

int					get_color(t_vec *color)
{
	int				x;
	int				y;
	int				z;

	x = clamp(color->x, 0, 255);
	y = clamp(color->y, 0, 255);
	z = clamp(color->z, 0, 255);
	return (x << 16 | y << 8 | z);
}
