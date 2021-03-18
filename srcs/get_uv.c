/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:04:38 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 16:03:34 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		get_sphere_uv(t_hit_record *rec)
{
	double	theta;
	double	phi;

	theta = acos(-(rec->normal->y));
	phi = atan2(-(rec->normal->z), rec->normal->x) + M_PI;
	rec->u = phi / (2 * M_PI);
	rec->v = theta / M_PI;
}

void		get_square_uv(t_hit_record *rec, t_square *sq)
{
	double	inv_len;

	inv_len = 1 / sq->size;
	rec->u = (rec->u + sq->size) * inv_len;
	rec->v = (rec->v + sq->size) * inv_len;
}
