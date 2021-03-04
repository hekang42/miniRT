/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:15:37 by hekang            #+#    #+#             */
/*   Updated: 2021/03/04 11:18:20 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int         triangle_hit(void *obj, t_ray *r, t_hit_record *rec)
{
    t_triangle      *tr;
    t_vec           *v0v1;
    t_vec           *v0v2;
    t_vec           *pvec;
    double          det;
    double          invdet;
    t_vec           *tvec;
    double          u;
    double          v;
    t_vec           *qvec;

    tr = (t_triangle *)obj;
    v0v1 = vec_sub(tr->p1, tr->p0);
    v0v2 = vec_sub(tr->p2, tr->p0);
    pvec = vec_cross(r->dir, v0v2);
    det = vec_dot(v0v1, pvec);
    // printf("det : %f \n", det);
    if (fabs(det) < 0.00000001)
        return (FALSE);
    invdet = 1 / det;
    tvec = vec_sub(r->orig, tr->p0);
    u = vec_dot(tvec, pvec) * invdet;
    qvec = vec_cross(tvec, v0v1);
    v = vec_dot(r->dir, qvec) * invdet;
    // printf("u : %f \n", u);
    // printf("v : %f \n", v);
    if ((u < 0 || u > 1) || (v < 0 || u + v > 1))
        return (FALSE);
    rec->t = vec_dot(v0v2, qvec) * invdet;
    rec->color = tr->color;
    rec->p = ray_at(r, rec->t);
    rec->normal = vec_unit(vec_cross(v0v1, v0v2));
	// set_face_normal(r, rec, TRUE);
    rec->p = vec_add(rec->p, vec_mul_const(rec->normal, 0.0000001));

    // printf( "\n\n 11\n");
    return (TRUE);
}