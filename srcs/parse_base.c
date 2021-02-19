/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:52:39 by hekang            #+#    #+#             */
/*   Updated: 2021/02/19 15:16:50 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int     parse_resolution(t_scene *scene, char *line)
{
    char    **s;

    s = ft_split(line, ' ');
    if (ft_atoi(s[1]) && ft_atoi(s[2]) && !s[3])
        scene->img = create_img_data(ft_atoi(s[1]), ft_atoi(s[2]));
    else
    {
        printf("ERROR : Init RESOLUTION\n");
        return (0);
    }
    return (1);
}

int     parse_ambient(t_scene *scene, char *line)
{
    char    **s;
    char    **c;
    t_vec   *color;

    s = ft_split(line, ' ');
    c = ft_split(s[2], ',');
    if ((s == 0 || c == 0) && !s[3])
    {
        printf("ERROR : Init AMBIENT\n");
        return (0);
    }
    color = vec_create(ft_atod(c[0]), ft_atod(c[1]), ft_atod(c[2]));
    scene->ambient = init_ambient(ft_atod(s[1]),color); 
    return (1);
}

int     parse_camera(t_scene *scene, char *line)
{
    char    **s;
    char    **lookfrom;
    char    **looknormal;
    t_vec   *from;
    t_vec   *normal;

    s = ft_split(line, ' ');
    lookfrom = ft_split(s[1], ',');
    looknormal = ft_split(s[2], ',');
    if ((s == 0 || lookfrom == 0 || looknormal == 0) && !s[3])
    {
        printf("ERROR : Init Camera\n");
        return (0);
    }
    scene->n_cam++;
    from = vec_create(ft_atoi(lookfrom[0]), ft_atoi(lookfrom[1]), ft_atoi(lookfrom[2]));
    printf("\nx : %f / y : %f / z : %f \n", from->x, from->y , from->z);
    printf("n_cam : %d \n", scene->n_cam);
    normal = vec_create(ft_atod(looknormal[0]), ft_atod(looknormal[1]), ft_atod(looknormal[2]));
    camlst_add(scene, init_cam(scene, from, normal, ft_atod(s[3]) * PI / 180.0));
    return (1);
}

int     parse_light(t_scene *scene, char *line)
{
    char    **s;
    char    **vec_tmp;
    double  ratio;
    t_vec   *origin;
    t_vec   *color;

    s = ft_split(line, ' ');
    vec_tmp = ft_split(s[1], ',');
    origin = vec_create(ft_atoi(vec_tmp[0]), ft_atoi(vec_tmp[1]), ft_atoi(vec_tmp[2]));
    ratio = ft_atod(s[2]);
    vec_tmp = ft_split(s[3], ',');
    color = vec_create(ft_atoi(vec_tmp[0]), ft_atoi(vec_tmp[1]), ft_atoi(vec_tmp[2]));
    scene->light = init_light(origin, ratio, color);
    return (1);
}
