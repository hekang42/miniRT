/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:02:49 by hekang            #+#    #+#             */
/*   Updated: 2021/03/16 15:06:57 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			cubetosquare(t_scene *scene, t_cube *cube)
{
	t_vec		*tmp;

	cube->sq1 = (t_square *)ft_calloc(1, sizeof(t_square));
	cube->sq2 = (t_square *)ft_calloc(1, sizeof(t_square));
	cube->sq3 = (t_square *)ft_calloc(1, sizeof(t_square));
	tmp = vec_create(cube->size / 2, 0, 0);
	cube->sq1->origin = vec_add(cube->origin, tmp);
	cube->sq1->normal = vec_create(1, 0, 0);
	cube->sq1->color = vec_mul_const(cube->color, 1);
	cube->sq1->size = cube->size;
	free(tmp);
	tmp = vec_create(cube->size / 2, 0, 0);
	cube->sq2->origin = vec_sub(cube->origin, tmp);
	cube->sq2->normal = vec_create(-1, 0, 0);
	cube->sq2->color = vec_mul_const(cube->color, 1);
	cube->sq2->size = cube->size;
	free(tmp);
	tmp = vec_create(0, cube->size / 2, 0);
	cube->sq3->origin = vec_add(cube->origin, tmp);
	cube->sq3->normal = vec_create(0, 1, 0);
	cube->sq3->color = vec_mul_const(cube->color, 1);
	cube->sq3->size = cube->size;
	free(tmp);
	hitlst_add(scene->obj, (void *)cube->sq1, OBJ_SQUARE);
	hitlst_add(scene->obj, (void *)cube->sq2, OBJ_SQUARE);
	hitlst_add(scene->obj, (void *)cube->sq3, OBJ_SQUARE);
}

void			cubetosquare_2(t_scene *scene, t_cube *cube)
{
	t_vec		*tmp;

	cube->sq4 = (t_square *)ft_calloc(1, sizeof(t_square));
	cube->sq5 = (t_square *)ft_calloc(1, sizeof(t_square));
	cube->sq6 = (t_square *)ft_calloc(1, sizeof(t_square));
	tmp = vec_create(0, cube->size / 2, 0);
	cube->sq4->origin = vec_sub(cube->origin, tmp);
	cube->sq4->normal = vec_create(0, -1, 0);
	cube->sq4->color = vec_mul_const(cube->color, 1);
	cube->sq4->size = cube->size;
	free(tmp);
	tmp = vec_create(0, 0, cube->size / 2);
	cube->sq5->origin = vec_add(tmp, cube->origin);
	cube->sq5->normal = vec_create(0, 0, 1);
	cube->sq5->color = vec_mul_const(cube->color, 1);
	cube->sq5->size = cube->size;
	free(tmp);
	tmp = vec_create(0, 0, cube->size / 2);
	cube->sq6->origin = vec_sub(cube->origin, tmp);
	cube->sq6->normal = vec_create(0, 0, -1);
	cube->sq6->color = vec_mul_const(cube->color, 1);
	cube->sq6->size = cube->size;
	free(tmp);
	hitlst_add(scene->obj, (void *)cube->sq4, OBJ_SQUARE);
	hitlst_add(scene->obj, (void *)cube->sq5, OBJ_SQUARE);
	hitlst_add(scene->obj, (void *)cube->sq6, OBJ_SQUARE);
}