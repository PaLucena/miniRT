/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:19:45 by palucena          #+#    #+#             */
/*   Updated: 2024/02/20 14:42:01 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

t_vector	v_norm(t_vector v)
{
	t_vector	v_norm;
	double		tmp;

	v_norm.i = 0;
	v_norm.j = 0;
	v_norm.k = 0;
	tmp = v_mod(v);
	if (tmp != 0)
	{
		v_norm.i = v.i / tmp;
		v_norm.j = v.j / tmp;
		v_norm.k = v.k / tmp;
	}
	return (v_norm);
}

double	v_mod(t_vector v)
{
	return (sqrt((v.i * v.i) + (v.j * v.j) + (v.k * v.k)));
}

double	v_dot_product(t_vector v1, t_vector v2)
{
	return (v1.i * v2.i + v1.j * v2.j + v1.k * v2.k);
}

t_vector	v_cross_product(t_vector v1, t_vector v2)
{
	t_vector	result;

	result.i = v1.j * v2.k - v1.k * v2.j;
	result.j = v1.k * v2.i - v1.i * v2.k;
	result.k = v1.i * v2.j - v1.j * v2.i;
	return (result);
}

t_vector	v_matrix_product(t_vector p, t_matrix m)
{
	t_vector	result;

	result.i = p.i * m.m[0][0] + p.j * m.m[0][1] + p.k * m.m[0][2] + m.m[0][3];
	result.j = p.i * m.m[1][0] + p.j * m.m[1][1] + p.k * m.m[1][2] + m.m[1][3];
	result.k = p.i * m.m[2][0] + p.j * m.m[2][1] + p.k * m.m[2][2] + m.m[2][3];
	return (result);
}
