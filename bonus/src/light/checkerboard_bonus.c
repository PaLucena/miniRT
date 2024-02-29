/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:21:45 by palucena          #+#    #+#             */
/*   Updated: 2024/02/29 19:15:55 by palucena         ###   ########.fr       */
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
	if (((int)(uv.u * 20) + (int)(uv.v * 10)) % 2 == 0)
		return (true);
	return (false);
}

bool	checkerb_pl(t_shape *sh, t_point q, t_info *info)
{
	t_uv	uv;

	sh->prop.n_vec = v_unitary(sh->prop.n_vec);
	uv.u = fmod(q.x + info->w_width / 2, 1);
	uv.v = (q.y * sh->prop.n_vec.k) + (q.z * sh->prop.n_vec.j);
	uv.v = fmod(uv.v - info->w_height / 2, 1);

	if (((int)(uv.u * 2) + (int)(uv.v * 2)) % 2 == 0)
		return (true);
	return (false);
}

//TODO:  La puta matriz de transformación