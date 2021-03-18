/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:00:32 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 19:55:15 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define PI 3.14159265358917932385
# define OBJ_SPHERE 1
# define OBJ_PLANE 2
# define OBJ_TRIANGLE 3
# define OBJ_SQUARE 4
# define OBJ_CYLINDER 5
# define OBJ_CYLINDER_2 6
# define OBJ_CYLINDER_CAP 7
# define OBJ_CYLINDER_CAP_2 8
# define OBJ_SPHERE_CHECKER 9
# define OBJ_SPHERE_RAINBOW 10
# define OBJ_SQUARE_CHECKER 11
# define OBJ_CYLINDER_RAINBOW 12
# define OBJ_CYLINDER_RAINBOW_2 13
# define OBJ_CONE 14
# define ANTI_SAMPLES 1
# define REFLECT_DEPTH 5
# define X_KEY_PRESS 2
# define X_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17

# define TRUE 1
# define FALSE 0
# define HIT_T_MIN 0.001

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "minirt_struct.h"
# include "get_next_line.h"
# include "libft.h"

t_img_data		*create_img_data(int width, int height);
void			mlx_show(t_vars vars, t_mlx_data *img, t_img_data *data);
void			*free_img_data(t_img_data *data);
t_camera		*camera_locate(double aspect_ratio);
t_sphere		*init_sphere(t_vec *center, double radius, t_vec *color);
void			hitlst_add(t_list *lst, void *obj, int obj_type);
void			free_hitlst(t_list *lst);
t_hittable		*hittable_create(void *obj, int obj_type);
void			free_hittable(t_hittable *h);
int				sphere_hit(void *s, t_ray *r, t_hit_record *rec);
void			free_sphere(t_sphere *s);
t_vec			*vec_create(double x, double y, double z);
t_vec			*vec_add_apply(t_vec *a, t_vec *b);
t_vec			*vec_sub_apply(t_vec *a, t_vec *b);
t_vec			*vec_mul_const_apply(t_vec *a, double c);
t_vec			*vec_div_const_apply(t_vec *a, double c);
t_vec			*vec_add(t_vec *a, t_vec *b);
t_vec			*vec_sub(t_vec *a, t_vec *b);
t_vec			*vec_mul_const(t_vec *a, double c);
t_vec			*vec_div_const(t_vec *a, double c);
t_vec			*vec_mul_each(t_vec *a, t_vec *b);
double			vec_dot(t_vec *u, t_vec *v);
double			vec_len(t_vec *u);
double			vec_len_sqrt(t_vec *u);
t_vec			*vec_cross(t_vec *u, t_vec *v);
t_vec			*vec_unit(t_vec *u);
t_hit_record	*hit_record_new(void);
void			reset_hit_record(t_hit_record *rec);
void			free_hit_record(t_hit_record *rec, int n);
int				hitlst_hit(t_list *lst, t_hit_record *rec);
void			hit_set_normal(t_hit_record *record, t_ray *r);
void			draw_hittable(t_scene *scene);
void			color_map(void *mlx, void *win, int w, int h);
t_vec			*ray_at(t_ray *ray, double t);
t_ray			*create_ray(t_vec *origin, t_vec *direction);
void			free_ray(t_ray *ray, int is_ray_free);
double			clamp(double x, double min, double max);
int				get_color(t_scene *scene, t_vec *color);
t_vec			*ray_color(t_ray *r);
t_camera		*create_cam(double aspect_ratio);
void			draw_sky(t_img_data *data, t_camera *cam);
int				plane_hit(void *s, t_ray *r, t_hit_record *rec);
t_plane			*init_plane(t_vec *p, t_vec *normal, t_vec *albedo);
t_light			*init_light(t_vec *ori, double ratio, t_vec *color);
t_ambient		*init_ambient(double ratio, t_vec *color);
t_camera		*init_cam(t_scene *scene, t_vec *lookfrom,
				t_vec *lookat, double hfov);
int				vec_is_parallel(t_vec *a, t_vec *b);
t_scene			*parse(char *rt_file);
int				parse_resolution(t_scene *scene, char *line);
int				parse_ambient(t_scene *scene, char *line);
int				parse_camera(t_scene *scene, char *line);
int				parse_light(t_scene *scene, char *line);
int				parse_plane(t_scene *scene, char *line);
int				parse_sphere(t_scene *scene, char *line);
int				parse_triangle(t_scene *scene, char *line);
int				parse_square(t_scene *scene, char *line);
int				parse_cylinder(t_scene *scene, char *line);
int				parse_cylinder_2(t_scene *scene, char *line);
t_list			*init_list();
void			camlst_add(t_scene *scene, t_list *lst, t_camera *cam);
void			mlx_draw_by_img_data(t_mlx_data *mlx_data,
				t_img_data *img_data);
t_ray			*camera_get_ray(t_camera *cam, double u, double v);
int				cal_hittable_color(t_scene *scene, t_hit_record *rec);
int				triangle_hit(void *obj, t_ray *r, t_hit_record *rec);
void			set_face_normal(t_ray *r, t_hit_record *rec);
t_vec			*clamp_vec(t_vec *vec, double min, double max);
int				in_shadow(t_scene *scene, t_light *light, t_hit_record *rec);
int				square_hit(void *obj, t_ray *r, t_hit_record *rec);
int				cylinder_hit(void *obj, t_ray *r, t_hit_record *rec);
int				cylinder_hit_2(void *obj, t_ray *r, t_hit_record *rec);
int				cylinder_hit_top_cap(void *obj, t_ray *r, t_hit_record *rec);
int				cylinder_hit_bottom_cap(void *obj, t_ray *r,
				t_hit_record *rec);
int				lightlst_hit(t_scene *scene, t_list *lst, t_hit_record *rec);
void			lightlst_add(t_list *lst, t_vec *ori, double ratio,
				t_vec *color);
int				save_first_frame(t_scene *scene, t_img_data *img,
				char *filename);
void			free_array(void **s);
void			free_scene(t_scene *scene);
void			free_obj_list(t_list *list);
void			free_object(t_hittable *obj);
void			free_cam(t_camera *cam);
void			free_cam_list(t_list *list);
void			free_light(t_light *light);
void			free_light_list(t_list *list);
void			free_sphere(t_sphere *sp);
void			free_plane(t_plane *pl);
void			free_square(t_square *sq);
void			free_cylinder(t_cylinder *cy);
void			free_triangle(t_triangle *tr);
t_vec			*vec_unit_apply(t_vec *u);
void			cubetosquare(t_scene *scene, t_cube *cube);
void			cubetosquare_2(t_scene *scene, t_cube *cube);
void			cubetosquare_3(t_scene *scene, t_cube *cube);
int				parse_cube(t_scene *scene, char *line);
int				parse_pyramid(t_scene *scene, char *line);
void			pyramidtotriangle(t_scene *scene, t_pyramid *py);
void			pyramidtosquare(t_scene *scene, t_pyramid *py);
void			get_sphere_uv(t_hit_record *rec);
void			get_square_uv(t_hit_record *rec, t_square *sq);
int				uv_sphere_hit(void *obj, t_ray *r, t_hit_record *rec);
t_sp_set		set_sphere_var(t_sphere *sp, t_ray *r);
int				parse_bonus(t_scene *scene, char *line);
int				sphere_hit_checker(void *obj, t_ray *r, t_hit_record *rec);
t_scene			*init_scene(void);
int				parse_sphere_checker(t_scene *scene, char *line);
int				parse_sphere_rainbow(t_scene *scene, char *line);
int				parse_cylinder_rainbow(t_scene *scene, char *line);
int				sphere_hit_rainbow(void *obj, t_ray *r, t_hit_record *rec);
int				vec_each_len(t_vec *a, double l, t_vec *n, t_hit_record *rec);
int				square_hit_checker(void *obj, t_ray *r, t_hit_record *rec);
int				parse_square_checker(t_scene *scene, char *line);
t_cy_set		set_cylinder_var(t_cylinder *cy, t_ray *r, int type);
int				cylinder_hit_rainbow(void *obj, t_ray *r, t_hit_record *rec);
int				cylinder_hit_rainbow_2(void *obj, t_ray *r, t_hit_record *rec);
int				parse_filter(t_scene *scene, char *line);
double			ft_random(void);
void			draw_hittable_anti(t_scene *scene);
int				parse_antialiasing(t_scene *scene, char *line);
int				parse_cone(t_scene *scene, char *line);
int				cone_hit(void *obj, t_ray *r, t_hit_record *rec);
void			parse_check(char **s, int n, char *type);
void			free_2(void *a, void *b);
void			free_3(void *a, void *b, void *c);
void			free_4(void *a, void *b, void *c, void *d);
t_vec			*vec_add_apply_free(t_vec *a, t_vec *b);
int				mlx_key_handle(int keycode);
int				change_camera(void);
void			mlx_hook_utils(t_vars vars);
t_list			*draw_scene(t_scene *scene);
t_list			*dup_img(t_scene *scene);
int				check_arg(int argc, char **argv);

#endif
