/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:14:03 by palucena          #+#    #+#             */
/*   Updated: 2024/01/22 15:11:05 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_inter	*cy_topcover_inter(t_info *info, t_shape *cy, t_pixel px)
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
	plane_inter	= inter_pl(info, cover_c, px);
	if (v_mod(v_get_from2(info->cset->point, plane_inter->q)) < cy->prop.rad)
	{
		free (plane_inter);
		return (cover_c);
	}
	free (plane_inter);
	free (cover_c);
	return (NULL);
}

t_inter	*inter_cy(t_info *in, t_shape *cy, t_pixel px)
{
	t_inter		*inter_body;
	t_inter		*inter_top;
	t_inter		*inter_bot;

	inter_body = cy_body_inter();
	inter_body = cy_topcover_inter();
	inter_body = cy_botcover_inter();
	inter->index = cy->index;
	cc = v_get_from2(in->cset->point, sp->prop.c);
	abc = calculate_abc(in, sp, px.d, cc);
	inter->d = quadratic_equation(abc.x, abc.y, abc.z);
	if (inter->d < 0)
	{
		free (inter);
		return (NULL);
	}
	cc = v_norm(cc);
	inter->q = inter_point_coords(in, inter, cc);
	return (inter);
}
