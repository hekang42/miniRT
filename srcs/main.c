/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:08:25 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 18:09:11 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list		*g_img_list;
t_mlx_data	*g_img;
t_vars		g_vars;

int				change_camera(void)
{
	t_img_data *data;

	if (g_img_list->next)
		g_img_list = g_img_list->next;
	data = g_img_list->content;
	mlx_draw_by_img_data(g_img, data);
	mlx_put_image_to_window(g_vars.mlx, g_vars.win, g_img->img, 0, 0);
	mlx_show(g_vars, g_img, data);
	return (1);
}

int				main(int argc, char *argv[])
{
	t_scene		*scene;
	t_vars		vars;
	t_img_data	*data;
	t_mlx_data	*img;
	t_list		*img_lst;

	if (!(check_arg(argc, argv)))
		return (0);
	scene = parse(argv[1]);
	img_lst = draw_scene(scene);
	data = img_lst->content;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, data->width, data->height, "miniRT");
	img = (t_mlx_data *)ft_calloc(1, sizeof(t_mlx_data));
	img->img = mlx_new_image(vars.mlx, data->width, data->height);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
					&(img->line_length), &(img->endian));
	g_vars = vars;
	g_img = img;
	g_img_list = img_lst;
	if (argc == 3)
		return (save_first_frame(scene, img_lst->content, "image.bmp"));
	free_scene(scene);
	mlx_show(vars, img, data);
	mlx_hook_utils(vars);
}
