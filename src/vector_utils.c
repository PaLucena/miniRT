/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:21:38 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/18 15:43:17 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	v_mult(t_vector a, t_vector b)
{
	t_vector	new;

	new.i = a.i * b.i;
	new.j = a.j * b.j;
	new.k = a.k * b.k;
	return (new);
}

t_vector	v_sum(t_vector a, t_vector b)
{
	t_vector	new;

	new.i = a.i + b.i;
	new.j = a.j + b.j;
	new.k = a.k + b.k;
	return (new);
}

t_vector	v_unitary(t_vector a)
{
	t_vector	new;
	double		mod;

	mod = sqrt((pow(a.i, 2)) + (pow(a.j, 2)) + (pow(a.k, 2)));
	new.i = a.i / mod;
	new.j = a.j / mod;
	new.k = a.k / mod;
	return (new);
}

t_vector	v_get_from2(t_point from, t_point to)
{
	t_vector	new;

	new.i = to.x - from.x;
	new.j = to.y - from.y;
	new.k = to.z - from.z;
	return (new);
}


double	v_mod(t_vector v)
{
	return (sqrt((v.i * v.i) + (v.j * v.j) + (v.k * v.k)));
}
