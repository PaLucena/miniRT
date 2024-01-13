/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:35:29 by palucena          #+#    #+#             */
/*   Updated: 2024/01/13 13:29:57 by palucena         ###   ########.fr       */
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
	int				index;
	struct s_shape	*next;
}	t_shape;

/**
 * @brief Intersección de rayo con figura.
 * 
 */
typedef struct s_inter
{
	int		index;
	double	d;
}	t_inter;

/**
 * @brief Coordenadas de un plano en la escena
 * 
 * l -> left
 * r -> right
 * t -> top
 * b -> bottom
 */
typedef	struct s_plcoor
{
	double	l;
	double	r;
	double	t;
	double	b;
}	t_plcoor;

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

#endif