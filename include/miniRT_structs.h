/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:35:29 by palucena          #+#    #+#             */
/*   Updated: 2024/01/19 11:31:06 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCTS_H
# define MINIRT_STRUCTS_H

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
}	t_type;

typedef struct s_shape
{
	t_type			type;
	t_properties	prop;
	int				index;
	struct s_shape	*next;
}	t_shape;

/**
 * @brief Intersección de rayo con figura.
 * 
 * Index -> Indice de la figura
 * d -> Distancia entre la camara y el punto de interseccion
 * q -> Coordenadas del punto de interseccion
 */
typedef struct s_inter
{
	int		index;
	double	d;
	t_point q;
}	t_inter;

/**
 * @brief Coordenadas de las esquinas del plano imagen
 * 
 * l -> left ('x' de la esquina superior izquierda del plano imagen)
 * r -> right ('x' de la esquina superior derecha del plano imagen)
 * t -> top ('y' de la esquina superior derecha del plano imagen)
 * b -> bottom ('y' de la esquina inferior derecha del plano imagen)
 */
typedef	struct s_iplane
{
	double	l;
	double	r;
	double	t;
	double	b;
}	t_iplane;

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
	t_vector	n_vec;
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
	t_iplane	*pl;
	t_aset		*aset;
	t_cset		*cset;
	t_lset		*lset;
	t_shape		*shapes_list;
	int32_t		width;
	int32_t		height;
}	t_info;

#endif