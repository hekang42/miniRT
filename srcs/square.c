/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:59:16 by hekang            #+#    #+#             */
/*   Updated: 2021/02/20 22:01:37 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
int             vec_each_len(t_vec *a, double l, t_vec *n)
{
    t_vec t;
    t_vec *t_r;
    t_vec *tmp;

    // t.x = (n->x) * 180 / PI;
    // t.y = (n->y) * 180 / PI;
    // t.z = (n->z) * 180 / PI;
    
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
    if ((fabs(t_r->x) < l && fabs(t_r->y) < l && fabs(t_r->z) < l)
    && (pow(pow(fabs(t_r->x), 2) + pow(fabs(t_r->y), 2) + pow(fabs(t_r->z), 2), 0.5) <= pow(2, 0.5) * l))
        return (TRUE);
    
    return (FALSE);
}

int             vec_each_len_add(t_vec *a, double l)
{
    if (pow(pow(fabs(a->x), 2) + pow(fabs(a->y), 2) + pow(fabs(a->z), 2), 0.5) < pow(2, 0.5) * l / 2)
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

    // if (vec_each_len(vec_sub(rec->p, sq->origin), sq->size / 2) 
    if (vec_each_len(vec_sub(rec->p, sq->origin), sq->size / 2, sq->normal))
    // && vec_each_len_add(vec_sub(rec->p, sq->origin), sq->size))
    // if (vec_each_len_add(vec_sub(rec->p, sq->origin), sq->size))
    {
        rec->t = t;
        rec->normal = vec_unit(sq->normal);
        rec->color = sq->color;
        return (TRUE);
    }
    return (FALSE);

}