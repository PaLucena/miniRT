/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:12:56 by palucena          #+#    #+#             */
/*   Updated: 2024/02/05 12:09:13 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	distance_pl(t_info *info, t_shape *pl, t_vector ray)
{
	double	top;
	double	bot;

	bot = v_dot_product(ray, pl->prop.n_vec);
	if (bot == 0)
		return (-1.0);
	top = v_dot_product(v_get_from2(info->lset->point, pl->prop.c),
			pl->prop.n_vec);
	return (top / bot);
}

t_inter	*inter_pl(t_info *in, t_shape *pl, t_pixel px)
{
	t_inter	*inter;

	inter = malloc(sizeof(t_inter));
	inter->index = pl->index;
	inter->d = distance_pl(in, pl, px.d);
	if (inter->d == -1.0)
		return (free(inter), NULL);
	inter->q = inter_point_coords(in, inter, px.d, pl->type);
	return (inter);
}
