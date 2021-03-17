/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:10:09 by hekang            #+#    #+#             */
/*   Updated: 2021/03/17 12:03:01 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			parse_bonus(t_scene *scene, char *line)
{
	while (line[0] == ' ')
		line++;
	if (ft_strnstr(line, "cy2 ", 4))
		parse_cylinder_2(scene, line);
	else if (ft_strnstr(line, "cb ", 3))
		parse_cube(scene, line);
	else if (ft_strnstr(line, "py ", 3))
		parse_pyramid(scene, line);
	else if (ft_strnstr(line, "sp_c ", 5))
		parse_sphere_checker(scene, line);
	else if (ft_strnstr(line, "sp_r ", 5))
		parse_sphere_rainbow(scene, line);
	else if (ft_strnstr(line, "sq_c ", 5))
		parse_square_checker(scene, line);
	else if (ft_strnstr(line, "cy_r ", 5))
		parse_cylinder_rainbow(scene, line);
	else if (ft_strnstr(line, "anti ", 5))
		parse_antialiasing(scene, line);
	else
		return (0);
	return (1);
}