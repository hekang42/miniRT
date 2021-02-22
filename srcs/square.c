/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:59:16 by hekang            #+#    #+#             */
/*   Updated: 2021/02/22 18:07:25 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec           *vec_orient(t_vec *a, t_vec *n)
{
    t_vec t;
    t_vec *t_r;
    t_vec *tmp;
    // radian = t * 3.141592 / 180;
    t.x = (n->x) * PI;
    t.y = (n->y) * PI;
    t.z = (n->z) * PI;
    t_r = vec_create(0,0,0);
    tmp = vec_create(0,0,0);
    //x orient
    t_r->x = a->x;
    t_r->y = a->y * cos(t.x) - a->z * sin(t.x);
    t_r->z = a->y * sin(t.x) + a->z * cos(t.x);
    //z orient
    tmp->x = t_r->x * cos(t.z) - t_r->y * sin(t.z);
    tmp->y = t_r->x * sin(t.z) + t_r->y * cos(t.z);
    tmp->z = t_r->z;
    //y orient
    t_r->x = tmp->x * cos(t.y) + tmp->z * sin(t.y);
    t_r->y = tmp->y;
    t_r->z = -1 * tmp->x * sin(t.y) + tmp->z * cos(t.y);

    return (t_r);
}

int             vec_each_len(t_vec *a, double l, t_vec *n)
{
    t_vec *t_r;
    double f;
    t_vec *n_x;
    t_vec *n_y;
    t_vec *n_z;
    t_vec *n_o;

    t_r = vec_orient(a, n);
    n_x = vec_orient(vec_create(1,0,0), n);
    n_y = vec_orient(vec_create(0,1,0), n);
    n_z = vec_orient(vec_create(0,0,1), n);
    n_o = vec_orient(vec_create(1,0,1), n);
    // if ((fabs(t_r->x) <= l && fabs(t_r->y) <= l && fabs(t_r->z) <= l)
    f = pow(2, 0.5) / pow(3, 0.5);
    // if ((fabs(t_r->x) <= pow(2, -0.5) * l && fabs(t_r->y) <= pow(2, -0.5) * l && fabs(t_r->z) <= pow(2, -0.5) * l)
    // if ((fabs(t_r->x) <= f * l && fabs(t_r->y) <= f * l && fabs(t_r->z) <= f * l)
    // if ((fabs(t_r->x) <= l && fabs(t_r->y) <= l && fabs(t_r->z) <= l)
    // if ((vec_dot(t_r, vec_create(n->x, 0, 0)) <= l)
    // && (vec_dot(t_r, vec_create(0, n->y, 0)) <= l)
    // && (vec_dot(t_r, vec_create(0, 0, n->z)) <= l)
    // if ((fabs(t_r->x) + fabs(t_r->y) + fabs(t_r->z) <= 2 * l)
    // if ((vec_len((vec_cross(t_r, n))) < l))
    if (((vec_dot(t_r, n_x) < l) && (vec_dot(t_r, n_y) < l) && (vec_dot(t_r, n_z) <l))
    && (vec_dot(t_r, n_o))
    // && ((a->x < l) && (a->y < l) && (a->z <l))
    // && (vec_len((vec_cross(vec_create(t_r->x, t_r->y, 0), vec_create(0, t_r->y,t_r->z)))) < pow(l, 2))
    // && (vec_len((vec_cross(vec_create(0, t_r->y, t_r->z), vec_create(t_r->x, t_r->y,0)))) < pow(l, 2))
    // && (vec_len((vec_cross(vec_create(t_r->x, 0, t_r->z), vec_create(0, t_r->y,t_r->z)))) < pow(l, 2)))
    && (vec_len(t_r) <= pow(2, 0.5) * l))
    // && (pow(pow(t_r->x, 2) + pow(t_r->y, 2) + pow(t_r->z, 2), 0.5) <= pow(2, 0.5) * l))
        return (TRUE);
    return (FALSE);
}

int             square_hit(void *obj, t_ray *r, t_hit_record *rec)
{
    double      denominator; //분모
    t_square    *sq;
    t_vec       *oc;
    double      t;

    sq = ((t_square *)obj);
    denominator = vec_dot(sq->normal, r->dir);
    if (fabs(denominator) < 0.000001)
        return (FALSE); 
    oc = vec_sub(sq->origin, r->orig);
    t = vec_dot(oc, sq->normal) / denominator;
    if (t < rec->t_min || t > rec->t_max)
        return (FALSE);
    rec->p = ray_at(r, t);
    /*
        사각형 
        법선벡터와 수직하는 평면을 구하고
        중심점에서 각 축(xyz)의 길이의 합이 사이즈 / 2 인 점들.
    */
    if (vec_each_len(vec_sub(rec->p, sq->origin), sq->size / 2, sq->normal))
    {
        rec->t = t;
        rec->normal = vec_unit(sq->normal);
        rec->color = sq->color;
        return (TRUE);
    }
    return (FALSE);
}