/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_filter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:32:31 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 18:37:58 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				parse_filter(t_scene *scene, char *line)
{
	while (line[0] == ' ')
		line++;
	if (ft_strnstr(line, "sepia", 5))
		scene->sepia = TRUE;
	return (0);
}
