/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:11:19 by hekang            #+#    #+#             */
/*   Updated: 2021/03/14 18:27:17 by hekang           ###   ########.fr       */
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
	if (s == 0 || !s[1] || !s[2] || !s[3] || s[4])
	{
		printf("ERROR : Init Plane\n");
		return (0);
	}
	tmp = ft_split(s[1], ',');
	origin = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array(tmp);
	tmp = ft_split(s[2], ',');
	normal = vec_unit(vec_create(ft_atod(tmp[0]),
		ft_atod(tmp[1]), ft_atod(tmp[2])));
	free_array(tmp);
	tmp = ft_split(s[3], ',');
	color = vec_create(ft_atoi(tmp[0]),
		ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_array(tmp);
	hitlst_add(scene->obj, (void *)init_plane(origin, normal, color),
		OBJ_PLANE);
	free_array(s);
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
	if (s == 0 || !s[1] || !s[2] || !s[3] || s[4])
	{
		printf("ERROR : Init Sphere\n");
		return (0);
	}
	tmp = ft_split(s[1], ',');
	origin = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array(tmp);
	radius = ft_atod(s[2]) / 2;
	tmp = ft_split(s[3], ',');
	color = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_array(tmp);
	hitlst_add(scene->obj, (void *)init_sphere(origin, radius, color),
		OBJ_SPHERE);
	free_array(s);
	return (1);
}

int				parse_triangle(t_scene *scene, char *line)
{
	char		**s;
	char		**tmp;
	t_triangle	*tri;

	s = ft_split(line, ' ');
	if (s == 0 || !s[1] || !s[2] || !s[3] || !s[4] || s[5])
	{
		printf("ERROR : Init Triangle\n");
		return (0);
	}
	tri = (t_triangle *)malloc(sizeof(t_triangle));
	tmp = ft_split(s[1], ',');
	tri->p0 = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array(tmp);
	tmp = ft_split(s[2], ',');
	tri->p1 = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array(tmp);
	tmp = ft_split(s[3], ',');
	tri->p2 = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array(tmp);
	tmp = ft_split(s[4], ',');
	tri->color = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_array(tmp);
	hitlst_add(scene->obj, (void *)tri, OBJ_TRIANGLE);
	free_array(s);
	return (1);
}

int				parse_square(t_scene *scene, char *line)
{
	char		**s;
	char		**tmp;
	t_square	*sq;

	s = ft_split(line, ' ');
	if (s == 0 || !s[1] || !s[2] || !s[3] || !s[4] || s[5])
	{
		printf("ERROR : Init Triangle\n");
		return (0);
	}
	sq = (t_square *)malloc(sizeof(t_square));
	tmp = ft_split(s[1], ',');
	sq->origin = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array(tmp);
	tmp = ft_split(s[2], ',');
	sq->normal = vec_unit(vec_create(ft_atod(tmp[0]),
		ft_atod(tmp[1]), ft_atod(tmp[2])));
	free_array(tmp);
	sq->size = ft_atod(s[3]);
	tmp = ft_split(s[4], ',');
	sq->color = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_array(tmp);
	hitlst_add(scene->obj, (void *)sq, OBJ_SQUARE);
	free_array(s);
	return (1);
}

int				parse_cylinder(t_scene *scene, char *line)
{
	char		**s;
	char		**tmp;
	t_cylinder	*cy;

	s = ft_split(line, ' ');
	if (s == 0 || !s[1] || !s[2] || !s[3] || !s[4] || !s[5] || s[6])
	{
		printf("ERROR : Init Cylinder\n");
		return (0);
	}
	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	tmp = ft_split(s[1], ',');
	cy->origin = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array(tmp);
	tmp = ft_split(s[2], ',');
	cy->normal = vec_unit(vec_create(ft_atod(tmp[0]),
		ft_atod(tmp[1]), ft_atod(tmp[2])));
	cy->diameter = ft_atod(s[4]);
	cy->height = ft_atod(s[5]);
	free_array(tmp);
	tmp = ft_split(s[3], ',');
	cy->color = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_array(tmp);
	hitlst_add(scene->obj, (void *)cy, OBJ_CYLINDER);
	hitlst_add(scene->obj, (void *)cy, OBJ_CYLINDER_2);
	free_array(s);
	return (1);
}
