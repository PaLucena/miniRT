/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:19:45 by palucena          #+#    #+#             */
/*   Updated: 2024/01/19 14:20:10 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
