/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:19:45 by palucena          #+#    #+#             */
/*   Updated: 2024/01/22 15:23:36 by ealgar-c         ###   ########.fr       */
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

t_vector	v_esc_mult(t_vector orig, double escalar)
{
	t_vector	new;

	new.i = orig.i * escalar;
	new.j = orig.j * escalar;
	new.k = orig.k * escalar;
	return (new);
}
