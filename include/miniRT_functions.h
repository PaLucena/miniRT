/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:43:22 by palucena          #+#    #+#             */
/*   Updated: 2024/02/08 20:07:44 by palucena         ###   ########.fr       */
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

//	parser_utils.c
char		*par_clean_id(char *line);

//	save_amb.c
void		par_save_amb(char *line, t_info *info);

//	save_extras.c
void		ft_save_rgb(t_color *color, char *str, t_info *info);
void		ft_save_point(t_point *point, char *str, t_info *info);
void		ft_save_vector(t_vector *vector, char *str, t_info *info);
int			cy_save_hei(char *line, int start, t_properties *prop,
				t_info *info);

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
void		ft_keyhook(void *param);
void		ft_resizehook(int32_t new_w, int32_t new_h, void *param);

//inter_sphere.c
t_inter		*inter_sp(t_shape *sp, t_vector ray, t_point origin);

//inter_plane.c
t_inter		*inter_pl(t_shape *pl, t_vector ray, t_point origin);

//inter_cylinder.c
t_inter		*inter_cy(t_shape *pl, t_vector ray, t_point origin);

//	inter_cylinder2.c
t_inter		*cy_cap_coll(t_circle *top, t_circle *bot, t_vector ray, t_point orig);

//inter_utils.c
double		quadratic_equation(t_quad *quad);
t_point		plane_point_coords(t_info *in, double i, double j);
t_point		inter_point_coords(t_point origin, t_inter *inter, t_vector cc);

//	pixels.c
t_inter		*get_closest_collision(t_vector ray, t_point origin, t_info *info);
void		put_pixels(t_info *info);

//	light.c
void		ft_phong(t_inter *inter, t_info *info, t_pixel px);

//	light_utils.c
uint32_t	get_rgba(t_color color);
int			ft_cl_clamp(double unclamped);
t_color		add_color(t_color c1, t_color c2);
void		ft_darkness(t_info *info, double x, double y);

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
t_vector	v_matrix_product(t_vector v, t_matrix m);

//	vector_utils3.c
t_vector	v_opposite_vec(t_vector orig);
t_point		v_get_endpoint(t_vector vector, double d, t_point orig);

//	camera.c
void		set_camera(t_cset *c);
t_vector	camera_ray_direction(t_info *in, t_pixel px);

//	vector_point_color.c
t_point		v_to_p(t_vector v);
t_vector	p_to_v(t_point p);
t_vector	c_to_v(t_color c);
t_color		v_to_c(t_vector v);

#endif