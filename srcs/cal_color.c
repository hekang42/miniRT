/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:48:50 by hekang            #+#    #+#             */
/*   Updated: 2021/03/08 14:25:57 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


/*
    I = kd * Ll * cos = kd * Ll * N dot L
*/
t_vec               *diffuse_color(t_light *light, t_hit_record *rec)
{
    t_vec           *color;
    double          kd;
    t_vec           *L;
    t_vec           *N;

    kd = light->ratio;
    L = vec_unit(vec_sub(light->origin, rec->p));
    N = rec->normal;
    color = vec_mul_const(light->color, 
        vec_dot(L, N) * light->ratio * kd);
    return (vec_div_const(clamp_vec(color, 0, 255), 255.0));
}

t_vec               *specular_color(t_light *light, t_hit_record *rec)
{
    t_vec           *color;
    double          ks;
    t_vec           *R;
    t_vec           *V;
    t_vec           *L;
    t_vec           *L_rev;
    double          reflection;

    ks = light->ratio;
    V = vec_unit(vec_sub(rec->p, rec->ray->orig));
    L = vec_sub(light->origin, rec->p);
    L_rev = vec_sub(rec->p, light->origin);
    R = vec_unit(vec_add(L_rev, vec_mul_const(rec->normal, 2 * clamp(vec_dot(L, rec->normal), 0, INFINITY))));
    reflection = 0;
    if (vec_dot(V, R) < 0)
        reflection = pow(vec_dot(V, R), 100);
    color = vec_mul_const(light->color, reflection * ks);
    return (vec_div_const(clamp_vec(color, 0, 255), 255.0));
}

t_vec       *ambient_color(t_scene *scene)
{
    return(vec_mul_const(scene->ambient->color, scene->ambient->ratio / 255.0));
}

int         lightlst_hit(t_scene *scene, t_list *lst, t_hit_record *rec)
{
    t_vec   *color;
    t_light *light;
    t_vec   *diffuse;
    t_vec   *specular;

    color = rec->color;
    diffuse = vec_create(0, 0, 0);
    specular = vec_create(0, 0, 0);
    while (lst && lst->content)
    {
        light = (t_light *)(lst->content);
        if (!in_shadow(scene, light, rec))
        {
            diffuse = vec_add(diffuse, diffuse_color(light, rec));
            specular = vec_add(specular, specular_color(light, rec));
        }
        lst = lst->next;
    }
    color = vec_mul_each(color, vec_add(diffuse, specular));
    vec_add_apply(color, vec_mul_each(rec->color, ambient_color(scene)));
    return (get_color(color));
}