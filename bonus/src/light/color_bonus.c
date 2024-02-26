/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:07:25 by palucena          #+#    #+#             */
/*   Updated: 2024/02/26 15:01:21 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	ft_darkness(t_info *info, double x, double y)
{
	t_color	black;

	black.r = 0;
	black.g = 0;
	black.b = 0;
	mlx_put_pixel(info->mlx_s.win, x, y, get_rgba(black));
}

t_uv	uv_checkers(t_shape *sh, t_point q)
{
	t_uv	uv = (t_uv){0,0};

	if (sh->type == SP)
	{
		double		azimut = atan2(q.x, q.z);
		double		phi = asin(q.y / sh->prop.rad);
		uv.u = (int)(1 - (azimut / (2 * M_PI)) + 0.5);
		uv.v = 1 - phi / M_PI;
	}
	uv.u = q.x;
	uv.v = q.y + q.z;
	return (uv);
}

void	ft_color(t_inter *inter, t_info *info, t_pixel px)
{
	t_shape	*shape;
	t_uv	uv;

	if (inter && inter->d > EPS)
	{
		shape = info->shapes_list;
		while (shape && shape->index != inter->index)
			shape = shape->next;
		uv = uv_checkers(shape, inter->q);
		if ((uv.u + uv.v) % 2 == 0)
			shape->prop.color = (t_color){255,255,255};
		else	
			shape->prop.color = (t_color){0,0,0};
		ft_phong(inter, info, px, shape);
	}
/* 	else
		ft_darkness(info, px.i, px.j); */
}
