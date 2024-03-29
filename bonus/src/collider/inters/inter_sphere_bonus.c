/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:13:17 by palucena          #+#    #+#             */
/*   Updated: 2024/02/20 15:27:46 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static double	distance_sp(t_point origin, t_shape *sp, t_vector ray)
{
	t_quad	quad;

	quad.cc = v_get_from2(sp->prop.c, origin);
	quad.a = v_dot_product(ray, ray);
	quad.b = 2 * v_dot_product(ray, quad.cc);
	quad.c = v_dot_product(quad.cc, quad.cc) - pow(sp->prop.rad, 2);
	return (quadratic_equation(&quad));
}

t_inter	*inter_sp(t_shape *sp, t_vector ray, t_point origin)
{
	t_inter		*inter;

	inter = malloc(sizeof(t_inter));
	inter->index = sp->index;
	inter->d = distance_sp(origin, sp, ray);
	if (inter->d < EPS)
		return (free(inter), NULL);
	inter->q = inter_point_coords(origin, inter, ray);
	inter->norm = v_norm(v_get_from2(sp->prop.c, inter->q));
	return (inter);
}
