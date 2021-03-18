/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:23:28 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 17:43:47 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				parse_square_checker(t_scene *scene, char *line)
{
	char		**s;
	char		**tmp;
	t_square	*sq;

	s = ft_split(line, ' ');
	parse_check(s, 4, "Square with Checker");
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
	parse_check(s, 4, "Cylinder Rainbow");
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
	parse_check(s, 1, "Antialiasing");
	scene->anti = ft_atod(s[1]);
	free_array((void **)s);
	return (1);
}

int				parse_cone(t_scene *scene, char *line)
{
	char		**s;
	t_cylinder	*co;
	char		**tmp;

	s = ft_split(line, ' ');
	parse_check(s, 4, "Cone");
	co = (t_cylinder *)ft_calloc(1, sizeof(t_cylinder));
	tmp = ft_split(s[1], ',');
	co->origin = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array((void **)tmp);
	tmp = ft_split(s[2], ',');
	co->color = vec_create(ft_atod(tmp[0]),
		ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array((void **)tmp);
	co->normal = vec_unit(vec_create(1, -1, 0));
	co->diameter = ft_atod(s[3]);
	co->height = ft_atod(s[4]);
	hitlst_add(scene->obj, (void *)co, OBJ_CONE);
	hitlst_add(scene->obj, (void *)co, OBJ_CYLINDER_CAP);
	free_array((void **)s);
	return (1);
}

int				parse_sphere_rainbow(t_scene *scene, char *line)
{
	char		**s;
	t_vec		*origin;
	double		radius;
	char		**tmp;

	s = ft_split(line, ' ');
	parse_check(s, 2, "Sphere Rainbow");
	tmp = ft_split(s[1], ',');
	origin = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array((void **)tmp);
	radius = ft_atod(s[2]) / 2;
	hitlst_add(scene->obj, (void *)init_sphere(origin, radius,
		vec_create(0, 0, 0)), OBJ_SPHERE_RAINBOW);
	free_array((void **)s);
	return (1);
}
