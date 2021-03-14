/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:04:48 by hekang            #+#    #+#             */
/*   Updated: 2021/03/12 17:46:21 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include "libft.h"

typedef struct		s_img_data
{
	int				**img;
	int				width;
	int				height;
}					t_img_data;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_camera
{
	t_img_data		*data;
	t_vec			*origin;
	t_vec			*lower_left_corner;
	t_vec			*horizontal;
	t_vec			*vertical;
	t_vec			*normal;
	double			fov;
}					t_camera;

typedef struct		s_sphere
{
	t_vec			*center;
	t_vec			*color;
	double			radius;
}					t_sphere;

typedef struct		s_sp_set
{
	t_vec			*oc;
	double			a;
	double			half_b;
	double			c;
	double			discriminant;
	double			sqrtd;
	double			root;
}					t_sp_set;

typedef struct		s_plane
{
	t_vec			*p;
	t_vec			*normal;
	t_vec			*color;
}					t_plane;

typedef struct		s_ray
{
	t_vec			*orig;
	t_vec			*dir;
}					t_ray;

typedef struct		s_hit_record
{
	t_vec			*p;
	t_vec			*normal;
	t_vec			*color;
	t_ray			*ray;
	int				*obj;
	double			t_min;
	double			t_max;
	double			t;
}					t_hit_record;

typedef struct		s_hittable
{
	void			*obj;
	int				obj_type;
	int				(*hit)(void *s, t_ray *r, t_hit_record *);
}					t_hittable;

typedef struct		s_mlx_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_mlx_data;

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
}					t_vars;

typedef struct		s_light
{
	t_vec			*origin;
	double			ratio;
	t_vec			*color;
	double			a_ratio;
	t_vec			*a_color;
}					t_light;

typedef struct		s_ambient
{
	double			ratio;
	t_vec			*color;
}					t_ambient;

typedef struct		s_scene
{
	t_img_data		*img;
	t_ambient		*ambient;
	t_list			*cam;
	t_list			*light;
	t_list			*obj;
	int				n_cam;
}					t_scene;

typedef struct		s_triangle
{
	t_vec			*p0;
	t_vec			*p1;
	t_vec			*p2;
	t_vec			*color;
}					t_triangle;

typedef struct		s_tri_set
{
	t_vec			*v0v1;
	t_vec			*v0v2;
	t_vec			*pvec;
	t_vec			*tvec;
	t_vec			*qvec;
	double			det;
	double			invdet;
}					t_tri_set;

typedef struct		s_square
{
	t_vec			*origin;
	t_vec			*normal;
	t_vec			*color;
	double			size;
}					t_square;

typedef struct		s_cylinder
{
	t_vec			*origin;
	t_vec			*normal;
	t_vec			*color;
	double			diameter;
	double			height;
}					t_cylinder;

typedef struct		s_cy_set
{
	double			a;
	double			b;
	double			c;
	double			discriminant;
	double			root;
	double			t1;
	double			t2;
	t_vec			*cp;
}					t_cy_set;

typedef struct		s_frame_saver
{
	unsigned char	*buf;
	size_t			index;
	size_t			size;
}					t_frame_saver;

typedef struct		s_draw_var
{
	int				x;
	int				y;
	double			u;
	double			v;
	int				n;
}					t_draw_var;

typedef struct		s_specular_var
{
	t_vec			*r;
	t_vec			*v;
	t_vec			*l;
	t_vec			*l_rev;
	double			reflection;
}					t_specular_var;
#endif
