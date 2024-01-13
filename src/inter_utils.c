/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:47:34 by palucena          #+#    #+#             */
/*   Updated: 2024/01/13 12:23:08 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_plcoor	*image_plane_coords(t_cset *c)
{
	t_plcoor	*pl;

	pl = malloc(sizeof(t_plcoor));
	
}

double	ray_direction(t_info *info, double i, double j)
{
	t_plcoor	*pl;
	double		x;
	double		y;

	pl = image_plane_coords(info->cset);
	x = pl->l + (pl->r - pl->l)(i + 0.5)/WIDTH;
	y = pl->b + (pl->t - pl->b)(j + 0.5)/HEIGHT;
}
