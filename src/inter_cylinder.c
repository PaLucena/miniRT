/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:14:03 by palucena          #+#    #+#             */
/*   Updated: 2024/01/22 15:45:07 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_inter	*cy_topcover_inter(t_info *info, t_shape *cy, t_pixel px)
{
	t_shape	*cover_c;
	t_inter	*plane_inter;

	cover_c = malloc(sizeof(t_shape));
	cover_c->prop.c.x = (cy->prop.c.x + (cy->prop.n_vec.i
				* cy->prop.height / 2));
	cover_c->prop.c.y = (cy->prop.c.y + (cy->prop.n_vec.j
				* cy->prop.height / 2));
	cover_c->prop.c.z = (cy->prop.c.z + (cy->prop.n_vec.k
				* cy->prop.height / 2));
	cover_c->index = 0;
	cover_c->prop.n_vec = cy->prop.n_vec;
	plane_inter = inter_pl(info, cover_c, px);
	if (v_mod(v_get_from2(info->cset->point, plane_inter->q)) < cy->prop.rad)
	{
		free (cover_c);
		return (plane_inter);
	}
	free (plane_inter);
	free (cover_c);
	return (NULL);
}

static t_inter	*cy_botcover_inter(t_info *info, t_shape *cy, t_pixel px)
{
	t_shape	*cover_c;
	t_inter	*plane_inter;

	cover_c = malloc(sizeof(t_shape));
	cover_c->prop.c.x = (cy->prop.c.x - (cy->prop.n_vec.i
				* cy->prop.height / 2));
	cover_c->prop.c.y = (cy->prop.c.y - (cy->prop.n_vec.j
				* cy->prop.height / 2));
	cover_c->prop.c.z = (cy->prop.c.z - (cy->prop.n_vec.k
				* cy->prop.height / 2));
	cover_c->index = 0;
	cover_c->prop.n_vec = v_esc_mult(cy->prop.n_vec, -1);
	plane_inter = inter_pl(info, cover_c, px);
	if (v_mod(v_get_from2(info->cset->point, plane_inter->q)) < cy->prop.rad)
	{
		free (cover_c);
		return (plane_inter);
	}
	free (plane_inter);
	free (cover_c);
	return (NULL);
}

t_inter	*inter_cy(t_info *in, t_shape *cy, t_pixel px)
{
	// t_inter		*inter_body;
	t_inter		*inter_top;
	t_inter		*inter_bot;

	// inter_body = cy_body_inter();
	inter_top = cy_topcover_inter(in, cy, px);
	inter_bot = cy_botcover_inter(in, cy, px);
/* 	if (!inter_top && !inter_bot && inter_body)
		return (inter_body); */
	if (inter_top && !inter_bot)
		return (inter_top);
	if (!inter_top && inter_bot)
		return (inter_bot);
	if (inter_top->d < inter_bot->d)
		return (inter_top);
	return (inter_bot);
}
