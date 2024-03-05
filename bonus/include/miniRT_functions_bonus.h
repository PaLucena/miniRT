/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_functions_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:43:22 by palucena          #+#    #+#             */
/*   Updated: 2024/03/05 18:34:07 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_FUNCTIONS_BONUS_H
# define MINIRT_FUNCTIONS_BONUS_H

# include "miniRT_structs_bonus.h"

//	main.c
void		ft_print_error(char *str, t_info *info);

//	init_bonus.c
t_info		*init_info(char *filename);
void		init_mlx(t_info	*info);

//	parser_bonus.c
void		ft_parser(t_info *info);

//	parser_utils_bonus.c
char		*par_clean_id(char *line);
void		par_options(char *id, char *line, t_info *info);

//	save_amb_bonus.c
void		par_save_amb(char *line, t_info *info);

//	save_extras_bonus.c
void		ft_save_rgb(t_color *color, char *str, t_info *info);
void		ft_save_point(t_point *point, char *str, t_info *info);
void		ft_save_vector(t_vector *vector, char *str, t_info *info);
int			cy_co_save_hei(char *line, int start, t_properties *prop,
				t_info *info);

//	save_camera_bonus.c
void		par_save_camera(char *line, t_info *info);

//	save_light_bonus.c
void		par_save_light(char *line, t_info *info);

//	save_light_utils_bonus.c
void		lset_add_node(t_info *info, t_lset *new);
t_lset		*lset_new_node(void);

//	scene_list_tools_bonus.c
t_shape		*shapes_newnode(t_type type, int last_idx);
void		shapes_addback(t_shape *root, t_shape *node);
int			shapes_get_last_idx(t_shape *root);
bool		sp_checkerboard_info(char *line, int i, t_properties *prop);

//	save_sphere_bonus.c
void		par_save_sphere(char *line, t_info *info);

//	save_plane_bonus.c
void		par_save_plane(char *line, t_info *info);

//	save_cylinder_bonus.c
void		par_save_cylinder(char *line, t_info *info);

//	exit_bonus.c
void		ft_exit_program(void *param);

//	mlx_hooks_bonus.c
void		ft_keyhook(void *param);
void		ft_resizehook(int32_t new_w, int32_t new_h, void *param);

//inter_sphere_bonus.c
t_inter		*inter_sp(t_shape *sp, t_vector ray, t_point origin);

//inter_plane_bonus.c
t_inter		*inter_pl(t_shape *pl, t_vector ray, t_point origin);

//inter_cylinder_bonus.c
t_inter		*inter_cy(t_shape *pl, t_vector ray, t_point origin);
t_inter		*cy_co_check_closest(t_inter *caps, t_inter *body);

//	inter_cylinder2_bonus.c
t_inter		*cy_cap_coll(t_circle *top, t_circle *bot,
				t_vector ray, t_point orig);
t_shape		*cy_circle_to_plane(t_circle *c);

//inter_utils_bonus.c
double		quadratic_equation(t_quad *quad);
t_point		plane_point_coords(t_info *in, double i, double j);
t_point		inter_point_coords(t_point origin, t_inter *inter, t_vector cc);

//	pixels_bonus.c
t_inter		*get_closest_collision(t_vector ray, t_point origin, t_info *info);
void		put_pixels(t_info *info);

//	color_bonus.c
void		ft_darkness(t_info *info, double x, double y);
void		ft_color(t_inter *inter, t_info *info, t_pixel px);

//	checkerboard_bonus.c
bool		checkerb_sp(t_shape *sh, t_point q, t_info *info);
bool		checkerb_pl(t_shape *sh, t_point q, t_info *info);
bool		checkerb_cy(t_shape *sh, t_point q, t_info *info);
//	light_bonus.c
void		ft_phong(t_inter *inter, t_info *info, t_pixel px, t_color color);

//	light_utils_bonus.c
uint32_t	get_rgba(t_color color);
int			ft_cl_clamp(double unclamped);
t_color		add_color(t_color c1, t_color c2);

//	vector_utils_bonus.c
t_vector	v_mult(t_vector a, t_vector b);
t_vector	v_sum(t_vector a, t_vector b);
t_vector	v_unitary(t_vector a);
t_vector	v_get_from2(t_point from, t_point to);
t_vector	v_esc_mult(t_vector orig, double escalar);

//	vector_utils2_bonus.c
t_vector	v_norm(t_vector v);
double		v_mod(t_vector v);
double		v_dot_product(t_vector v1, t_vector v2);
t_vector	v_cross_product(t_vector v1, t_vector v2);
t_vector	v_matrix_product(t_vector p, t_matrix m);

//	vector_utils3_bonus.c
t_vector	v_opposite_vec(t_vector orig);
t_point		v_get_endpoint(t_vector vector, double d, t_point orig);
double		v_magnitude(t_vector v);

//	camera_bonus.c
void		set_camera(t_cset *c);
t_vector	camera_ray_direction(t_info *in, t_pixel px);

//	vector_point_color_bonus.c
t_point		v_to_p(t_vector v);
t_vector	p_to_v(t_point p);
t_vector	c_to_v(t_color c);
t_color		v_to_c(t_vector v);

//	save_cone_bonus.c
void		par_save_cone(char *line, t_info *info);

//	inter_cone_bonus.c
t_inter		*inter_co(t_shape *cy, t_vector ray, t_point origin);

//	inter_cone2_bonus.c
bool		co_outside_lims(t_shape *co, t_inter *inter, double radians);

#endif