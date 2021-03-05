/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 09:09:49 by hekang            #+#    #+#             */
/*   Updated: 2021/03/05 14:08:54 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int             cylinder_hit_2(void *obj, t_ray *r, t_hit_record *rec)
{
    t_cylinder  *cy;
    t_vec       *oc;
    t_cy_set    c;
    t_vec       *p;
    t_vec       *normal;

    cy = (t_cylinder *)obj;
    oc = vec_sub(r->orig, cy->origin);
    c.a = vec_dot(r->dir, r->dir) - pow(vec_dot(r->dir, cy->normal), 2);
    c.b = 2 * (vec_dot(r->dir, oc) - vec_dot(r->dir, cy->normal) * vec_dot(oc, cy->normal));
    c.c = vec_dot(oc, oc) - pow(vec_dot(oc, cy->normal), 2) - pow(cy->diameter / 2, 2);
    c.discriminant = pow(c.b, 2) - 4 * c.a * c.c;
    if (c.discriminant < 0.00001)
        return (FALSE);
    c.root = (-c.b + pow(c.discriminant, 0.5)) / 2 / c.a;
    if (c.root < rec->t_min || c.root > rec->t_max)
            return (FALSE);
    p = ray_at(r, c.root);
    c.cp = vec_sub(p, cy->origin);
    normal = vec_unit(vec_sub(p, vec_add(cy->origin, vec_mul_const(cy->normal, vec_dot(c.cp, cy->normal)))));
    // rec->p = vec_add(rec->p, vec_mul_const(rec->normal, -0.000001));
    if ((0 < vec_dot(c.cp, cy->normal)) && (vec_dot(c.cp, cy->normal) < cy->height))
    {
        rec->t = c.root;
        rec->p = ray_at(r, c.root);
        rec->normal = normal;
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
    t_vec       *p;
    t_vec       *normal;

    cy = (t_cylinder *)obj;
    cy->normal = vec_unit(cy->normal);
    oc = vec_sub(r->orig, cy->origin);
    c.a = vec_dot(r->dir, r->dir) - pow(vec_dot(r->dir, cy->normal), 2);
    c.b = 2 * (vec_dot(r->dir, oc) - vec_dot(r->dir, cy->normal) * vec_dot(oc, cy->normal));
    c.c = vec_dot(oc, oc) - pow(vec_dot(oc, cy->normal), 2) - pow(cy->diameter / 2, 2);
    c.discriminant = pow(c.b, 2) - 4 * c.a * c.c;
    if (c.discriminant < 0.00001)
        return (FALSE);
    c.root = (-c.b - pow(c.discriminant, 0.5)) / 2 / c.a;
    if (c.root < rec->t_min || c.root > rec->t_max)
        return (FALSE);
    // rec->t = c.root;
    // rec->p = ray_at(r, c.root);
    p = ray_at(r, c.root);
    c.cp = vec_sub(p, cy->origin);
    normal = vec_unit(vec_sub(p, vec_add(cy->origin, vec_mul_const(cy->normal, vec_dot(c.cp, cy->normal)))));
    // p = vec_add(rec->p, vec_mul_const(normal, -0.000001));
    if ((0 < vec_dot(c.cp, cy->normal)) && (vec_dot(c.cp, cy->normal) < cy->height))
    {
        rec->t = c.root;
        rec->p = ray_at(r, c.root);
        rec->normal = normal;
        rec->color = cy->color;
        return (TRUE);
    }
    return (FALSE);
}