/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:53:18 by palucena          #+#    #+#             */
/*   Updated: 2024/03/01 13:04:35 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_vector	m_product(t_vector p, t_matrix m)
{
	t_vector	result;

	result.i = p.i * m.m[0][0] + p.j * m.m[0][1] + p.k * m.m[0][2] + m.m[0][3];
	result.j = p.i * m.m[1][0] + p.j * m.m[1][1] + p.k * m.m[1][2] + m.m[1][3];
	result.k = p.i * m.m[2][0] + p.j * m.m[2][1] + p.k * m.m[2][2] + m.m[2][3];
	return (result);
}

t_point	m_rotation_x(t_point p, double rad)
{
	t_matrix	m;

	m.m[0][0] = 1;
	m.m[1][0] = 0;
	m.m[2][0] = 0;
	m.m[3][0] = 0;
	m.m[0][1] = 0;
	m.m[1][1] = cosf(rad);
	m.m[2][1] = -sinf(rad);
	m.m[3][1] = 0;
	m.m[0][2] = 0;
	m.m[1][2] = sinf(rad);
	m.m[2][2] = cosf(rad);
	m.m[3][2] = 0;
	m.m[0][3] = 0;
	m.m[1][3] = 0;
	m.m[2][3] = 0;
	m.m[3][3] = 1;
	return (v_to_p(m_product(p_to_v(p), m)));
}

t_point	m_rotation_z(t_point p, double rad)
{
	t_matrix	m;

	m.m[0][0] = cosf(rad);
	m.m[1][0] = -sinf(rad);
	m.m[2][0] = 0;
	m.m[3][0] = 0;
	m.m[0][1] = sinf(rad);
	m.m[1][1] = cosf(rad);
	m.m[2][1] = 0;
	m.m[3][1] = 0;
	m.m[0][2] = 0;
	m.m[1][2] = 0;
	m.m[2][2] = 1;
	m.m[3][2] = 0;
	m.m[0][3] = 0;
	m.m[1][3] = 0;
	m.m[2][3] = 0;
	m.m[3][3] = 1;
	return (v_to_p(m_product(p_to_v(p), m)));
}
