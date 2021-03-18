/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:17:46 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 19:57:53 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int					in_shadow(t_scene *scene, t_light *light, t_hit_record *rec)
{
	t_ray			*light_ray;
	double			light_length;
	t_vec			*p;
	t_hit_record	*rec_l;
	t_vec			*tmp;

	rec_l = hit_record_new();
	tmp = vec_mul_const(rec->normal, 0.000001);
	p = vec_add_apply(tmp, rec->p);
	light_ray = create_ray(p, vec_unit(vec_sub(light->origin, p)));
	tmp = vec_sub(light->origin, p);
	light_length = vec_len(tmp);
	free(tmp);
	rec_l->p = vec_mul_const(p, 1);
	rec_l->t_max = light_length;
	rec_l->ray = light_ray;
	if (!hitlst_hit(scene->obj, rec_l))
	{
		free_hit_record(rec_l, 1);
		if (vec_dot(rec->normal, rec->ray->dir) > 0)
			return (TRUE);
		return (FALSE);
	}
	free_hit_record(rec_l, 1);
	return (TRUE);
}
