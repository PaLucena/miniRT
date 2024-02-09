/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_point_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:44:05 by palucena          #+#    #+#             */
/*   Updated: 2024/02/09 14:13:32 by ealgar-c         ###   ########.fr       */
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

t_vector	p_to_v(t_point p)
{
	t_vector	v;

	v.i = p.x;
	v.j = p.y;
	v.k = p.z;
	return (v);
}

t_vector	c_to_v(t_color c)
{
	t_vector	v;

	v.i = (double)c.r;
	v.j = (double)c.g;
	v.k = (double)c.b;
	return (v);
}

t_color	v_to_c(t_vector v)
{
	t_color	c;

	c.r = (int)v.i;
	c.g = (int)v.j;
	c.b = (int)v.k;
	return (c);
}
