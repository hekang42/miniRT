/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:00:21 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 17:07:02 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				parse_base(t_scene *scene, char *line)
{
	while (line[0] == ' ')
		line++;
	if (ft_strnstr(line, "R ", 2))
		parse_resolution(scene, line);
	else if (ft_strnstr(line, "A ", 2))
		parse_ambient(scene, line);
	else if (ft_strnstr(line, "c ", 2))
		parse_camera(scene, line);
	else if (ft_strnstr(line, "l ", 2))
		parse_light(scene, line);
	else
		return (0);
	return (1);
}

int				parse_obj(t_scene *scene, char *line)
{
	while (line[0] == ' ')
		line++;
	if (ft_strnstr(line, "pl ", 3))
		parse_plane(scene, line);
	else if (ft_strnstr(line, "sp ", 3))
		parse_sphere(scene, line);
	else if (ft_strnstr(line, "sq ", 3))
		parse_square(scene, line);
	else if (ft_strnstr(line, "cy ", 3))
		parse_cylinder(scene, line);
	else if (ft_strnstr(line, "tr ", 3))
		parse_triangle(scene, line);
	else
		return (0);
	return (1);
}

void			parse_rt(t_scene *scene, char *line)
{
	if (parse_base(scene, line))
		return ;
	else if (parse_obj(scene, line))
		return ;
	else if (parse_bonus(scene, line))
		return ;
	else if (parse_filter(scene, line))
		return ;
}

void			check_scene(t_scene *scene)
{
	if (!scene->resolution)
	{
		printf("Error\n ** Must have 1 Resolution.\n");
		exit(EXIT_SUCCESS);
	}
	if (!scene->amb)
	{
		printf("Error\n ** Must have 1 Ambient.\n");
		exit(EXIT_SUCCESS);
	}
}

t_scene			*parse(char *rt_file)
{
	int			rd;
	int			fd;
	char		*line;
	t_scene		*scene;

	scene = init_scene();
	fd = open(rt_file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n : rt file path\n");
		close(fd);
		return (0);
	}
	rd = 1;
	while (rd)
	{
		rd = get_next_line(fd, &line);
		parse_rt(scene, line);
		free(line);
	}
	close(fd);
	if (scene != NULL)
		return (scene);
	printf("Error\n : Parsing Scene\n");
	exit(EXIT_SUCCESS);
}
