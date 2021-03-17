/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:08:25 by hekang            #+#    #+#             */
/*   Updated: 2021/03/17 11:57:00 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list		*g_img_list;
t_mlx_data	*g_img;
t_vars		g_vars;

int				exit_program(void)
{
	mlx_destroy_window(g_vars.mlx, g_vars.win);
	exit(0);
	return (0);
}

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

int				mlx_key_handle(int keycode)
{
	printf("keycode : %d\n", keycode);
	if (keycode == 53)
		return (exit_program());
	if (keycode == 8)
		return (change_camera());
	return (0);
}

int				mouse_button_handle(int button, int x, int y, void *p)
{
	printf("Mouse_button in Win, button %d at %dx%d.\n", button, x, y);
	return ((int)p);
}

int				**create_img(int width, int height)
{
	int			**result;
	int			w;
	int			h;

	w = -1;
	result = (int **)ft_calloc(width, sizeof(int *));
	while (++w < width)
	{
		result[w] = (int *)ft_calloc(height, sizeof(int));
		h = -1;
		while (++h < height)
			result[w][h] = 0;
	}
	return (result);
}

void			imglst_add(t_scene *scene, t_list *lst, int i)
{
	t_img_data	*img;
	int			x;
	int			y;
	t_list		*begin;

	img = create_img_data(scene->img->width, scene->img->height);
	begin = lst;
	y = scene->img->height;
	while (--y >= 0)
	{
		x = -1;
		while (++x < scene->img->width)
			img->img[x][y] = ((t_camera *)(scene->cam->content))->data->img[x][y];
	}
		printf("%d \n", i);
	{
	}
	if (lst->content)
	{
		while (i--)
			lst = lst->next;
		lst->next = init_list();
		lst->next->content = img;
		lst->next->next = begin;
	}
	else
	{
		lst->content = img;
		lst->next = lst;
	}
	scene->cam = scene->cam->next;
}

t_list			*dup_img(t_scene *scene)
{
	t_list		*lst;
	t_list		*begin;
	t_img_data	*img;
	int			x;
	int			y;
	t_list		*cam_begin;

	lst = init_list();
	cam_begin = scene->cam;
	begin = lst;
	while (scene->n_cam--)
	{
		img = create_img_data(scene->img->width, scene->img->height);
		y = scene->img->height;
		while (--y >= 0)
		{
			x = -1;
			while (++x < scene->img->width)
				img->img[x][y] = ((t_camera *)(scene->cam->content))->data->img[x][y];
		}
		if (lst->content)
		{
			lst->next = init_list();
			lst->next->content = img;
			lst->next->next = begin;
			lst = lst->next;
		}
		else
		{
			lst->content = img;
			lst->next = lst;
		}
		scene->cam = scene->cam->next;
	}
	lst = lst->next;
	scene->cam = cam_begin;
	return (lst);
}

int				main(int argc, char *argv[])
{
	t_scene		*scene;
	int			n;
	t_vars		vars;
	t_img_data	*data;
	t_mlx_data	*img;
	t_list		*img_lst;

	if (argc == 3)
	{
		if (!ft_strnstr(argv[2], "--save", 6))
		{
			printf("ERROR : Input Argument\n");
			return (0);
		}
	}
	if (argc != 2 && argc != 3)
	{
		printf("ERROR : Input Argument\n");
		return (0);
	}
	scene = parse(argv[1]);

	n = 0;
	if (scene->anti)
		draw_hittable_anti(scene);
	else
		draw_hittable(scene);
	img_lst = dup_img(scene);
	data = img_lst->content;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, data->width, data->height, "miniRT");
	printf("4444\n");
	img = (t_mlx_data *)ft_calloc(1, sizeof(t_mlx_data));
	img->img = mlx_new_image(vars.mlx, data->width, data->height);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
					&(img->line_length), &(img->endian));
	g_vars = vars;
	g_img = img;
	g_img_list = img_lst;
	if (argc == 3)
	{
		printf("starting save bmp\n");
		save_first_frame(img_lst->content, "image.bmp");
		printf("Complete save bmp\n");
		return (0);
	}
	free_scene(scene);
	mlx_show(vars, img, data);
	mlx_hook(vars.win, X_KEY_PRESS, 0, mlx_key_handle, 0);
	mlx_mouse_hook(vars.win, mouse_button_handle, 0);
	mlx_loop(vars.mlx);
}
