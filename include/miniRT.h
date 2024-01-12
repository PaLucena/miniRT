/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:21:20 by palucena          #+#    #+#             */
/*   Updated: 2024/01/12 14:12:37 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/errno.h>
# include <math.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_vector
{
	float	i;
	float	j;
	float	k;
}	t_vector;

/**
 * @brief struct to save the properties of the shapes
 * 
 * center: the point of the center (for cy and sp) and a point of a plane
 * height: only for cy
 * rad: (diam / 2) only for cy and sp
 * color: rgb settings
 * n_vector: only for pl and cy
 */
typedef struct s_properties
{
	t_point		center;
	float		height;
	float		rad;
	t_color		color;
	t_vector	n_vector;
}	t_properties;

typedef enum e_type
{
	CY = 0,
	PL,
	SP,
}	t_type;

typedef struct s_shape
{
	t_type			type;
	t_properties	prop;
	struct s_shape	*next;
}	t_shape;

typedef struct s_mlxset
{
	mlx_t		*mlx;
	mlx_image_t	*win;
}	t_mlxset;

typedef struct s_aset
{
	float	ratio;
	t_color	color;
}	t_aset;

typedef struct s_cset
{
	t_point		point;
	int			fov;
	t_vector	n_vector;
}	t_cset;

typedef struct s_lset
{
	t_point	point;
	t_color	color;
	float	brightness;
}	t_lset;

typedef struct s_info
{
	char		*filename;
	t_mlxset	mlx_s;
	t_aset		*aset;
	t_cset		*cset;
	t_lset		*lset;
	t_shape		*shapes_list;
}	t_info;

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

//	save_camera.c
void	par_save_camera(char *line, t_info *info);

//	save_light.c
void	par_save_light(char *line, t_info *info);

//	scene_list_tools.c
t_shape	*shapes_newnode(t_type type);
void	shapes_addback(t_shape *root, t_shape *node);

//	save_sphere.c
void	par_save_sphere(char *line, t_info *info);

#endif