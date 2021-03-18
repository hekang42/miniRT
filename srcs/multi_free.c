/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:42:19 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 11:44:32 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		free_2(void *a, void *b)
{
	free(a);
	free(b);
}

void		free_3(void *a, void *b, void *c)
{
	free(a);
	free(b);
	free(c);
}

void		free_4(void *a, void *b, void *c, void *d)
{
	free(a);
	free(b);
	free(c);
	free(d);
}
