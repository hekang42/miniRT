/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:13:33 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 17:28:38 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			check_arg(int argc, char **argv)
{
	if (argc == 3 && !ft_strnstr(argv[2], "--save", 6))
	{
		printf("Error\n : Input Argument Must be '--save'\n");
		return (0);
	}
	if (argc != 2 && argc != 3)
	{
		printf("Error\n : Input Argument\n");
		return (0);
	}
	return (1);
}
