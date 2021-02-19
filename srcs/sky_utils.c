/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:24:29 by hekang            #+#    #+#             */
/*   Updated: 2021/02/15 15:43:11 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int             get_color(t_vec *color)
{
    int         x;
    int         y;
    int         z;
    // xyz 가 1보다 클 경우 앞의 색상에 영향을 줌.
    x = clamp(color->x, 0, 255);
    y = clamp(color->y, 0, 255);
    z = clamp(color->z, 0, 255);
    return(x << 16 | y << 8 | z);
}

double             hit_sphere(t_vec *center, double radius, t_ray *r)
{
    double      discriminant;
    double      a;
    double      b;
    double      c;
    t_vec       *oc;

    oc = vec_sub(r->orig, center);
    a = vec_dot(r->dir, r->dir);
    b = 2.0 * vec_dot(r->dir, oc);
    c = vec_dot(oc, oc) - pow(radius, 2);
    discriminant = b * b - 4 * a * c;
    //return (discriminant > 0);
    if (discriminant < 0)
        return (-1.0);
    else
    {
        c = (-b - sqrt(discriminant)) / (2.0 * a);
        if (c < 0)
            c = (-b + sqrt(discriminant)) / (2.0 * a);
        return (c);
    }
}

t_vec           *ray_color(t_ray *r)
{
    double      t;
    t_vec       *unit_dir;
    t_vec       *tmp1;
    t_vec       *tmp2;
    t_vec       *N;

//    if (hit_sphere(vec_create(0, 0, -1), 0.5, r))
//        return (vec_create(0.5, 0.3, 1));    
    t = hit_sphere(vec_create(0, 0, -1), 0.5, r);
    if (t > 0.0)
    {
        tmp1 = ray_at(r, t);
        // N = vec_unit(vec_sub(tmp1, vec_create(0, 0, -1))); //center_point
        N = vec_unit(vec_sub( vec_create(0.15, 0.15, -0.8), tmp1)); //center_point
        // return (vec_mul_const(vec_create(2,2,2),vec_dot(N, tmp1)));

        // return (vec_mul_const(vec_create(N->z, N->z, N->z), N->z));
        //if (vec_dot(r->dir, N) < 0)
            // N = vec_mul_const_apply(N, -1);
        // N = vec_add(N, vec_create(1, 1, 1));
        // N = vec_mul_const_apply(N, 0.5); //radius

        //N = vec_mul_const_apply(N, 0.5);
        // return (N);
    }
    unit_dir = vec_unit(r->dir);
    t = 0.5 * (unit_dir->y + 1.0);
    tmp1 = vec_mul_const(vec_create(1.0, 1.0, 1.0), 1.0 - t);
    tmp2 = vec_mul_const(vec_create(0.5, 0.7, 1.0), t);
    return (vec_add(tmp1, tmp2));    
}


void	color_map(void *mlx, void *win,int w,int h)
{
  int	x;
  int	y;
  int	color;

  x = w;
  while (x--)
    {
      y = h;
      while (y--)
        {
          color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
	  	  mlx_pixel_put(mlx,win,x,y,color);
        }
    }
}

void        draw_sky(t_img_data *data, t_camera *cam)
{
    int     x;
    int     y;
    t_ray   *r;

    y = data->height;
    while (--y >= 0)
    {
        x = -1;
        while (++x < data->width)
        {
            double u;
            double v;

            u = (double)(x) / (data->width - 1);
            v = (double)(y) / (data->height - 1);
            r = create_ray(cam->origin
            ,   vec_add(vec_add(cam->lower_left_corner, vec_mul_const(cam->horizontal, u)), 
                        vec_sub(vec_mul_const(cam->vertical, v), cam->origin)));
            data->img[x][y] = get_color(ray_color(r));
        }
        //printf("data->img[%d][%d] = %d\n", x, y, data->img[x-1][y-1]);
    }
}