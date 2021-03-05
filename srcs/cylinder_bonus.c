/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:03:43 by hekang            #+#    #+#             */
/*   Updated: 2021/03/05 10:28:06 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int             draw_circle(t_vec *a, double r, t_vec *n)
{
    t_vec       *n_x;
    t_vec       *n_y;
    t_vec       *vup;
    t_vec       len;

    vup = vec_create(1, 0, 0);
    if (vec_is_parallel(vup, n))
        vup = vec_create(0, 1, 0);
    n_x = vec_unit(vec_cross(vup, n));
    n_y = vec_unit(vec_cross(n, n_x));
    len.x = fabs(vec_dot(a, n_x));
    len.y = fabs(vec_dot(a, n_y));
    if (len.x * len.x + len.y * len.y < r * r)
        return (TRUE);
    return (FALSE);
}


int             cylinder_hit_top_cap(void *obj, t_ray *r, t_hit_record *rec)
{
    t_cylinder      *cy;
    double          denominator;
    t_vec           *oc;
    double          t;
    t_vec           *c;
    t_vec           *p;

    cy = (t_cylinder *)obj;
    cy->normal = vec_unit(cy->normal);
    denominator = vec_dot(cy->normal, r->dir);
    if (fabs(denominator) < 0.000001)
        return (FALSE);
    c = vec_add(cy->origin, vec_mul_const(cy->normal, cy->height));
    oc = vec_sub(c, r->orig);
    t = vec_dot(oc, cy->normal) / denominator;
    if (t < rec->t_min || t > rec->t_max)
        return (FALSE);
    p = ray_at(r, t);
    if (draw_circle(vec_sub(p, c), cy->diameter / 2, cy->normal))
    {
        rec->p = p;
        rec->t = t;
        rec->normal = vec_unit(cy->normal);
        rec->color = cy->color;
        return (TRUE);
    }
    return (FALSE);
}

int             cylinder_hit_bottom_cap(void *obj, t_ray *r, t_hit_record *rec)
{
    t_cylinder      *cy;
    double          denominator;
    t_vec           *oc;
    double          t;
    t_vec           *c;
    t_vec           *p;

    cy = (t_cylinder *)obj;
    cy->normal = vec_unit(cy->normal);
    c = cy->origin;
    denominator = vec_dot(cy->normal, r->dir);
    if (fabs(denominator) < 0.000001)
        return (FALSE);
    oc = vec_sub(c, r->orig);
    t = vec_dot(oc, cy->normal) / denominator;
    if (t < rec->t_min || t > rec->t_max)
        return (FALSE);
    p = ray_at(r, t);
    if (draw_circle(vec_sub(p, c), cy->diameter / 2, cy->normal))
    {
        rec->p = p;
        rec->t = t;
        rec->normal = vec_unit(cy->normal);
        rec->color = cy->color;
        return (TRUE);
    }
    return (FALSE);
}