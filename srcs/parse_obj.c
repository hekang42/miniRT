/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:11:19 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 11:32:25 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				parse_plane(t_scene *scene, char *line)
{
	char		**s;
	t_vec		*origin;
	t_vec		*normal;
	t_vec		*color;
	char		**tmp;

	s = ft_split(line, ' ');
	parse_check(s, 3, "Plane");
	tmp = ft_split(s[1], ',');
	origin = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array((void **)tmp);
	tmp = ft_split(s[2], ',');
	normal = vec_unit(vec_create(ft_atod(tmp[0]),
		ft_atod(tmp[1]), ft_atod(tmp[2])));
	free_array((void **)tmp);
	tmp = ft_split(s[3], ',');
	color = vec_create(ft_atoi(tmp[0]),
		ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_array((void **)tmp);
	hitlst_add(scene->obj, (void *)init_plane(origin, normal, color),
		OBJ_PLANE);
	free_array((void **)s);
	return (1);
}

int				parse_sphere(t_scene *scene, char *line)
{
	char		**s;
	t_vec		*origin;
	double		radius;
	t_vec		*color;
	char		**tmp;

	s = ft_split(line, ' ');
	parse_check(s, 3, "Sphere");
	tmp = ft_split(s[1], ',');
	origin = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array((void **)tmp);
	radius = ft_atod(s[2]) / 2;
	tmp = ft_split(s[3], ',');
	color = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_array((void **)tmp);
	hitlst_add(scene->obj, (void *)init_sphere(origin, radius, color),
		OBJ_SPHERE);
	free_array((void **)s);
	return (1);
}

int				parse_triangle(t_scene *scene, char *line)
{
	char		**s;
	char		**tmp;
	t_triangle	*tri;

	s = ft_split(line, ' ');
	parse_check(s, 4, "Triangle");
	tri = (t_triangle *)ft_calloc(1, sizeof(t_triangle));
	tmp = ft_split(s[1], ',');
	tri->p0 = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array((void **)tmp);
	tmp = ft_split(s[2], ',');
	tri->p1 = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array((void **)tmp);
	tmp = ft_split(s[3], ',');
	tri->p2 = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array((void **)tmp);
	tmp = ft_split(s[4], ',');
	tri->color = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_array((void **)tmp);
	hitlst_add(scene->obj, (void *)tri, OBJ_TRIANGLE);
	free_array((void **)s);
	return (1);
}

int				parse_square(t_scene *scene, char *line)
{
	char		**s;
	char		**tmp;
	t_square	*sq;

	s = ft_split(line, ' ');
	parse_check(s, 4, "Square");
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
	hitlst_add(scene->obj, (void *)sq, OBJ_SQUARE);
	free_array((void **)s);
	return (1);
}

int				parse_cylinder(t_scene *scene, char *line)
{
	char		**s;
	char		**tmp;
	t_cylinder	*cy;

	s = ft_split(line, ' ');
	parse_check(s, 5, "Cylinder");
	cy = (t_cylinder *)ft_calloc(1, sizeof(t_cylinder));
	tmp = ft_split(s[1], ',');
	cy->origin = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array((void **)tmp);
	tmp = ft_split(s[2], ',');
	cy->normal = vec_unit(vec_create(ft_atod(tmp[0]),
		ft_atod(tmp[1]), ft_atod(tmp[2])));
	cy->diameter = ft_atod(s[4]);
	cy->height = ft_atod(s[5]);
	free_array((void **)tmp);
	tmp = ft_split(s[3], ',');
	cy->color = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_array((void **)tmp);
	hitlst_add(scene->obj, (void *)cy, OBJ_CYLINDER);
	hitlst_add(scene->obj, (void *)cy, OBJ_CYLINDER_2);
	free_array((void **)s);
	return (1);
}
