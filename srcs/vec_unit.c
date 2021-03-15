/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_unit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:57:59 by hekang            #+#    #+#             */
/*   Updated: 2021/03/15 16:22:37 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		*vec_unit(t_vec *u)
{
	t_vec	*result;

	result = vec_div_const(u, vec_len(u));
	free(u);
	return (result);
}

t_vec		*vec_unit_apply(t_vec *u)
{
	t_vec	*unit;

	unit = vec_unit(u);
	u->x = unit->x;
	u->y = unit->y;
	u->z = unit->z;
	free(unit);
	return (u);
}
