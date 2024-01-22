/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:13:17 by palucena          #+#    #+#             */
/*   Updated: 2024/01/22 11:01:57 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	calculate_abc(t_info *in, t_shape *sp, t_vector d, t_vector cc)
{
	t_point	abc;
	double	tmp;

	tmp = v_mod(v_get_from2(in->cset->point, sp->prop.c));
	abc.x = pow(v_mod(d), 2);
	abc.y = 2 * v_dot_product(d, cc);
	abc.z = pow(tmp, 2) - pow(sp->prop.rad, 2);
	return (abc);
}

t_inter	*inter_sp(t_info *in, t_shape *sp, t_pixel px)
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
