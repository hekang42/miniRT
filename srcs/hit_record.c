/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:26:12 by hekang            #+#    #+#             */
/*   Updated: 2021/03/11 14:06:56 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit_record	*hit_record_new(void)
{
	t_hit_record	*result;

	result = (t_hit_record *)malloc(sizeof(t_hit_record));
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
}

void			free_hit_record(t_hit_record *rec)
{
	reset_hit_record(rec);
	free(rec);
}

void			hit_set_normal(t_hit_record *record, t_ray *r)
{
	record->is_front_face = (vec_dot(r->dir, record->normal) < 0) ?
								TRUE : FALSE;
	if (record->is_front_face == FALSE)
		vec_mul_const_apply(record->normal, -1);
}
