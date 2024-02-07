/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:13:17 by palucena          #+#    #+#             */
/*   Updated: 2024/02/07 15:39:23 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	distance_sp(t_point origin, t_shape *sp, t_vector ray)
{
	t_vector	cc;
	t_point		abc;

	cc = v_get_from2(sp->prop.c, origin);
	abc.x = v_dot_product(ray, ray);
	abc.y = 2 * v_dot_product(ray, cc);
	abc.z = v_dot_product(cc, cc) - pow(sp->prop.rad, 2);
	return (quadratic_equation(abc.x, abc.y, abc.z));
}

t_inter	*inter_sp(t_shape *sp, t_vector ray, t_point origin)
{
	t_inter		*inter;

	inter = malloc(sizeof(t_inter));
	inter->index = sp->index;
	inter->d = distance_sp(origin, sp, ray);
	if (inter->d < 0)
		return (free(inter), NULL);
	inter->q = inter_point_coords(origin, inter, ray);
	return (inter);
}
