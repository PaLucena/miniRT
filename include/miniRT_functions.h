/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:43:22 by palucena          #+#    #+#             */
/*   Updated: 2024/01/12 18:18:39 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINRT_FUNCTIONS_H
# define MINRT_FUNCTIONS_H

# include "miniRT_structs.h"

//	main.c
void	ft_print_error(char *str, t_info *info);

//	init.c
t_info	*init_info(char *filename);

//	parser.c
void	ft_parser(t_info *info);

//	save_amb.c
void	par_save_amb(char *line, t_info *info);

//	save_extras.c
void	ft_save_rgb(t_color *color, char *str, t_info *info);
void	ft_save_point(t_point *point, char *str, t_info *info);
void	ft_save_vector(t_vector *vector, char *str, t_info *info);
int		cy_save_hei(char *line, int start, t_properties *prop, t_info *info);

//	save_camera.c
void	par_save_camera(char *line, t_info *info);

//	save_light.c
void	par_save_light(char *line, t_info *info);

//	scene_list_tools.c
t_shape	*shapes_newnode(t_type type, int last_idx);
void	shapes_addback(t_shape *root, t_shape *node);
int		shapes_get_last_idx(t_shape *root);

//	save_sphere.c
void	par_save_sphere(char *line, t_info *info);

//	save_plane.c
void	par_save_plane(char *line, t_info *info);

//	save_cylinder.c
void	par_save_cylinder(char *line, t_info *info);

//	exit.c
void	ft_exit_program(void *param);

//	mlx_hooks.c
void	ft_keyhook(void *param);

#endif