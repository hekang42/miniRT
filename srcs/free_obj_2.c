/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:35:58 by hekang            #+#    #+#             */
/*   Updated: 2021/03/17 20:05:26 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void			free_sphere(t_sphere *sp)
{
	free(sp->center);
	free(sp->color);
	free(sp);
}

void			free_plane(t_plane *pl)
{
	free(pl->color);
	free(pl->normal);
	free(pl->p);
	free(pl);
}

void			free_square(t_square *sq)
{
	free(sq->color);
	free(sq->normal);
	free(sq->origin);
	free(sq);
}

void			free_cylinder(t_cylinder *cy)
{
	free(cy->color);
	free(cy->normal);
	free(cy->origin);
	free(cy);
}

void			free_triangle(t_triangle *tr)
{
	free(tr->color);
	free(tr->p0);
	free(tr->p1);
	free(tr->p2);
	free(tr);
}
