/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:08:25 by hekang            #+#    #+#             */
/*   Updated: 2021/02/16 13:42:58 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene *g_scene;
t_mlx_data *g_img;
t_vars g_vars;


int				exit_program(void)
{
	exit(0);
	return (0);
}
int            change_camera(t_scene *scene)
{
    t_img_data *data;
    data = ((t_camera *)(scene->cam->next->content))->data;
    scene->cam = scene->cam->next;
    mlx_draw_by_img_data(g_img, data);
    mlx_put_image_to_window(g_vars.mlx, g_vars.win, g_img->img, 0, 0);

    mlx_show(g_vars, g_img, data);
    return (1);
}

int				mlx_key_handle(int keycode)
{
    printf("keycode : %d\n", keycode);
	if (keycode == 53)
		return (exit_program());
    if (keycode == 8) // c
        return (change_camera(g_scene));
	return (0);
}

int     mouse_button_handle(int button, int x, int y, void *p)
{
    printf("Mouse_button in Win, button %d at %dx%d.\n", button, x, y); 
    return ((int)p);
}  

int main(int argc, char *argv[])
{
    t_scene     *scene;
    int         n;
    t_vars      vars;
    t_img_data *data;
    t_mlx_data  *img;

    if (argc == 3)
    {
        if (ft_strnstr(argv[2], "--save", 6))
        //    save_bmp;
            argc = 1;
        else
        {
            printf("ERROR : Input Argument\n");
            return (0);
        }
    }
    if (argc == 1)
    {
        printf("ERROR : Input Argument\n");
        return (0);
    }
    argc = 1;
    scene = parse(argv[1]);
    n = 0;
    draw_hittable(scene);
    data = ((t_camera *)(scene->cam->content))->data;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, data->width, data->height, "miniRT");
    img = (t_mlx_data *)malloc(sizeof(t_mlx_data));
    img->img = mlx_new_image(vars.mlx, data->width, data->height);
    img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
                    &(img->line_length), &(img->endian));
    g_vars = vars;
    g_img = img;
    g_scene = scene;
    mlx_show(vars, img, data);
    mlx_hook(vars.win, X_KEY_PRESS, 0, mlx_key_handle, 0);
    mlx_mouse_hook(vars.win, mouse_button_handle, 0);
    mlx_loop(vars.mlx);
}
