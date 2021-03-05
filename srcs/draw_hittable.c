/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hittable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:18:41 by hekang            #+#    #+#             */
/*   Updated: 2021/03/05 15:48:41 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
    I = kd * Ll * cos = kd * Ll * N dot L
*/
t_vec               *diffuse_color(t_scene *scene, t_hit_record *rec)
{
    t_vec           *color;
    double          kd;
    t_vec           *L;
    t_vec           *N;

    kd = 1;
    // L = vec_unit(vec_sub(rec->p, scene->light->origin));
    L = vec_unit(vec_sub(scene->light->origin, rec->p));
    N = rec->normal;
    color = vec_mul_const(scene->light->color, 
        vec_dot(L, N) * scene->light->ratio * kd);
    return (clamp_vec(color, 0, 255));
}

t_vec               *specular_color(t_scene *scene, t_hit_record *rec)
{
    t_vec           *color;
    double          ks;
    t_vec           *R;
    t_vec           *V;
    t_vec           *L;
    t_vec           *L_rev;
    double          reflection;

    ks = scene->light->ratio;
    V = vec_unit(vec_sub(rec->p, rec->ray->orig));
    L = vec_sub(scene->light->origin, rec->p);
    L_rev = vec_sub(rec->p, scene->light->origin);
    R = vec_unit(vec_add(L_rev, vec_mul_const(rec->normal, 2 * clamp(vec_dot(L, rec->normal), 0, INFINITY))));
    reflection = 0;
    if (vec_dot(V, R) < 0)
        reflection = pow(vec_dot(V, R), 200);
    color = vec_mul_const(scene->light->color, reflection * ks);
    return (clamp_vec(color, 0, 255));
}

int                 cal_hittable_color(t_scene *scene, t_hit_record *rec)
{
    t_vec           *ambient;
    int             result;
    t_vec           *diffuse; 
    t_vec           *specular;

    result = 0;
    ambient = vec_create(0,0,0);
    if (hitlst_hit(scene->obj, rec))
    {
        diffuse = diffuse_color(scene, rec);
        // diffuse = vec_create(0,0,0);
        specular = specular_color(scene, rec);
        // specular = vec_create(0,0,0);
        ambient = vec_add(rec->color, vec_mul_const(scene->ambient->color, scene->ambient->ratio));
        // ambient = vec_create(0,0,0);
        
        result = get_color(vec_add(vec_add(diffuse, specular), ambient));

        // free(diffuse);
        // free(specular);
        // free(ambient);
        if (in_shadow(scene, rec))
            return(get_color(ambient));
    }
    return (result);
}

t_ray               *camera_get_ray(t_camera *cam, double u, double v)
{
    t_vec           *tmp;
    t_vec           *tmp2;

    tmp2 = vec_mul_const(cam->horizontal, u);
    tmp = vec_add(cam->lower_left_corner, tmp2);
    free(tmp2);  
    tmp2 = vec_mul_const(cam->vertical, v);
    vec_add_apply(tmp, tmp2);
    free(tmp2);
    vec_sub_apply(tmp, cam->origin);
    return (create_ray(cam->origin, tmp));
}

void                draw_hittable(t_scene *scene)
{
    int             x;
    int             y;
    double          u;
    double          v;
    t_hit_record    *rec;
    int n = 0;

    y = scene->img->height;
    while (n < scene->n_cam)
    {
        while ((--y) >= 0)
        {
            x = -1;
            while ((++x) < scene->img->width)
            {
                u = (double)x / (scene->img->width - 1);
                v = (double)y / (scene->img->height - 1);
                rec = hit_record_new();
                rec->ray = camera_get_ray(scene->cam->content, u, v);
                ((t_camera *)(scene->cam->content))->data->img[x][y] =
                    cal_hittable_color(scene, rec);
                free_hit_record(rec);
            }
        }
        scene->cam = scene->cam->next;
        y = scene->img->height;
        n++;
    }
}
