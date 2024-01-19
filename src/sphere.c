/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:13:17 by palucena          #+#    #+#             */
/*   Updated: 2024/01/19 11:31:30 by ealgar-c         ###   ########.fr       */
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
	if (a1 >= 0 && a2 >= 0 && a1 < a2)
		return (a1);
	return (a2);
}
t_inter	*inter_sp(t_info *in, t_shape *sp, double i, double j)
{
	t_inter		*inter;
	t_vector	d;
	t_vector	cc;
	t_point		p;
	t_point		abc;

	inter = malloc(sizeof(t_inter));
	inter->index = sp->index;
	p.x = in->pl->l + i;
	p.y = in->pl->b + j;
	p.z = (in->width / 2) / sin((in->cset->fov / 2) * (M_PI / 180)) + in->cset->point.z;
	d = v_norm(v_get_from2(in->cset->point, p));
	cc = v_get_from2(in->cset->point, sp->prop.c);
	abc.x = pow(v_mod(d), 2);
	abc.y = 2 * (d.i * cc.i + d.j * cc.j + d.k * cc.k);
	abc.z = pow(v_mod(v_get_from2(sp->prop.c, in->cset->point)), 2) - pow(sp->prop.rad, 2);
	inter->d = quadratic_equation(abc.x, abc.y, abc.z);
	if (inter->d < 0)
	{
		free (inter);
		return (NULL);
	}
	inter->q.x = in->cset->point.x + inter->d * in->cset->n_vec.i;
	inter->q.y = in->cset->point.y + inter->d * in->cset->n_vec.j;
	inter->q.z = in->cset->point.z + inter->d * in->cset->n_vec.k;
	return (inter);
}
