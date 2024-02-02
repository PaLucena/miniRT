/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:44:05 by palucena          #+#    #+#             */
/*   Updated: 2024/01/31 14:05:50 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	v_to_p(t_vector v)
{
	t_point	p;

	p.x = v.i;
	p.y = v.j;
	p.z = v.k;
	return (p);
}

/* t_vector	p_to_v(t_point p)
{
	t_vector	v;

	v.i = p.x;
	v.j = p.y;
	v.k = p.z;
	return (v);
} */
