/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_diffuse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:19:30 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/04 16:47:04 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	c_add_diff(t_shape *sh, double diff)
{
	t_color	result;

	result.r = 0;
	result.g = 0;
	result.b = 0;
	if (diff >= 0)
	{
		result.r = sh->prop.color.r * diff;
		result.g = sh->prop.color.g * diff;
		result.b = sh->prop.color.b * diff;
	}
	return (result);
}

t_color	diffuse_light(t_info *in, t_inter *inter, t_shape *sh)
{
	double		facing_ratio;
	t_vector	v;
	t_vector	n;

	v = v_norm(v_get_from2(inter->q, in->lset->point));
	if (sh->type == SP)
		n = v_norm(v_get_from2(sh->prop.c, inter->q));
	else /* if (sh->type == PL) */
		n = sh->prop.n_vec;
	facing_ratio = v_dot_product(v, n);
/* 	if (sh->type == PL)
		facing_ratio *= -1; */
	facing_ratio = (facing_ratio + in->lset->brightness + in->aset->ratio) / 3;
	return (c_add_diff(sh, facing_ratio));
}

/* t_color	ph_idiffuse(t_color a_c, t_info *info, t_shape *sh, t_inter c)
{
	t_color		final_color;
	t_vector	n_shape;
	t_vector	l_vec;
	t_vector	res_vect;

	n_shape = v_get_from2(sh->prop.c, c.q);
	l_vec = v_unitary(v_get_from2(c.q, info->lset->point));
	res_vect = v_mult(n_shape, l_vec);
	final_color.r = ft_cl_clamp(a_c.r + info->lset->brightness * res_vect.i);
	final_color.g = ft_cl_clamp(a_c.g + info->lset->brightness * res_vect.j);
	final_color.b = ft_cl_clamp(a_c.b + info->lset->brightness * res_vect.k);
	return (final_color);
} */
