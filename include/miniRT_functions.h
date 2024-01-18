/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:43:22 by palucena          #+#    #+#             */
/*   Updated: 2024/01/18 17:59:30 by palucena         ###   ########.fr       */
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
void		ft_keyhook(void *param);

//sphere.c
t_inter		*inter_sp(t_info *in, t_shape *sp, double i, double j);

//plane.c
t_inter		*inter_pl(t_info *in, double i, double j);

//cylinder.c
t_inter		*inter_cy(t_info *in, double i, double j);

//inter_utils.c
double		quadratic_equation(double a, double b, double c);
t_vector	v_unitary(t_vector a);
double		v_mod(t_vector v);
t_vector	v_get_from2(t_point from, t_point to);
t_vector	v_norm(t_vector v);
void		image_plane_coords(t_info *i);

//	pixels.c
void	put_pixels(t_info *info);

#endif