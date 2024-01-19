/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_diffuse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:19:30 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/18 16:45:51 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	ph_idiffuse(t_color a_c, t_info *info, t_shape *sh, t_inter c)
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
}