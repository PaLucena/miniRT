/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:21:45 by palucena          #+#    #+#             */
/*   Updated: 2024/03/05 18:27:12 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

bool	checkerb_sp(t_shape *sh, t_point q, t_info *info)
{
	t_uv	uv;
	double	azimut;
	double	polar;

	(void)info;
	azimut = atan2((q.x - sh->prop.c.x), (q.z - sh->prop.c.z));
	polar = acos((q.y - sh->prop.c.y) / sh->prop.rad);
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
		uv.u = fmod(q.z - info->width, 1);
		uv.v = fmod(q.y - info->height, 1);
	}
	else if (sh->prop.n_vec.j != 0)
	{
		uv.u = fmod(q.x - info->width, 1);
		uv.v = fmod(q.z - info->height, 1);
	}
	else if (sh->prop.n_vec.k != 0)
	{
		uv.u = fmod(q.x - info->width, 1);
		uv.v = fmod(q.y - info->height, 1);
	}
	if (((int)(uv.u * 2) + (int)(uv.v * 2)) % 2 == 0)
		return (true);
	return (false);
}

static int	checkerb_cy_calc(t_uv uv, t_shape *sh)
{
	return (((int)(uv.u * 24 * sh->prop.rad) + (int)(uv.v * sh->prop.height)));
}

bool	checkerb_cy(t_shape *sh, t_point q, t_info *info)
{
	t_uv	uv;
	double	azimut;
	double	ratio;

	(void)info;
	(void)sh;
	ratio = sh->prop.height / (sh->prop.rad * 2);
	azimut = atan2(q.x - sh->prop.c.x, q.z - sh->prop.c.z);
	uv.u = azimut / (2 * M_PI);
	uv.u = (1 - (uv.u + 0.5)) - info->width;
	uv.v = fmod(q.y - sh->prop.c.y, 1) - info->height;
	if (checkerb_cy_calc(uv, sh) % 2 == 0)
		return (true);
	return (false);
}
