/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hittable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:18:41 by hekang            #+#    #+#             */
/*   Updated: 2021/03/08 10:27:49 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int                 cal_hittable_color(t_scene *scene, t_hit_record *rec)
{
    int             result;

    result = 0;
    if (hitlst_hit(scene->obj, rec))
        result = lightlst_hit(scene, scene->light, rec);
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
