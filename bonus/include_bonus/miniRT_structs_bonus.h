/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_structs_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:35:29 by palucena          #+#    #+#             */
/*   Updated: 2024/02/20 10:21:05 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCTS_BONUS_H
# define MINIRT_STRUCTS_BONUS_H

# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_vector
{
	double	i;
	double	j;
	double	k;
}	t_vector;

typedef struct s_quad
{
	double		a;
	double		b;
	double		c;
	double		t1;
	double		t2;
	t_vector	cc;
}	t_quad;

/**
 * @brief struct to save the properties of the shapes
 * 
 * c: the point of the center (for cy and sp) and a point of a plane
 * height: only for cy
 * rad: (diam / 2) only for cy and sp
 * color: rgb settings
 * n_vec: only for pl and cy
 */
typedef struct s_properties
{
	t_point		c;
	float		height;
	float		rad;
	t_color		color;
	t_vector	n_vec;
}	t_properties;

typedef enum e_type
{
	CY = 0,
	PL,
	SP,
	CO,
}	t_type;

typedef struct s_shape
{
	t_type			type;
	t_properties	prop;
	int				index;
	struct s_shape	*next;
}	t_shape;

/**
 * @brief Shape-ray intersection
 * 
 * Index -> Index of the shape
 * d -> Distance between the camera and the intersection point
 * q -> Intersection point coordinates
 */
typedef struct s_inter
{
	int			index;
	double		d;
	t_point		q;
	t_vector	norm;
}	t_inter;

typedef struct s_circle
{
	t_point		p;
	t_vector	v;
	double		diam;
	t_inter		*coll;
	t_shape		*plane;
	int			shape_id;
}	t_circle;

/**
 * @brief Info about a single pixel in the screen
 * 
 * i -> X coordenate of the pixel inside the image plane
 * j -> Y coordenate of the pixel inside the image plane
 * p -> Coords (x, y, z) of the pixel in the scene
 * d -> Normalized camera-pixel vector (direction)
 */
typedef struct s_pixel
{
	double		i;
	double		j;
	t_vector	d;
}	t_pixel;

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

typedef struct s_matrix
{
	double	m[4][4];
}	t_matrix;

typedef struct s_cset
{
	t_point		point;
	int			fov;
	t_vector	n_vec;
	t_matrix	m;
}	t_cset;

typedef struct s_lset
{
	t_point			point;
	t_color			color;
	float			brightness;
	struct s_lset	*next;
}	t_lset;

typedef struct s_info
{
	char		*filename;
	t_mlxset	mlx_s;
	t_aset		*aset;
	t_cset		*cset;
	t_lset		*lset;
	t_shape		*shapes_list;
	int			width;
	int			height;
	int			w_width;
	int			w_height;
}	t_info;

#endif