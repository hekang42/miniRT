/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 09:09:49 by hekang            #+#    #+#             */
/*   Updated: 2021/02/21 00:56:41 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int             cylinder_cap_hit(void *obj, t_ray *r, t_hit_record *rec)
{
    t_cylinder  *cy;
    double      denominator;
    double      t;
    t_vec       *oc;
    t_vec       *max_origin;

    cy = (t_cylinder *)obj;
    max_origin = vec_add(vec_mul_const(cy->normal, cy->height), cy->origin);
    denominator = vec_dot(cy->normal, r->dir);
    if (fabs(denominator)< 0.000001)
        return (FALSE);
    oc = vec_sub(cy->origin, r->orig);
    t = vec_dot(oc, cy->normal) / denominator;
    if (t < rec->t_min || t > rec->t_max)
        return (FALSE);
    rec->p = ray_at(r, t);

    if (vec_len(vec_sub(rec->p, cy->origin)) < cy->diameter / 2 ||
    vec_len(vec_sub(rec->p, max_origin)) < cy->diameter / 2)
    {
        rec->t = t;
        rec->normal = vec_unit(cy->normal);
        rec->color = cy->color;
        return (TRUE);
    }
    return (FALSE);
}

int             cylinder_hit(void *obj, t_ray *r, t_hit_record *rec)
{
    t_cylinder  *cy;
    t_vec       *oc;
    t_cy_set    c;

    cy = (t_cylinder *)obj;
    oc = vec_sub(r->orig, cy->origin);
    c.a = vec_dot(r->dir, r->dir) - pow(vec_dot(r->dir, cy->normal), 2);
    c.b = 2 * (vec_dot(r->dir, oc) - vec_dot(r->dir, cy->normal) * vec_dot(oc, cy->normal));
    c.c = vec_dot(oc, oc) - pow(vec_dot(oc, cy->normal), 2) - pow(cy->diameter / 2, 2);
    c.discriminant = pow(c.b, 2) - 4 * c.a * c.c;
    if (c.discriminant < 0.00001)
        return (FALSE);
    c.root = (-c.b + pow(c.discriminant, 0.5)) / 2 / c.a;
    // if (c.root < (-c.b - pow(c.discriminant, 0.5)) / 2 / c.a)
    //     c.root = (-c.b - pow(c.discriminant, 0.5)) / 2 / c.a;
    if (c.root < rec->t_min || c.root > rec->t_max)
    {
        // c.root = (-c.b - pow(c.discriminant, 0.5)) / 2 / c.a;
        // if (c.root < rec->t_min || c.root > rec->t_max)
            return (FALSE);
    }
    // if ((-c.b - pow(c.discriminant, 0.5) < rec->t_min)
        if ((-c.b - pow(c.discriminant, 0.5)) / 2 / c.a < rec->t_min)
        return (FALSE);
    rec->t = c.root;
    rec->p = ray_at(r, c.root);
    c.cp = vec_sub(rec->p, cy->origin);
    rec->color = cy->color;
    rec->normal = vec_unit(vec_sub(rec->p, cy->origin));
    // set_face_normal(r, rec);
    if ((0 <= vec_dot(c.cp, cy->normal)) && (vec_dot(c.cp, cy->normal) <= cy->height))
        return (TRUE);
    return (FALSE);
}

int             cylinder_hit_2(void *obj, t_ray *r, t_hit_record *rec)
{
    t_cylinder  *cy;
    t_vec       *oc;
    t_cy_set    c;

    cy = (t_cylinder *)obj;
    oc = vec_sub(r->orig, cy->origin);
    c.a = vec_dot(r->dir, r->dir) - pow(vec_dot(r->dir, cy->normal), 2);
    c.b = 2 * (vec_dot(r->dir, oc) - vec_dot(r->dir, cy->normal) * vec_dot(oc, cy->normal));
    c.c = vec_dot(oc, oc) - pow(vec_dot(oc, cy->normal), 2) - pow(cy->diameter / 2, 2);
    c.discriminant = pow(c.b, 2) - 4 * c.a * c.c;
    if (c.discriminant < 0.00001)
        return (FALSE);
    c.root = (-c.b - pow(c.discriminant, 0.5)) / 2 / c.a;
    // if (c.root > (-c.b - pow(c.discriminant, 0.5)) / 2 / c.a)
    //     c.root = (-c.b - pow(c.discriminant, 0.5)) / 2 / c.a;
    if (c.root < rec->t_min || c.root > rec->t_max)
    {
        c.root = (-c.b - pow(c.discriminant, 0.5)) / 2 / c.a;
        // if (c.root < rec->t_min || c.root > rec->t_max)
        //     return (FALSE);
    }
    // if ((-c.b - pow(c.discriminant, 0.5) < rec->t_min)
        if ((-c.b + pow(c.discriminant, 0.5)) / 2 / c.a < rec->t_min)
        return (FALSE);
    
    rec->t = c.root;
    rec->p = ray_at(r, c.root);
    c.cp = vec_sub(rec->p, cy->origin);
    rec->color = cy->color;
    rec->normal = vec_unit(vec_sub(rec->p, cy->origin));
    if ((0 <= vec_dot(c.cp, cy->normal)) && (vec_dot(c.cp, cy->normal) <= cy->height))
        return (TRUE);
    return (FALSE);
}