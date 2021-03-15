/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_unit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:57:59 by hekang            #+#    #+#             */
/*   Updated: 2021/03/15 11:59:08 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		*vec_unit(t_vec *u)
{
	t_vec	*result;

	result = (t_vec *)ft_calloc(1, sizeof(t_vec));
	result = vec_div_const(u, vec_len(u));
	if (u)
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
