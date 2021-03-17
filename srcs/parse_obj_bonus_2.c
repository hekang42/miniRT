/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_bonus_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:23:28 by hekang            #+#    #+#             */
/*   Updated: 2021/03/17 12:47:22 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				parse_square_checker(t_scene *scene, char *line)
{
	char		**s;
	char		**tmp;
	t_square	*sq;

	s = ft_split(line, ' ');
	if (s == 0 || !s[1] || !s[2] || !s[3] || !s[4] || s[5])
	{
		printf("ERROR : Init Square Checker\n");
		return (0);
	}
	sq = (t_square *)ft_calloc(1, sizeof(t_square));
	tmp = ft_split(s[1], ',');
	sq->origin = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array((void **)tmp);
	tmp = ft_split(s[2], ',');
	sq->normal = vec_unit(vec_create(ft_atod(tmp[0]),
		ft_atod(tmp[1]), ft_atod(tmp[2])));
	free_array((void **)tmp);
	sq->size = ft_atod(s[3]);
	tmp = ft_split(s[4], ',');
	sq->color = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_array((void **)tmp);
	hitlst_add(scene->obj, (void *)sq, OBJ_SQUARE_CHECKER);
	free_array((void **)s);
	return (1);
}

int				parse_cylinder_rainbow(t_scene *scene, char *line)
{
	char		**s;
	char		**tmp;
	t_cylinder	*cy;

	s = ft_split(line, ' ');
	if (s == 0 || !s[1] || !s[2] || !s[3] || !s[4] || s[5])
	{
		printf("ERROR : Init Cylinder Rainbow\n");
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
	cy->diameter = ft_atod(s[3]);
	cy->height = ft_atod(s[4]);
	cy->color = vec_create(1, 1, 1);
	hitlst_add(scene->obj, (void *)cy, OBJ_CYLINDER_RAINBOW);
	hitlst_add(scene->obj, (void *)cy, OBJ_CYLINDER_RAINBOW_2);
	free_array((void **)s);
	return (1);
}

int				parse_antialiasing(t_scene *scene, char *line)
{
	char		**s;

	s = ft_split(line, ' ');
	if (s == 0 || !s[1] || s[2])
	{
		printf("ERROR : Init Antialiasing\n");
		return (0);
	}
	scene->anti = ft_atod(s[1]);
	free_array((void **)s);
	return (1);
}