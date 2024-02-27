/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:21:45 by palucena          #+#    #+#             */
/*   Updated: 2024/02/27 16:25:47 by palucena         ###   ########.fr       */
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

bool	checkerb_pl(t_shape *sh, t_point q)
{
	t_uv	uv;
	t_point	p;

	p.x = q.x - v_dot_product(sh->prop.n_vec, (t_vector){0, 1, 0});
	p.y = q.y - v_dot_product(sh->prop.n_vec, (t_vector){1, 0, 0});
	p.z = q.z - v_dot_product(sh->prop.n_vec, (t_vector){0, 0, 1});
	if (((int)(p.x) + (int)p.y + (int)(p.z)) %  2 == 0)
		return (true);
	return (false);

//	uv.u = fmod(q.x, 1);
//	uv.v = fmod(q.z, 1);

//	printf("XZ: %f %f\n", q.x, q.z);
//	printf("UV: %f %f\n\n", uv.u, uv.v);
//	if ((int)((q.x + q.y + q.z)) % 2 == 0)
	if (((int)(uv.u) + (int)(uv.v)) % 2 == 0)
		return (true);
	return (false);
}
