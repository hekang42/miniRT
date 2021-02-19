/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:33:21 by hekang            #+#    #+#             */
/*   Updated: 2021/02/17 09:37:19 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void        mlx_draw_by_img_data(t_mlx_data *mlx_data, t_img_data *img_data)
{
    int         width;
    int         height;
    char        *dst;
    int         next;

    width = -1;
    while ((++width) < img_data->width)
    {
        height = -1;
        while ((++height) < img_data->height)
        {
            next = (img_data->height - height - 1) * mlx_data->line_length;
            next += width * (mlx_data->bits_per_pixel / 8);
            dst = mlx_data->addr + next;
            *(unsigned int*)dst = img_data->img[width][height];
        }
    }
}

// int				exit_program(void)
// {
// 	exit(0);
// 	return (0);
// }

// int            change_camera(t_scene *scene)
// {
//     t_img_data *data;
//     printf("\n\n%p\n\n", (scene));
//     printf("\n\n%p\n\n", (scene->cam));
//     printf("\n\n%p\n\n", (scene->cam->next));
//     printf("\n\n%p\n\n", (scene->cam->next->content));
//     data = ((t_camera *)(scene->cam->next->content))->data;
//     printf("aaaa\n");
//     mlx_draw_by_img_data(g_img, data);
//     printf("bbbb\n");
//     mlx_put_image_to_window(g_vars.mlx, g_vars.win, g_img->img, 0, 0);
//     printf("cccc\n");

//     mlx_show(g_vars, g_img, g_scene,  data);
//     return (1);
// }

// int				mlx_key_handle(int keycode)
// {
//     printf("keycode : %d\n", keycode);
// 	if (keycode == 53)
// 		return (exit_program());
//     if (keycode == 8) // c
//         return (change_camera(g_scene));
// 	return (0);
// }

// int     mouse_button_handle(int button, int x, int y, void *p)
// {
//         printf("Mouse_button in Win, button %d at %dx%d.\n", button, x, y); 
//         return ((int)p);
// }  

void            mlx_show(t_vars vars, t_mlx_data *img, t_img_data *data)
{
    // t_vars      vars;
    // t_mlx_data  *img;
    // t_img_data  *data;

    // data = (t_img_data *)((scene->cam)->content);
    // vars.mlx = mlx_init();
    // vars.win = mlx_new_window(vars.mlx, data->width, data->height, title);

    // img = (t_mlx_data *)malloc(sizeof(t_mlx_data));
    // img->img = mlx_new_image(vars.mlx, data->width, data->height);
    // img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
    //                 &(img->line_length), &(img->endian));
/*
**  mlx_get_data_addr()은 생성된 이미지에 대한 정보를 반환하며, 나중에 사용자가 수정할 수 있습니다. 
**  img_ptr 파라미터는 사용할 이미지를 지정합니다. 다음 3개의 파리미터는 3개의 서로 다른 유효한 정수의 주소입니다. 
**  bits_per_pixel은 픽셀의 색상을 표현하는데 필요한 비트의 수로 채워집니다(색 깊이(depth of the image)라고도 불립니다). 
**  size_line은 메모리 안에서 이미지 한 줄을 저장하는데 필요한 바이트의 수입니다. 이 정보는 이미지의 한 줄에서 다른 줄로
**  이동하는데 사용합니다. endian은 이미지의 픽셀 색상을 little (endian == 0) 또는 big (endian == 1)에 저장해야하는지 여부를 의미합니다.
 */
    mlx_draw_by_img_data(img, data);
    mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
    // mlx_destroy_image(vars.mlx, img->img);
    //color_map(vars.mlx, vars.win, 300, 300);
	// mlx_hook(vars.win, X_KEY_PRESS, 0, mlx_key_handle, 0);
    // mlx_mouse_hook(vars.win, mouse_button_handle, 0);
    // mlx_loop(vars.mlx);
    // free(img);
}

// void            mlx_show(t_img_data *data, char *title)
// {
//     t_vars      vars;
//     t_mlx_data  *img;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, data->width, data->height, title);

//     img = (t_mlx_data *)malloc(sizeof(t_mlx_data));
//     img->img = mlx_new_image(vars.mlx, data->width, data->height);
//     img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
//                     &(img->line_length), &(img->endian));
// /*
// **  mlx_get_data_addr()은 생성된 이미지에 대한 정보를 반환하며, 나중에 사용자가 수정할 수 있습니다. 
// **  img_ptr 파라미터는 사용할 이미지를 지정합니다. 다음 3개의 파리미터는 3개의 서로 다른 유효한 정수의 주소입니다. 
// **  bits_per_pixel은 픽셀의 색상을 표현하는데 필요한 비트의 수로 채워집니다(색 깊이(depth of the image)라고도 불립니다). 
// **  size_line은 메모리 안에서 이미지 한 줄을 저장하는데 필요한 바이트의 수입니다. 이 정보는 이미지의 한 줄에서 다른 줄로
// **  이동하는데 사용합니다. endian은 이미지의 픽셀 색상을 little (endian == 0) 또는 big (endian == 1)에 저장해야하는지 여부를 의미합니다.
//  */
//     mlx_draw_by_img_data(img, data);
//     mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
//     mlx_destroy_image(vars.mlx, img->img);
//     //color_map(vars.mlx, vars.win, 300, 300);
// 	mlx_hook(vars.win, X_KEY_PRESS, 0, mlx_key_handle, 0);
//     mlx_mouse_hook(vars.win, mouse_button_handle, 0);
//     mlx_loop(vars.mlx);
//     free(img);
// }