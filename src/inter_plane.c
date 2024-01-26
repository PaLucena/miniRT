/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:12:56 by palucena          #+#    #+#             */
/*   Updated: 2024/01/26 14:37:49 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	plane_hit(t_info *in, t_shape *pl, t_pixel px)
{
	double	numerator;
	double	denominator;

	numerator = v_dot_product(v_get_from2(in->cset->point, pl->prop.c),
			pl->prop.n_vec);
	denominator = v_dot_product(px.d, pl->prop.n_vec);
	if (denominator > 0.000001)
		return (true);
	return (false);
}

t_inter	*inter_pl(t_info *in, t_shape *pl, t_pixel px)
{
	t_inter	*inter;
	double	top;
	double	bot;

	if (!plane_hit(in, pl, px))
		return (NULL);
	inter = malloc(sizeof(t_inter));
	inter->index = pl->index;
	top = v_dot_product(v_get_from2(in->cset->point, pl->prop.c),
			pl->prop.n_vec);
	bot = v_dot_product(px.d, pl->prop.n_vec);
	inter->d = (top / bot);
	inter->q = inter_point_coords(in, inter, px.d, pl->type);
	inter->q.x *= -1;
	inter->d *= (-1);
	return (inter);
}
