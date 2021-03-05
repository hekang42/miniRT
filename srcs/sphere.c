/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:15:49 by hekang            #+#    #+#             */
/*   Updated: 2021/03/05 11:15:44 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere        *init_sphere(t_vec *center, double radius, t_vec *color)
{
    t_sphere    *result;

    result = (t_sphere *)malloc(sizeof(t_sphere));
    result->center = center;
    result->radius = radius;
    result->color = color;
    return (result);
}

// int			check_sphere_hitrange(void *s, t_ray *r, t_hit_record *rec)
// {
// 	int		is_big_t;
// 	double	t;

// 	is_big_t = -1;
// 	while ((++is_big_t) < 2)
// 	{
// 		t = (-info->b / 2 + info->root_d * (is_big_t ? (1) : (-1))) / info->a;
// 		if (info->t_min < t && t < info->t_max)
// 		{
// 			if (rec->p)
// 				reset_hit_record(rec);
// 			rec->t = t;
// 			rec->p = ray_at(r, t);
// 			rec->normal = vec_sub(rec->p, ((t_sphere *)s)->center);
// 			vec_div_const_apply(rec->normal, ((t_sphere *)s)->radius);
// 			hit_set_normal(rec, r);
// 			// rec->mat = info->mat;
// 			return (TRUE);
// 		}
// 	}
// 	return (FALSE);
// }

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
    rec->is_front_face = vec_dot(r->dir, rec->normal) < 0;
    rec->normal = (rec->is_front_face) ? rec->normal : vec_mul_const(rec->normal, -1);
}

int         sphere_hit(void *obj, t_ray *r, t_hit_record *rec)
{
    t_sphere    *sp;
    t_sp_set    s;

    sp = ((t_sphere *)obj);
    s.oc = vec_sub(r->orig, sp->center);
    s.a = vec_dot(r->dir, r->dir);
    s.half_b = vec_dot(r->dir, s.oc);
    s.c = vec_dot(s.oc, s.oc) - pow(sp->radius, 2);
    s.discriminant = pow(s.half_b, 2) - s.a * s.c;
    //printf("disciminant: %f\n", s.discriminant);
    if (s.discriminant < 0.00001)
        return (FALSE);
    s.sqrtd = sqrt(s.discriminant);
    s.root = (-s.half_b - s.sqrtd) / s.a;
  	if (s.root < rec->t_min || s.root > rec->t_max)
	{
		s.root = (-s.half_b + s.sqrtd) / s.a;
		if (s.root < rec->t_min || s.root > rec->t_max)
			return (FALSE);
	}
    if ((-s.half_b + s.sqrtd) / s.a < rec->t_min 
        || (-s.half_b - s.sqrtd) / s.a < rec->t_min)
        return (FALSE);
    // 그림자 계산 . 자신과 겹쳤을때
    
    // printf("radius: %f\n", sp->radius );
    // printf("color x: %f\n", sp->color->x );
    // printf("color y: %f\n", sp->color->y );
    // printf("color z: %f\n", sp->color->z );
    rec->t = s.root;
    rec->p = ray_at(r, s.root);
    rec->normal = vec_unit(vec_sub(rec->p, sp->center));
    // rec->p = vec_sub(rec->p, vec_mul_const(rec->normal, 0.00001));
    rec->color = sp->color;
	// set_face_normal(r, rec);
    return (TRUE);
}