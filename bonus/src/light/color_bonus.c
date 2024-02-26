/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:07:25 by palucena          #+#    #+#             */
/*   Updated: 2024/02/26 17:55:02 by ealgar-c         ###   ########.fr       */
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

bool	uv_checkers(t_shape *sh, t_point q)
{
	t_uv	uv = (t_uv){0,0};

	if (sh->type == SP)
	{
		double		azimut = atan2(q.x, q.z);
		double		phi = asin(q.y / sh->prop.rad);
		uv.u = (int)(1 - (azimut / (2 * M_PI)) + 0.5);
		uv.v = 1 - phi / M_PI;
	}
//	uv.u = q.x;
//	uv.v = q.y + q.z;
	if (((int)(uv.u * 8) + (int)(uv.v * 8)) % 2 == 0)
		return (true);
	return (false);
}

void	ft_color(t_inter *inter, t_info *info, t_pixel px)
{
	t_shape	*shape;

	if (inter && inter->d > EPS)
	{
		shape = info->shapes_list;
		while (shape && shape->index != inter->index)
			shape = shape->next;
		if (shape->prop.checkerboard && uv_checkers(shape, inter->q))
			ft_phong(inter, info, px, (t_color){255,255,255});
		else
			ft_phong(inter, info, px, shape->prop.color);
	}
/* 	else
		ft_darkness(info, px.i, px.j); */
}
