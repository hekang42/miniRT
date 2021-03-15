/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:00:52 by hekang            #+#    #+#             */
/*   Updated: 2021/03/15 12:03:58 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				parse_cylinder_2(t_scene *scene, char *line)
{
	char		**s;
	char		**tmp;
	t_cylinder	*cy;

	s = ft_split(line, ' ');
	if (s == 0 || !s[1] || !s[2] || !s[3] || !s[4] || !s[5] || s[6])
	{
		printf("ERROR : Init Cylinder_bonus\n");
		return (0);
	}
	cy = (t_cylinder *)ft_calloc(1, sizeof(t_cylinder));
	tmp = ft_split(s[1], ',');
	cy->origin = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array((void **)tmp);
	tmp = ft_split(s[2], ',');
	cy->normal = vec_unit(vec_create(ft_atod(tmp[0]),
	ft_atod(tmp[1]), ft_atod(tmp[2])));
	free_array((void **)tmp);
	cy->diameter = ft_atod(s[4]);
	cy->height = ft_atod(s[5]);
	tmp = ft_split(s[3], ',');
	cy->color = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_array((void **)tmp);
	hitlst_add(scene->obj, (void *)cy, OBJ_CYLINDER);
	hitlst_add(scene->obj, (void *)cy, OBJ_CYLINDER_2);
	hitlst_add(scene->obj, (void *)cy, OBJ_CYLINDER_CAP);
	hitlst_add(scene->obj, (void *)cy, OBJ_CYLINDER_CAP_2);
	free_array((void **)s);
	return (1);
}
