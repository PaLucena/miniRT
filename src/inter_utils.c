/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:47:34 by palucena          #+#    #+#             */
/*   Updated: 2024/01/19 15:29:42 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	quadratic_equation(double a, double b, double c)
{
	double		dis;
	double		a1;
	double		a2;

	dis = (b * b) - 4 * a * c;
	if (dis < 0)
		return (-1);
	a1 = ((b * -1) + sqrt(dis)) / (2 * a);
	a2 = ((b * -1) - sqrt(dis)) / (2 * a);
	if ((a1 >= 0 && a2 >= 0 && a1 < a2) || a1 >= 0)
		return (a1);
	return (a2);
}

t_point	plane_point_coords(t_info *in, double i, double j)
{
	t_point	p;

	p.x = in->pl->l + i;
	p.y = in->pl->b + j;
	p.z = (in->width / 2) / sin((in->cset->fov / 2)
			* (M_PI / 180)) + in->cset->point.z;
	if (in->cset->n_vec.k > 0)
		p.z *= -1;
	return (p);
}

void	image_plane_coords(t_info *i)
{
	i->pl->l = i->cset->point.x - i->width / 2;
	i->pl->r = i->cset->point.x + i->width / 2;
	i->pl->t = i->cset->point.y + i->height / 2;
	i->pl->b = i->cset->point.y - i->height / 2;
}

t_point	inter_point_coords(t_info *in, t_inter *inter, t_vector cc)
{
	t_point	q;

	q.x = in->cset->point.x + inter->d * cc.i;
	q.y = in->cset->point.y + inter->d * cc.j;
	q.z = in->cset->point.z + inter->d * cc.k;
	return (q);
}
