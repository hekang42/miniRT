/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:59:16 by hekang            #+#    #+#             */
/*   Updated: 2021/02/23 18:25:45 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec           *vec_orient(t_vec *a, t_vec *n)
{
    t_vec t;
    t_vec *t_r;
    t_vec *tmp;
    // radian = t * 3.141592 / 180;
    t.x = -1 * (n->x) * PI;
    t.y = -1 * (n->y) * PI;
    t.z = -1 * (n->z) * PI;
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
    
    


    // //x orient
    // t_r->x = a->x;
    // t_r->y = a->y * cos(t.x) - a->z * sin(t.x);
    // t_r->z = a->y * sin(t.x) + a->z * cos(t.x);
    // //z orient
    // tmp->x = t_r->x * cos(t.z) - t_r->y * sin(t.z);
    // tmp->y = t_r->x * sin(t.z) + t_r->y * cos(t.z);
    // tmp->z = t_r->z;
    // //y orient
    // t_r->x = tmp->x * cos(t.y) + tmp->z * sin(t.y);
    // t_r->y = tmp->y;
    // t_r->z = -1 * tmp->x * sin(t.y) + tmp->z * cos(t.y);
    return (t_r);
}

int             vec_each_len(t_vec *a, double l, t_vec *n)
{
    t_vec *t_r;
    t_vec *n_x;
    t_vec *n_y;
    t_vec *n_z;
    t_vec *n_o;
    t_vec *right_top;
    t_vec *right_bottom;
    t_vec *left_top;
    t_vec *left_bottom;
    // t_vec *reverse_n;
    n = vec_unit(n);

    t_r = vec_orient(a, n);
    // t_r = a;
    n_x = (vec_orient(vec_create(1,0,0), n));
    n_y = (vec_orient(vec_create(0,1,0), n));
    n_z = (vec_orient(vec_create(0,0,1), n));
    n_o = vec_unit(vec_orient(vec_create(1,1,1), n));

    // printf("n   %f %f %f\n", n->x, n->y, n->z);
    // printf("a   %f %f %f\n", a->x, a->y, a->z);
    // printf("t_r %f %f %f\n", t_r->x, t_r->y, t_r->z);

    // reverse_n = vec_mul_const(n, -1);
    // t_r = vec_orient(p, n);
    // printf("t_rr %f %f %f\n", t_r->x, t_r->y, t_r->z);

    right_top = vec_orient(vec_create(l, l, l), n);
    right_bottom = vec_orient(vec_create(a->x + l, a->y - l, a->z), n);
    left_top = vec_orient(vec_create(a->x - l, a->y + l, a->z), n);
    left_bottom = vec_orient(vec_create(-1 * l, -1 * l, -1 * l), n );

    // t_vec *x_min = vec_orient(vec_create(a->x - l, 0, 0), n);
    // t_vec *x_max = vec_orient(vec_create(a->x + l, 0, 0), n);
    // t_vec *y_min = vec_orient(vec_create(0, a->y + l, 0), n);
    // t_vec *y_max = vec_orient(vec_create(0, a->y - l, 0), n);
    // t_vec *z_min = vec_orient(vec_create(0, 0, a->z + l), n);
    // t_vec *z_max = vec_orient(vec_create(0, 0, a->z - l), n);
    // t_vec *ori_n = vec_orient(origin, n);

    // if ((fabs(t_r->x) <= l && fabs(t_r->y) <= l && fabs(t_r->z) <= l)
    // if ((fabs(t_r->x) <= pow(2, -0.5) * l && fabs(t_r->y) <= pow(2, -0.5) * l && fabs(t_r->z) <= pow(2, -0.5) * l)
    // if ((fabs(t_r->x) <= f * l && fabs(t_r->y) <= f * l && fabs(t_r->z) <= f * l)
    // if ((fabs(t_r->x) <= l && fabs(t_r->y) <= l && fabs(t_r->z) <= l)
    // if ((vec_dot(t_r, vec_create(n->x, 0, 0)) <= l)
    // && (vec_dot(t_r, vec_create(0, n->y, 0)) <= l)
    // && (vec_dot(t_r, vec_create(0, 0, n->z)) <= l)
    // if ((fabs(t_r->x) + fabs(t_r->y) + fabs(t_r->z) <= 2 * l)
    // if ((vec_len((vec_cross(t_r, n))) < l))

    // printf("n   %f %f %f\n", n->x, n->y, n->z);
    // printf("n_o   %f %f %f\n", n_o->x, n_o->y, n_o->z);

    // printf("n_x %f %f %f\n", n_x->x, n_x->y, n_x->z);
    // printf("n_y %f %f %f\n", n_y->x, n_y->y, n_y->z);
    // printf("n_z %f %f %f\n", n_z->x, n_z->y, n_z->z);
    // printf("n_x len : %f\n\n", vec_len(n_x));

    // if ((fabs(t_r->x) < fabs(right_top->x)) && (fabs(t_r->x) > fabs(left_bottom->x)) 
    // && (fabs(t_r->y) < fabs(right_top->y)) && (fabs(t_r->y) > fabs(left_bottom->y)) 
    // && (fabs(t_r->z) < fabs(right_top->z)) && (fabs(t_r->z) > fabs(left_bottom->z)))
    //     return (TRUE);
    // if (fabs(n->x) > 0)
    //     {if ((t_r->y < right_top->y) && (t_r->y > left_bottom->y) 
    //         && (t_r->z < right_top->z) && (t_r->z > left_bottom->z))
    //         return (TRUE);  }
    // else if (fabs(n->y) > 0)
    //     {if ((t_r->x < right_top->x) && (t_r->x > left_bottom->x) 
    //         && (t_r->z < right_top->z) && (t_r->z > left_bottom->z))
    //         return (TRUE);  }
    // else if (fabs(n->z) > 0)
    //     {if ((t_r->x < right_top->x) && (t_r->x > left_bottom->x) 
    //         && (t_r->y < right_top->y) && (t_r->y > left_bottom->y))
    //         return (TRUE);  }
    
    
    
    // if ((t_r->x < right_top->x) && (t_r->x > left_bottom->x) 
    // && (t_r->y < right_top->y) && (t_r->y > left_bottom->y) 
    // && (t_r->z < right_top->z) && (t_r->z > left_bottom->z))
    //     return (TRUE);
    // printf("rt     %f %f %f\n", right_top->x, right_top->y, right_top->z);
    // printf("origin %f %f %f\n", ori_n->x, ori_n->y, ori_n->z);


    // if ((fabs(vec_dot(t_r, n_x)) < l) && (fabs(vec_dot(t_r, n_y)) < l) && (fabs(vec_dot(t_r, n_z)) <l))
    // // && (fabs(vec_dot(t_r, n_x)) + fabs(vec_dot(t_r, n_y)) + fabs(vec_dot(t_r, n_z)) < 2 * l))
    // // && (!vec_dot(t_r, n_o))
    // // && ((a->x < l) && (a->y < l) && (a->z <l))
    // // && (vec_len((vec_cross(vec_create(t_r->x, t_r->y, 0), vec_create(0, t_r->y,t_r->z)))) < pow(l, 2))
    // // && (vec_len((vec_cross(vec_create(0, t_r->y, t_r->z), vec_create(t_r->x, t_r->y,0)))) < pow(l, 2))
    // // && (vec_len((vec_cross(vec_create(t_r->x, 0, t_r->z), vec_create(0, t_r->y,t_r->z)))) < pow(l, 2)))
    // // && (vec_len(t_r) <= pow(2, 0.5) * l))
    // // && (pow(pow(t_r->x, 2) + pow(t_r->y, 2) + pow(t_r->z, 2), 0.5) <= pow(2, 0.5) * l))
    // {
    //     printf("%f %f %f \n", vec_dot(t_r, n_x), vec_dot(t_r, n_y), vec_dot(t_r, n_z) );
    //     printf("len : %f\n", pow(vec_dot(t_r, n_x), 2) + pow(vec_dot(t_r, n_y), 2) + pow(vec_dot(t_r, n_z), 2));
    //     printf("\t\t%f \n", 2 * l * l);
    //     // if (pow(vec_dot(t_r, n_x), 2) + pow(vec_dot(t_r, n_y), 2) + pow(vec_dot(t_r, n_z), 2) < 2 * l * l)
    //     // if (vec_len(vec_cross(t_r, n)) <  pow(2, 0.5) * l)
    //         return (TRUE);
    // }

    // if ((fabs(n->x) == 0)
    //     && ((fabs(vec_dot(t_r, n_y)) < l) && (fabs(vec_dot(t_r, n_z)) < l)))
    //         return (TRUE);
    // else if ((fabs(n->y) == 0)
    //     && ((fabs(vec_dot(t_r, n_x)) < l) && (fabs(vec_dot(t_r, n_z)) < l)))
    //         return (TRUE);
    // else if ((fabs(n->z) == 0)
    //     && ((fabs(vec_dot(t_r, n_y)) < l) && (fabs(vec_dot(t_r, n_x)) < l)))
    //         return (TRUE);
    // else
// if (n->x == 0.5)
// {    printf("n : %f %f %f\n\n",n->x, n->y, n->z);
//     printf("n_x : %f %f %f\n", n_x->x, n_x->y, n_x->z);
//     printf("n_y : %f %f %f\n", n_y->x, n_y->y, n_y->z);
//     printf("n_z : %f %f %f\n", n_z->x, n_z->y, n_z->z);}

    // n_x = vec_create(fabs(n_x->x), fabs(n_x->y), fabs(n_z->z));
    // n_y = vec_create(fabs(n_y->x), fabs(n_y->y), fabs(n_y->z));
    // n_z = vec_create(fabs(n_z->x), fabs(n_z->y), fabs(n_z->z));

    if ((fabs(vec_dot(t_r, n_x)) < l) && (fabs(vec_dot(t_r, n_y)) < l) && (fabs(vec_dot(t_r, n_z)) < l))
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
    if (vec_each_len( vec_sub(rec->p, sq->origin), sq->size / 2, sq->normal))
    {
        rec->t = t;
        rec->normal = vec_unit(sq->normal);
        rec->color = sq->color;
        return (TRUE);
    }
    return (FALSE);
}