/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:48:50 by hekang            #+#    #+#             */
/*   Updated: 2021/03/15 17:14:20 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec				*diffuse_color(t_light *light, t_hit_record *rec)
{
	t_vec			*color;
	t_vec			*diffuse_l;

	diffuse_l = vec_unit(vec_sub(light->origin, rec->p));
	color = vec_mul_const(light->color,
		vec_dot(diffuse_l, rec->normal) * light->ratio);
	free(diffuse_l);
	return (vec_div_const_apply(clamp_vec(color, 0, 255), 255.0));
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
	var.r = vec_unit(vec_add_apply(vec_mul_const(rec->normal,
		2 * clamp(vec_dot(var.l, rec->normal), 0, INFINITY)), var.l_rev));
	var.reflection = 0;
	if (vec_dot(var.v, var.r) < 0)
		var.reflection = pow(vec_dot(var.v, var.r), 100);
	color = vec_mul_const(light->color, var.reflection * ks);
	free(var.l);
	free(var.l_rev);
	free(var.r);
	free(var.v);
	return (vec_div_const_apply(clamp_vec(color, 0, 255), 255.0));
}

t_vec				*ambient_color(t_scene *scene)
{
	return (vec_mul_const(scene->ambient->color,
		scene->ambient->ratio / 255.0));
}

int					lightlst_hit(t_scene *scene, t_list *lst, t_hit_record *rec)
{
	t_light			*light;
	t_vec			*diffuse;
	t_vec			*specular;
	t_vec			*ambient;
	t_vec			*tmp;

	diffuse = vec_create(0, 0, 0);
	specular = vec_create(0, 0, 0);
	while (lst && lst->content)
	{
		light = (t_light *)(lst->content);
		if (!in_shadow(scene, light, rec))
		{
			tmp = diffuse_color(light, rec);
			diffuse = vec_add_apply(diffuse, tmp);
			free(tmp);
			tmp = specular_color(light, rec);
			specular = vec_add_apply(specular, tmp);
			free(tmp);
		}
		lst = lst->next;
	}
	tmp = vec_mul_each(vec_add(diffuse, specular), rec->color);
	ambient = ambient_color(scene);
	vec_add_apply(tmp, vec_mul_each(ambient, rec->color));
	free(diffuse);
	free(specular);
	free(ambient);
	return (get_color(tmp));
}

int					get_color(t_vec *color)
{
	int				x;
	int				y;
	int				z;

	x = clamp(color->x, 0, 255);
	y = clamp(color->y, 0, 255);
	z = clamp(color->z, 0, 255);
	free(color);
	return (x << 16 | y << 8 | z);
}
