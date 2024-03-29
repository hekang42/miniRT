/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:26:12 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 19:54:56 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit_record	*hit_record_new(void)
{
	t_hit_record	*result;

	result = (t_hit_record *)ft_calloc(1, sizeof(t_hit_record));
	result->normal = NULL;
	result->p = NULL;
	result->t_min = HIT_T_MIN;
	result->t_max = INFINITY;
	result->color = NULL;
	return (result);
}

void			reset_hit_record(t_hit_record *rec)
{
	if (rec->normal)
		free(rec->normal);
	if (rec->p)
		free(rec->p);
	if (rec->color)
		free(rec->color);
}

void			free_hit_record(t_hit_record *rec, int n)
{
	reset_hit_record(rec);
	free_ray(rec->ray, n);
	free(rec);
}
