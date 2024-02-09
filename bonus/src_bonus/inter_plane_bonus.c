/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:12:56 by palucena          #+#    #+#             */
/*   Updated: 2024/02/09 14:05:24 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/miniRT_bonus.h"

static double	distance_pl(t_point origin, t_shape *pl, t_vector ray)
{
	double	top;
	double	bot;

	bot = v_dot_product(ray, pl->prop.n_vec);
	if (bot == 0)
		return (-1.0);
	top = v_dot_product(v_get_from2(origin, pl->prop.c),
			pl->prop.n_vec);
	return (top / bot);
}

t_inter	*inter_pl(t_shape *pl, t_vector ray, t_point origin)
{
	t_inter	*inter;

	inter = malloc(sizeof(t_inter));
	inter->index = pl->index;
	inter->d = distance_pl(origin, pl, ray);
	if (inter->d == -1.0)
		return (free(inter), NULL);
	inter->q = inter_point_coords(origin, inter, ray);
	return (inter);
}
