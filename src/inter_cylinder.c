/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:14:03 by palucena          #+#    #+#             */
/*   Updated: 2024/01/19 16:17:00 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

t_inter	*inter_cy(t_info *in, t_shape *cy, t_pixel px)
{
	t_inter		*inter;
	t_vector	cc;
	t_point		abc;

	inter = malloc(sizeof(t_inter));
	inter->index = sp->index;
	cc = v_get_from2(in->cset->point, sp->prop.c);
	abc = calculate_abc(in, sp, px.d, cc);
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
