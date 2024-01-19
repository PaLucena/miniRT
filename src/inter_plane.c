/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:12:56 by palucena          #+#    #+#             */
/*   Updated: 2024/01/19 15:13:51 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_inter	*inter_pl(t_info *in, t_shape *pl, t_pixel px)
{
	t_inter	*inter;
	double	top;
	double	bot;

	inter = malloc(sizeof(t_inter));
	inter->index = pl->index;
	top = v_dot_product(v_get_from2(in->cset->point, pl->prop.c),
			pl->prop.n_vec);
	bot = v_dot_product(px.d, pl->prop.n_vec);
	if (bot == 0)
	{
		if (top == 0)
			inter->d = 0;
		else
		{
			free (inter);
			return (NULL);
		}
	}
	else
		inter->d = top / bot;
	inter->d *= -1;
	inter->q = inter_point_coords(in, inter, px.d);
	return (inter);
}


// d -> ?
// p0 -> pl->prop.c
// p -> ?
// n -> pl->prop.n_vec
// l0 -> in->cset->point
// l -> px.d