/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:04:48 by hekang            #+#    #+#             */
/*   Updated: 2021/03/04 15:35:24 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# define DIFFUSE 0
# define METAL 1

# define SP 0
# define LIGHT 1
# define PL	2
# define SQ 3
# define CY 4
# define TR 5
# define CB 6
# define PM 7
# define CAM 11

#include "libft.h"

typedef struct      s_img_data
{
    int             **img;
    int             width;
    int             height;
}                   t_img_data;

typedef struct      s_vec
{
    double          x;
    double          y;
    double          z;
}                   t_vec;

typedef struct      s_camera
{
    t_img_data      *data;
    t_vec           *origin;
    t_vec           *lower_left_corner;
    t_vec           *horizontal;
    t_vec           *vertical;
    t_vec           *normal;
    double          fov;
}                   t_camera;

typedef struct      s_sphere
{
    t_vec           *center;
    double          radius;
    t_vec           *color;
}                   t_sphere;

typedef struct		s_sp_set
{
	t_vec		*oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;
}                   t_sp_set;

typedef struct      s_plane
{
    t_vec           *p;
    t_vec           *normal;
    t_vec           *albedo;
}                   t_plane;

typedef struct      s_ray
{
    t_vec           *orig;
    t_vec           *dir;
}                   t_ray;

typedef struct		    s_material
{
	int             	type;
    t_vec               *color;
	double  			option1;
}                       t_material;

typedef struct          s_hit_record
{
    t_vec               *p;
    t_vec               *normal;
	int            	    *obj;
	// t_material	        *material;
    t_vec               *color;
    t_ray               *ray;
    double              t_min;
    double              t_max;
    double              t;
    int                 is_front_face;
}                       t_hit_record;


// typedef struct          s_hitlst_info
// {
//     t_ray               *ray;
//     double              t_min;
//     double              t_max;
//     double              a;
//     double              b;
//     double              root_d;
//     t_hit_record        *rec;
// }                       t_hitlst_info;

typedef struct      s_hittable
{
    void            *obj;
    int             obj_type;
    int             (*hit)(void *s, t_ray *r, t_hit_record *);
}                   t_hittable;

typedef struct			s_mlx_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_mlx_data;

typedef struct      s_vars
{
    void            *mlx;
    void            *win;
}                   t_vars;

typedef struct      s_light
{
    t_vec           *origin;
    double          ratio;
    t_vec           *color;
    double          a_ratio;
    t_vec           *a_color;
}                   t_light;

typedef struct      s_ambient
{
    double           ratio;
    t_vec           *color;
}                   t_ambient;

typedef struct      s_scene
{
    t_img_data      *img;
    t_list          *cam;
    t_ambient       *ambient;
    t_light         *light;
    t_list          *obj;
    int             n_cam;
}                   t_scene;

typedef struct      s_triangle
{
    t_vec           *p0;
    t_vec           *p1;
    t_vec           *p2;
    t_vec           *color;
}                   t_triangle;

typedef struct      s_square
{
    t_vec           *origin;
    t_vec           *normal;
    double          size;
    t_vec           *color;
    t_vec           *p1;
    t_vec           *p2;
}                   t_square;

typedef struct      s_cylinder
{
    t_vec           *origin;
    t_vec           *normal;
    double          diameter;
    double          height;
    t_vec           *color;
}                   t_cylinder;

typedef struct      s_cy_set
{
    double          a;
    double          b;
    double          c;
    double          discriminant;
    double          root;
    t_vec           *cp;
    double          t1;
    double          t2;
}                   t_cy_set;

#endif