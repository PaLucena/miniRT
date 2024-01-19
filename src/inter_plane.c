/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:12:56 by palucena          #+#    #+#             */
/*   Updated: 2024/01/19 17:18:03 by palucena         ###   ########.fr       */
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
		inter->d = -1;
		if (top == 0)
			inter->d = 0;
	}
	else
		inter->d = top / bot;
/* 	if (px.i == in->width / 2 && px.j == in->height / 2)
			printf(" Choca con %d -> %f\n\t\ttop -> %f bot -> %f\n", inter->index, inter->d, top, bot); */
	if (inter->d < 0)
	{
		free (inter);
		return (NULL);
	}
	inter->q = inter_point_coords(in, inter, px.d);
	return (inter);
}

// d -> ?
// p0 -> pl->prop.c
// p -> ?
// n -> pl->prop.n_vec
// l0 -> in->cset->point
// l -> px.d