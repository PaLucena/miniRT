/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:14:03 by palucena          #+#    #+#             */
/*   Updated: 2024/02/04 20:30:39 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_point	cy_cap_center(t_point cy_c, t_vector v, double d)
{
	t_point	cir_c;

	cir_c.x = cy_c.x + (v.i * d);
	cir_c.y = cy_c.y + (v.j * d);
	cir_c.z = cy_c.z + (v.k * d);
	return (cir_c);
}

t_shape	*cy_circle_to_plane(t_circle	c, int id)
{
	t_shape	*shp;

	shp = malloc(sizeof(t_shape));
	shp->index = id;
	shp->next = NULL;
	shp->prop.c = c.p;
	shp->prop.n_vec = c.v;
	return (shp);
}

t_inter	*cy_cap_coll(t_circle top, t_circle bot, t_info *in, t_pixel px, int id)
{
	t_inter	*top_coll;
	t_inter	*bot_coll;

	top_coll = inter_pl(in, cy_circle_to_plane(top, id), px);
	bot_coll = inter_pl(in, cy_circle_to_plane(bot, id), px);
	if (top_coll && bot_coll)
	{
		if (top_coll->d < bot_coll->d)
			return (top_coll);
		return (bot_coll);
	}
	else if (top_coll)
		return (top_coll);
	else if (bot_coll)
		return (bot_coll);
	return (NULL);
}

t_inter	*inter_cy(t_info *in, t_shape *cy, t_pixel px)
{
	t_circle	top_cap;
	t_circle	bot_cap;
	t_inter		*caps_coll;

	(void)in;
	(void)px;
	top_cap.v = cy->prop.n_vec;
	top_cap.p = cy_cap_center(cy->prop.c, cy->prop.n_vec, cy->prop.height / 2);
	top_cap.diam = cy->prop.rad * 2;
	bot_cap.v = v_opposite_vec(cy->prop.n_vec);
	bot_cap.p = cy_cap_center(cy->prop.c, v_opposite_vec(cy->prop.n_vec), cy->prop.height / 2);
	bot_cap.diam = cy->prop.rad * 2;
	caps_coll = cy_cap_coll(top_cap, bot_cap, in, px, cy->index);
	if (test)
	{
		printf("top cap center: %f %f %f\n", top_cap.p.x, top_cap.p.y, top_cap.p.z);
		printf("bot cap center: %f %f %f\n", bot_cap.p.x, bot_cap.p.y, bot_cap.p.z);
		if (caps_coll)
			printf("COLL: (%f, %f, %f), dist: %f\n", caps_coll->q.x, caps_coll->q.y, caps_coll->q.z, caps_coll->d);
	}
	return (caps_coll);
}

double	distance_cy(t_info *info, t_shape *cy, t_vector ray)
{
	(void) info;
	(void) cy;
	(void) ray;
	return (0.0);
}