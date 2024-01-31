/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:13:17 by palucena          #+#    #+#             */
/*   Updated: 2024/01/31 16:38:40 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	distance_sp(t_info *info, t_shape *sp, t_vector ray, t_pixel px)
{
	t_vector	cc;
	t_point		abc;
	double	tmp;

	cc = v_get_from2(sp->prop.c, info->cset->point);
	abc.x = v_dot_product(ray, ray);
	abc.y = 2 * v_dot_product(ray, cc);
	tmp = v_mod(v_get_from2(info->cset->point, sp->prop.c));
	abc.z = pow(v_dot_product(cc, cc), 2) - pow(sp->prop.rad, 2);
	if (px.i == info->width / 2 && px.j == info->height / 2)
		printf("abc: %f %f %f\n", abc.x, abc.y, abc.z);
	return (quadratic_equation(abc.x, abc.y, abc.z));
}

t_inter	*inter_sp(t_info *in, t_shape *sp, t_pixel px)
{
	t_inter		*inter;

	inter = malloc(sizeof(t_inter));
	inter->index = sp->index;
	inter->d = distance_sp(in, sp, px.d, px);
	if (px.i == in->width / 2 && px.j == in->height / 2)
		printf("alo%f\n", inter->d);
	if (inter->d < 0)
		return (free(inter), NULL);
	inter->q = inter_point_coords(in, inter, px.d, sp->type);
	//inter->q.y *= -1;
	return (inter);
}
