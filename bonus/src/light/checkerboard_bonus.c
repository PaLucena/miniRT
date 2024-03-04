/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:21:45 by palucena          #+#    #+#             */
/*   Updated: 2024/03/04 21:41:09 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

bool	checkerb_sp(t_shape *sh, t_point q)
{
	t_uv	uv;
	double	azimut;
	double	polar;

	azimut = atan2(q.x, q.z);
	polar = acos(q.y / sh->prop.rad);
	uv.u = (1 - (azimut / (2 * M_PI) + 0.5));
	uv.v = 1 - (polar / M_PI);
	if (((int)(uv.u * 16) + (int)(uv.v * 8)) % 2 == 0)
		return (true);
	return (false);
}

bool	checkerb_pl(t_shape *sh, t_point q, t_info *info)
{
	t_uv	uv;

	uv.u = 0.0;
	uv.v = 0.0;
	if (sh->prop.n_vec.i != 0)
	{
		uv.u = fmod(q.z - info->w_width, 1);
		uv.v = fmod(q.y - info->w_height, 1);
	}
	else if (sh->prop.n_vec.j != 0)
	{
		uv.u = fmod(q.x - info->w_width, 1);
		uv.v = fmod(q.z - info->w_height, 1);
	}
	else if (sh->prop.n_vec.k != 0)
	{
		uv.u = fmod(q.x - info->w_width, 1);
		uv.v = fmod(q.y - info->w_height, 1);
	}
	if (((int)(uv.u * 2) + (int)(uv.v * 2)) % 2 == 0)
		return (true);
	return (false);
}

bool	checkerb_cy(t_shape *sh, t_point q, t_info *info)
{
	t_uv	uv;
	double	azimut;

	(void)info;
	(void)sh;
	azimut = atan2(q.x, q.z);
	uv.u = azimut / (2 * M_PI);
	uv.u = (1 - (uv.u + 0.5));
	uv.v = fmod(q.y, 1);
	if (((int)(uv.u * 32) + (int)(uv.v * 2)) % 2 == 0)
		return (true);
	return (false);
}
