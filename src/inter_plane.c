/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:12:56 by palucena          #+#    #+#             */
/*   Updated: 2024/01/27 14:52:07 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	distance_pl(t_info *info, t_shape *pl, t_vector ray)
{
	double	top;
	double	bot;
	double	d;

	top = v_dot_product(v_get_from2(info->lset->point, pl->prop.c),
			pl->prop.n_vec);
	bot = v_dot_product(ray, pl->prop.n_vec);
	if (bot < 0.000001)
		return (0);
	d = (top / bot);
	return (d);
}

t_inter	*inter_pl(t_info *in, t_shape *pl, t_pixel px)
{
	t_inter	*inter;

	inter = malloc(sizeof(t_inter));
	inter->index = pl->index;
	inter->d = distance_pl(in, pl, px.d);
	if (!inter->d)
		return (free(inter), NULL);
	inter->q = inter_point_coords(in, inter, px.d, pl->type);
	inter->q.x *= -1; //TODO: arreglar signos
	inter->d *= (-1); //TODO: arreglar signos
	return (inter);
}
