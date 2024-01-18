/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:13:17 by palucena          #+#    #+#             */
/*   Updated: 2024/01/18 18:18:23 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	plane_point_coords(t_info *in, double i, double j)
{
	t_point	p;

	p.x = in->pl->l + i;
	p.y = in->pl->b + j;
	p.z = (WIDTH / 2) / sin((in->cset->fov / 2) * (M_PI / 180)) + in->cset->point.z;
	return (p);
}

t_point	calculate_abc(t_info *in, t_shape *sp, t_vector d, t_vector cc)
{
	t_point	abc;
	double	tmp;

	tmp = v_mod(v_get_from2(in->cset->point, sp->prop.c));
	abc.x = pow(v_mod(d), 2);
	abc.y = 2 * (d.i * cc.i + d.j * cc.j + d.k * cc.k);
	abc.z = pow(tmp, 2) - pow(sp->prop.rad, 2);
	return (abc);
}

t_point	inter_point_coords(t_info *in, t_inter *inter, t_vector cc)
{
	t_point	q;

	q.x = in->cset->point.x + inter->d * cc.i;
	q.y = in->cset->point.y + inter->d * cc.j;
	q.z = in->cset->point.z + inter->d * cc.k;
	return (q);
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
	p = plane_point_coords(in, i, j);
	if (in->cset->n_vec.k > 0)
		p.z *= -1;
	d = v_norm(v_get_from2(in->cset->point, p));
	cc = v_get_from2(in->cset->point, sp->prop.c);
	abc = calculate_abc(in, sp, d, cc);
	inter->d = quadratic_equation(abc.x, abc.y, abc.z);
	if (inter->d < 0)
	{
		free (inter);
		return (NULL);
	}
	cc = v_norm(cc);
	inter->q = inter_point_coords(in, inter, cc);
	return (inter);
}
