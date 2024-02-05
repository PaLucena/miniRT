/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:13:17 by palucena          #+#    #+#             */
/*   Updated: 2024/02/05 18:44:09 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	distance_sp(t_info *info, t_shape *sp, t_vector ray)
{
	t_quad	quad;

	quad.cc = v_get_from2(sp->prop.c, info->cset->point);
	quad.a = v_dot_product(ray, ray);
	quad.b = 2 * v_dot_product(ray, quad.cc);
	quad.c = v_dot_product(quad.cc, quad.cc) - pow(sp->prop.rad, 2);
	return (quadratic_equation(&quad));
}

t_inter	*inter_sp(t_info *in, t_shape *sp, t_pixel px)
{
	t_inter		*inter;

	inter = malloc(sizeof(t_inter));
	inter->index = sp->index;
	inter->d = distance_sp(in, sp, px.d);
	if (inter->d < 0)
		return (free(inter), NULL);
	inter->q = inter_point_coords(in, inter, px.d, sp->type);
	return (inter);
}
