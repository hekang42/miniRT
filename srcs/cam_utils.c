/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:26:06 by hekang            #+#    #+#             */
/*   Updated: 2021/03/05 16:31:36 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list          *init_camlst()
{
    t_list      *result;

    result = (t_list *)malloc(sizeof(t_list));
    result->content = NULL;
    result->next = NULL;
    return (result);
}

void            camlst_add(t_scene *scene, t_camera *cam)
{
    t_list  *begin;
    int     cnt;

    cnt = scene->n_cam;
    begin = scene->cam;
    if (scene->cam->content)
    {
        while (cnt--)
            scene->cam = scene->cam->next;
        scene->cam->next = init_camlst();
        scene->cam->next->content = cam;
        scene->cam->next->next = begin;
    }
    else
    {
        scene->cam->content = cam;
        scene->cam->next = scene->cam;
    }
    cam->data = create_img_data(scene->img->width, scene->img->height);
    scene->cam = begin;
}

// void            camlst_add(t_list *lst, t_camera *cam)
// {
//     if (lst->content == NULL)
//     {
//         printf("1\n");
//         // lst = init_camlst();
//         lst->content = cam;
//         lst->next = lst;
//     }
//     else 
//     {
//         printf("2\n");
//         // while (lst->next)
//         //     lst = lst->next;
//         lst->next = init_camlst();
//         lst->next->content = cam;
//         lst->next->next = lst;
//     }
//     // lst->content = cam;
// }

void			set_camera_llc(t_camera *cam, t_vec *lookat)
{
	t_vec		*tmp;

	vec_div_const_apply(cam->horizontal, 2.0);
	vec_div_const_apply(cam->vertical, 2.0);
	tmp = vec_add(cam->horizontal, cam->vertical);
	vec_add_apply(tmp, lookat);
	cam->lower_left_corner = vec_sub(cam->origin, tmp);
	free(tmp);
	vec_mul_const_apply(cam->horizontal, 2.0);
	vec_mul_const_apply(cam->vertical, 2.0);
}

t_camera        *init_cam(t_scene *scene, t_vec *lookfrom, t_vec *lookat, double hfov)
{
    t_camera    *result;
    double      view_h;
    double      view_w;
    t_vec       *vup;

	lookat = vec_unit(vec_mul_const_apply(lookat, -1.0));
    vup = vec_create(0, 1, 0);
	if (vec_is_parallel(vup, lookat))
	{
		free(vup);
		vup = vec_create(1, 0, 0);
	}
    result = (t_camera *)malloc(sizeof(t_camera));

    result->normal = lookat;
    result->fov = hfov;
    view_w = 2 * tan(hfov / 2.0);
    view_h = view_w / (scene->img->width) * scene->img->height;
    result->horizontal = vec_unit(vec_cross(vup, lookat));
	result->vertical = vec_mul_const_apply(
							vec_cross(lookat, result->horizontal), view_h);
	vec_mul_const_apply(result->horizontal, view_w);
	result->origin = lookfrom;
    set_camera_llc(result, lookat);
    // result->lower_left_corner = vec_sub(result->origin, vec_create(view_w / 2, view_h / 2, view_w / (2 * tan(vfov / 2.0 * PI /180 ))));

	// set_camera_llc(result, lookat);
	free(lookat);
	return (result);
}

t_camera        *create_cam(double aspect_ratio)
{
    t_camera    *result;
    double      viewport_height;
    double      viewport_width;
    double      focal_length;

    result = (t_camera *)malloc(sizeof(t_camera));
    focal_length = 1.0;
    viewport_height = 30.0;
    viewport_width = viewport_height * aspect_ratio;
    result->origin = vec_create(0, 0, 0);
    result->horizontal = vec_create(viewport_width, 0, 0);
    result->vertical = vec_create(0, viewport_height, 0);
    result->lower_left_corner = vec_sub(result->origin, vec_create(viewport_width / 2, viewport_height / 2, focal_length));
    //result->lower_left_corner = vec_sub(result->origin, vec_create((result->horizontal->x) / 2, result->vertical->y / 2, focal_length));
    return (result);
}