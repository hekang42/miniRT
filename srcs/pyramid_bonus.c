/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:43:31 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 14:18:28 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		pyramidtosquare(t_scene *scene, t_pyramid *py)
{
	py->sq = (t_square *)ft_calloc(1, sizeof(t_square));
	py->sq->origin = vec_mul_const(py->origin, 1);
	py->sq->normal = vec_create(0, 1, 0);
	py->sq->color = vec_mul_const(py->color, 1);
	py->sq->size = py->size * 2;
	hitlst_add(scene->obj, (void *)py->sq, OBJ_SQUARE);
}

void		pyramidtotriangle_2(t_scene *scene, t_pyramid *py)
{
	t_vec	*tmp;

	py->tri3 = (t_triangle *)ft_calloc(1, sizeof(t_triangle));
	py->tri4 = (t_triangle *)ft_calloc(1, sizeof(t_triangle));
	py->tri3->color = vec_mul_const(py->color, 1);
	tmp = vec_create(py->size, 0, -py->size);
	py->tri3->p1 = vec_add_apply(tmp, py->origin);
	tmp = vec_create(-py->size, 0, -py->size);
	py->tri3->p2 = vec_add_apply(tmp, py->origin);
	tmp = vec_create(0, py->size, 0);
	py->tri3->p0 = vec_add_apply(tmp, py->origin);
	py->tri4->color = vec_mul_const(py->color, 1);
	tmp = vec_create(-py->size, 0, -py->size);
	py->tri4->p1 = vec_add_apply(tmp, py->origin);
	tmp = vec_create(-py->size, 0, py->size);
	py->tri4->p2 = vec_add_apply(tmp, py->origin);
	tmp = vec_create(0, py->size, 0);
	py->tri4->p0 = vec_add_apply(tmp, py->origin);
	hitlst_add(scene->obj, (void *)py->tri3, OBJ_TRIANGLE);
	hitlst_add(scene->obj, (void *)py->tri4, OBJ_TRIANGLE);
}

void		pyramidtotriangle(t_scene *scene, t_pyramid *py)
{
	t_vec	*tmp;
	double	size;

	size = py->size;
	py->tri1 = (t_triangle *)ft_calloc(1, sizeof(t_triangle));
	py->tri2 = (t_triangle *)ft_calloc(1, sizeof(t_triangle));
	py->tri1->color = vec_mul_const(py->color, 1);
	tmp = vec_create(-py->size, 0, py->size);
	py->tri1->p1 = vec_add_apply(tmp, py->origin);
	tmp = vec_create(py->size, 0, py->size);
	py->tri1->p2 = vec_add_apply(tmp, py->origin);
	tmp = vec_create(0, py->size, 0);
	py->tri1->p0 = vec_add_apply(tmp, py->origin);
	py->tri2->color = vec_mul_const(py->color, 1);
	tmp = vec_create(py->size, 0, py->size);
	py->tri2->p1 = vec_add_apply(tmp, py->origin);
	tmp = vec_create(py->size, 0, -py->size);
	py->tri2->p2 = vec_add_apply(tmp, py->origin);
	tmp = vec_create(0, py->size, 0);
	py->tri2->p0 = vec_add_apply(tmp, py->origin);
	hitlst_add(scene->obj, (void *)py->tri1, OBJ_TRIANGLE);
	hitlst_add(scene->obj, (void *)py->tri2, OBJ_TRIANGLE);
	pyramidtotriangle_2(scene, py);
}
