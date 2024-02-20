/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cone2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:34:54 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/20 14:42:01 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

bool	co_outside_lims(t_shape *co, t_inter *inter, double radians)
{
	double	c_to_q;
	double	limit;

	c_to_q = v_mod(v_get_from2(co->prop.c, inter->q));
	limit = sqrt(pow(co->prop.height, 2) + pow(co->prop.rad, 2));
	if (c_to_q > limit + EPS)
		return (false);
	if (radians < 90.0 * (M_PI / 180))
	{
		if (v_dot_product(v_get_from2(co->prop.c,
					inter->q), co->prop.n_vec) > EPS)
			return (true);
	}
	return (false);
}
