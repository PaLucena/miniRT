/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:43:22 by palucena          #+#    #+#             */
/*   Updated: 2024/02/01 11:19:24 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINRT_FUNCTIONS_H
# define MINRT_FUNCTIONS_H

# include "miniRT_structs.h"

//	main.c
void		ft_print_error(char *str, t_info *info);

//	init.c
t_info		*init_info(char *filename);
void		init_mlx(t_info	*info);

//	parser.c
void		ft_parser(t_info *info);

//	save_amb.c
void		par_save_amb(char *line, t_info *info);

//	save_extras.c
void		ft_save_rgb(t_color *color, char *str, t_info *info);
void		ft_save_point(t_point *point, char *str, t_info *info);
void		ft_save_vector(t_vector *vector, char *str, t_info *info);
int			cy_save_hei(char *line, int start, t_properties *prop, t_info *info);

//	save_camera.c
void		par_save_camera(char *line, t_info *info);

//	save_light.c
void		par_save_light(char *line, t_info *info);

//	scene_list_tools.c
t_shape		*shapes_newnode(t_type type, int last_idx);
void		shapes_addback(t_shape *root, t_shape *node);
int			shapes_get_last_idx(t_shape *root);

//	save_sphere.c
void		par_save_sphere(char *line, t_info *info);

//	save_plane.c
void		par_save_plane(char *line, t_info *info);

//	save_cylinder.c
void		par_save_cylinder(char *line, t_info *info);

//	exit.c
void		ft_exit_program(void *param);

//	mlx_hooks.c
void		khook_debug(struct mlx_key_data keydata, void *param);
void		ft_keyhook(void *param);
void		ft_resizehook(int32_t new_w, int32_t new_h, void *param);

//inter_sphere.c
double		distance_sp(t_info *info, t_shape *sp, t_vector ray, bool a);
t_inter		*inter_sp(t_info *in, t_shape *sp, t_pixel px, bool a);

//inter_plane.c
double		distance_pl(t_info *info, t_shape *pl, t_vector ray);
t_inter		*inter_pl(t_info *in, t_shape *pl, t_pixel px);

//inter_cylinder.c
double		distance_cy(t_info *info, t_shape *cy, t_vector ray);
t_inter		*inter_cy(t_info *in, t_shape *cy, t_pixel px);

//inter_utils.c
double		quadratic_equation(double a, double b, double c);
t_point		plane_point_coords(t_info *in, double i, double j);
t_point		inter_point_coords(t_info *in, t_inter *inter, t_vector cc, int type);

//	pixels.c
t_inter		*get_closest_collision(t_pixel px, t_info *info, bool a);
void		put_pixels(t_info *info);

//	light.c
void		ft_phong(t_inter *inter, t_info *info, t_pixel px);
void		ft_darkness(t_info *info, double x, double y);
int			ft_cl_clamp(double unclamped);

//	light_diffuse.c
t_color		diffuse_light(t_info *in, t_inter *inter, t_shape *sh);
//t_color		ph_idiffuse(t_color a_c, t_info *info, t_shape *sh, t_inter c);

//	vector_utils.c
t_vector	v_mult(t_vector a, t_vector b);
t_vector	v_sum(t_vector a, t_vector b);
t_vector	v_unitary(t_vector a);
t_vector	v_get_from2(t_point from, t_point to);
t_vector	v_esc_mult(t_vector orig, double escalar);

//	vector_utils2.c
t_vector	v_norm(t_vector v);
double		v_mod(t_vector v);
double		v_dot_product(t_vector v1, t_vector v2);
t_vector	v_cross_product(t_vector v1, t_vector v2);
t_vector	v_matrix_product(t_point v, t_matrix m);

//	camera.c
void		set_camera(t_cset *c);
t_vector	camera_ray_direction(t_info *in, t_pixel px);

//	vector_point.c
t_point		v_to_p(t_vector v);
//t_vector	p_to_v(t_point p);

#endif