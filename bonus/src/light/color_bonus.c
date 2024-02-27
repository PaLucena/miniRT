/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:07:25 by palucena          #+#    #+#             */
/*   Updated: 2024/02/27 13:59:23 by palucena         ###   ########.fr       */
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
	if (sh->type == SP)
		return (checkerb_sp(sh, q));
	else if (sh->type == PL)
		return (checkerb_pl(sh, q));
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
		if (uv_checkers(shape, inter->q))
			ft_phong(inter, info, px, (t_color){255,255,255});
		else
			ft_phong(inter, info, px, shape->prop.color);
	}
/* 	else
		ft_darkness(info, px.i, px.j); */
}
