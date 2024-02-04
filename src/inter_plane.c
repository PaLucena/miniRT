/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:12:56 by palucena          #+#    #+#             */
/*   Updated: 2024/02/04 20:26:31 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	distance_pl(t_info *info, t_shape *pl, t_vector ray)
{
	double	top;
	double	bot;

	bot = v_dot_product(ray, pl->prop.n_vec);
	if (bot == 0)
		return (0);
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
	if (!inter->d)
		return (free(inter), NULL);
	inter->q = inter_point_coords(in, inter, px.d, pl->type);
	if (test)
		printf("%f\n", inter->d);
	return (inter);
}
