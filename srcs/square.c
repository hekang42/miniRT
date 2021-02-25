/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:59:16 by hekang            #+#    #+#             */
/*   Updated: 2021/02/25 20:51:59 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec           *vec_orient(t_vec *a, t_vec *n)
{
    t_vec   t;
    t_vec   *t_r;
    t_vec   *tmp;
    // radian = t * 3.141592 / 180;

    t.x = -1 * (n->x) * PI;
    t.y = -1 * (n->y) * PI;
    t.z = -1 * (n->z) * PI;

    t.x = 0;
    t.y = 0;
    t.z = 0;

    if (n->x != 0)
        t.x = acos(vec_dot(vec_create(1, 0, 0), n) / vec_len(n));
    if (n->y != 0)
        t.y = acos(vec_dot(vec_create(0, 1, 0), n) / vec_len(n));
    if (n->z != 0)
        t.z = acos(vec_dot(vec_create(0, 0, 1), n) / vec_len(n));
    // if (n->z)
    //     t.x = atan(n->y/n->z);
    // if (n->x)
    //     t.y = atan(n->z/n->x);
    // if (n->y)
    //     t.z = atan(n->x/n->y);
// if (n->x == 0.5)
// {
    // printf("n %f %f %f\n", n->x, n->y, n->z);
    // printf("t %f %f %f\n", t.x / PI * 180, t.y / PI * 180, t.z / PI * 180);
// }

    t_r = vec_create(0,0,0);
    tmp = vec_create(0,0,0);
    
    //z orient
    t_r->x = a->x * cos(t.z) - a->y * sin(t.z);
    t_r->y = a->x * sin(t.z) + a->y * cos(t.z);
    t_r->z = a->z;
    //x orient
    tmp->x = t_r->x;
    tmp->y = t_r->y * cos(t.x) - t_r->z * sin(t.x);
    tmp->z = t_r->y * sin(t.x) + t_r->z * cos(t.x);
    //y orient
    t_r->x = tmp->x * cos(t.y) + tmp->z * sin(t.y);
    t_r->y = tmp->y;
    t_r->z = -1 * tmp->x * sin(t.y) + tmp->z * cos(t.y);
    return (t_r);
}

int             vec_each_len(t_vec *a, double l, t_vec *n)
{
    t_vec   *n_x;
    t_vec   *n_y;
    t_vec   *n_z;
    
    n_x = (vec_orient(vec_create(1,0,0), n));
    n_y = (vec_orient(vec_create(0,1,0), n));
    n_z = (vec_orient(vec_create(0,0,1), n));
    double x = fabs(vec_dot(a, n_x));
    double y = fabs(vec_dot(a, n_y));
    double z = fabs(vec_dot(a, n_z));

    // if ((fabs(vec_dot(a, n_x)) <= l) && (fabs(vec_dot(a, n_y)) <= l) && (fabs(vec_dot(a, n_z)) <= l))
    // if ((fabs(vec_dot(a, n_x)) <= l) && (fabs(vec_dot(a, n_y)) <= l) && (fabs(vec_dot(a, n_z)) <= l))
    if ((x <= l) && (y <= l) && (z <= l))
        // if (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) < sqrt(2) * l)
        // if (vec_len(a) < sqrt(2) * l)
        // if (sqrt(pow(x, 2) + pow(y, 2)) <= sqrt(2) * l)
        // if (sqrt(pow(x, 2) + pow(z, 2)) <= sqrt(2) * l)
        // if (sqrt(pow(y, 2) + pow(z, 2)) <= sqrt(2) * l)

        
        {
            if (vec_len(a) > sqrt(2) * l)
            {

                printf("vec_len :%f\n", vec_len(a));
                printf("x: %f y: %f z: %f\n", x, y, z);
            }
            return (TRUE);
        }
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
    if (vec_each_len( vec_sub(rec->p, sq->origin), sq->size / 2, sq->normal))
    {
        rec->t = t;
        rec->normal = vec_unit(sq->normal);
        rec->color = sq->color;
        return (TRUE);
    }
    return (FALSE);
}
