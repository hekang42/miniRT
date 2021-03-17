/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:00:52 by hekang            #+#    #+#             */
/*   Updated: 2021/03/17 12:52:07 by hekang           ###   ########.fr       */
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

int				parse_cube(t_scene *scene, char *line)
{
	char		**s;
	char		**tmp;
	t_cube		*cb;

	s = ft_split(line, ' ');
	if (s == 0 || !s[1] || !s[2] || !s[3] || s[4])
	{
		printf("ERROR : Init Cube\n");
		return (0);
	}
	cb = (t_cube *)ft_calloc(1, sizeof(t_cube));
	tmp = ft_split(s[1], ',');
	cb->origin = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array((void **)tmp);
	cb->size = ft_atod(s[2]) / 2;
	tmp = ft_split(s[3], ',');	
	cb->color = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_array((void **)tmp);
	free_array((void **)s);
	cubetosquare(scene, cb);
	cubetosquare_2(scene, cb);
	free(cb->color);
	free(cb->origin);
	free(cb);
	return (1);
}

int				parse_pyramid(t_scene *scene, char *line)
{
	char		**s;
	char		**tmp;
	t_pyramid	*py;

	s = ft_split(line, ' ');
	if (s == 0 || !s[1] || !s[2] || !s[3] || s[4])
	{
		printf("ERROR : Init Cube\n");
		return (0);
	}
	py = (t_pyramid *)ft_calloc(1, sizeof(t_pyramid));
	tmp = ft_split(s[1], ',');
	py->origin = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array((void **)tmp);
	py->size = ft_atod(s[2]) / 2;
	tmp = ft_split(s[3], ',');	
	py->color = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_array((void **)tmp);
	free_array((void **)s);
	pyramidtosquare(scene, py);
	pyramidtotriangle(scene, py);
	free(py->color);
	free(py->origin);
	free(py);
	return (1);
}

int					parse_sphere_checker(t_scene *scene, char *line)
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
	free_array((void **)tmp);
	radius = ft_atod(s[2]) / 2;
	tmp = ft_split(s[3], ',');
	color = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_array((void **)tmp);
	hitlst_add(scene->obj, (void *)init_sphere(origin, radius, color),
		OBJ_SPHERE_CHECKER);
	free_array((void **)s);
	return (1);
}

int					parse_sphere_rainbow(t_scene *scene, char *line)
{
	char		**s;
	t_vec		*origin;
	double		radius;
	char		**tmp;

	s = ft_split(line, ' ');
	if (s == 0 || !s[1] || !s[2] || s[3])
	{
		printf("ERROR : Init Sphere\n");
		return (0);
	}
	tmp = ft_split(s[1], ',');
	origin = vec_create(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_array((void **)tmp);
	radius = ft_atod(s[2]) / 2;
	hitlst_add(scene->obj, (void *)init_sphere(origin, radius, vec_create(0, 0, 0)),
		OBJ_SPHERE_RAINBOW);
	free_array((void **)s);
	return (1);
}