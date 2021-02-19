/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:00:21 by hekang            #+#    #+#             */
/*   Updated: 2021/02/19 09:17:54 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene     *init_scene()
{
    t_scene     *result;

    result = (t_scene *)malloc(sizeof(t_scene));
    result->n_cam = 0;
    return (result);
}

int         parse_base(t_scene *scene, char *line)
{
    while (line[0] == ' ')
        line++;
    if (ft_strnstr(line, "R ", 2))
        parse_resolution(scene, line);
    else if (ft_strnstr(line, "A ", 2))
        parse_ambient(scene, line);
    else if (ft_strnstr(line, "c ", 2))
        parse_camera(scene, line);
    else if (ft_strnstr(line, "l ", 2))
        parse_light(scene, line);
    else
        return (0);
    return (1);
}

int         parse_obj(t_scene *scene, char *line)
{
    while (line[0] == ' ')
        line++;
    if (ft_strnstr(line, "pl ", 3))
        parse_plane(scene, line);
    else if (ft_strnstr(line, "sp ", 3))
        parse_sphere(scene, line);
    else if (ft_strnstr(line, "sq ", 3))
        parse_square(scene, line);
    else if (ft_strnstr(line, "cy ", 3))
        parse_cylinder(scene, line);
    else if (ft_strnstr(line, "tr ", 3))
        parse_triangle(scene, line);
    else
        return (0);
    return (1);
}

void        parse_rt(t_scene *scene, char *line)
{
    if (parse_base(scene, line))
        return ;
    else if (parse_obj(scene, line))
        return ;
}

t_scene        *parse(char *rt_file)
{
    int         rd;
    int         fd;
    char        *line;
    t_scene     *scene;

    scene = init_scene();
    scene->obj = hitlst_new();
    scene->cam = init_camlst();
    fd = open(rt_file, O_RDONLY);
    if (fd < 0)
    {
        printf("ERROR : rt file path\n");
        close(fd);
        return (0);
    }
    rd = 1;
    while (rd)
    {
        rd = get_next_line(fd, &line);
        parse_rt(scene, line);
        free(line);
    }
    close(fd);
    return (scene);
}