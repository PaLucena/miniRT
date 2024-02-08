/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:47:34 by palucena          #+#    #+#             */
/*   Updated: 2024/02/08 14:13:51 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static double	quad_closest_t(t_quad quad)
{
	if (quad.t1 >= 0 && quad.t2 >= 0)
	{
		if (quad.t1 < quad.t2)
			return (quad.t1);
		return (quad.t2);
	}
	if (quad.t1 >= 0 && quad.t2 < 0)
		return (quad.t1);
	return (quad.t2);
}

double	quadratic_equation(t_quad *quad)
{
	double		dis;

	dis = (quad->b * quad->b) - 4 * quad->a * quad->c;
	if (dis < 0)
		return (-1);
	quad->t1 = ((quad->b * -1) + sqrt(dis)) / (2 * quad->a);
	quad->t2 = ((quad->b * -1) - sqrt(dis)) / (2 * quad->a);
	return (quad_closest_t(*quad));
}

t_point	plane_point_coords(t_info *in, double i, double j)
{
	t_point	p;
	double	fov;
	double	a_ratio;

	a_ratio = in->width / (double)in->height;
	fov = tan((in->cset->fov * (M_PI / 180)) / 2);
	p.x = (2 * ((i + 0.5) / (double)in->width) - 1) * a_ratio * fov;
	p.y = (1 - 2 * ((j + 0.5) / (double)in->height)) * fov;
	p.z = 1;
	return (p);
}

t_point	inter_point_coords(t_point origin, t_inter *inter, t_vector cc)
{
	t_point	q;

	q.x = origin.x + inter->d * cc.i;
	q.y = origin.y + inter->d * cc.j;
	q.z = origin.z + inter->d * cc.k;
	return (q);
}
