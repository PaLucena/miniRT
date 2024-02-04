/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:14:03 by palucena          #+#    #+#             */
/*   Updated: 2024/02/05 00:05:17 by ealgar-c         ###   ########.fr       */
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

t_shape	*cy_circle_to_plane(t_circle *c, int id)
{
	t_shape	*shp;

	shp = malloc(sizeof(t_shape));
	shp->index = id;
	shp->next = NULL;
	shp->prop.c = c->p;
	shp->prop.n_vec = c->v;
	/* if (test)
	{
		printf("plane pt: %f %f %f\n", shp->prop.c.x, shp->prop.c.y, shp->prop.c.z);
		printf("plane vec: %f %f %f\n", shp->prop.n_vec.i, shp->prop.n_vec.j, shp->prop.n_vec.k);
	} */
	return (shp);
}

t_inter	*cy_valid_coll(t_circle *top, t_circle *bot)
{
	bool	top_valid;
	bool	bot_valid;

	top_valid = false;
	bot_valid = false;
	if (top->coll)
	{
		if (test)
			printf("dist ctr to coll TOP:\t%f\n", v_mod(v_get_from2(top->p, top->coll->q)));
		if (v_mod(v_get_from2(top->p, top->coll->q)) <= top->diam / 2)
			top_valid = true;
	}
	if (bot->coll)
	{
		if (test)
			printf("dist ctr to coll BOT:\t%f\n", v_mod(v_get_from2(bot->p, bot->coll->q)));
		if (v_mod(v_get_from2(bot->p, bot->coll->q)) <= bot->diam / 2.0)
			bot_valid = true;
	}
	if (top_valid && bot_valid)
	{
		if (top->coll->d < bot->coll->d)
			return (top->coll);
		return (bot->coll);
	}
	else if (top_valid)
		return (top->coll);
	else if (bot_valid)
		return (bot->coll);
	return (NULL);
}

t_inter	*cy_cap_coll(t_circle *top, t_circle *bot, t_info *in, t_pixel px, int id)
{
	top->plane = cy_circle_to_plane(top, id);
	bot->plane = cy_circle_to_plane(bot, id);
	top->coll = inter_pl(in, top->plane, px);
	bot->coll = inter_pl(in, bot->plane, px);
	if (test)
	{
		printf("center of circle TOP:\t\t%f %f %f\n", top->p.x, top->p.y, top->p.z);
		printf("vector of the plane TOP:\t%f %f %f\n", top->plane->prop.n_vec.i, top->plane->prop.n_vec.j, top->plane->prop.n_vec.k);
		printf("pt of collision TOP:\t\t%f %f %f\n\n\n", top->coll->q.x, top->coll->q.y, top->coll->q.z);
		printf("center of circle BOT:\t\t%f %f %f\n", bot->p.x, bot->p.y, bot->p.z);
		printf("vector of the plane BOT:\t%f %f %f\n", bot->plane->prop.n_vec.i, bot->plane->prop.n_vec.j, bot->plane->prop.n_vec.k);
		printf("pt of collision BOT:\t\t%f %f %f\n", bot->coll->q.x, bot->coll->q.y, bot->coll->q.z);
	}
	return (cy_valid_coll(top, bot));
}

t_inter	*inter_cy(t_info *in, t_shape *cy, t_pixel px)
{
	t_circle	top_cap;
	t_circle	bot_cap;
	t_inter		*caps_coll;

	top_cap.v = cy->prop.n_vec;
	top_cap.p = cy_cap_center(cy->prop.c, cy->prop.n_vec, cy->prop.height / 2);
	top_cap.diam = cy->prop.rad * 2;
	bot_cap.v = cy->prop.n_vec;
	bot_cap.p = cy_cap_center(cy->prop.c, v_opposite_vec(cy->prop.n_vec), cy->prop.height / 2);
	bot_cap.diam = cy->prop.rad * 2;
	caps_coll = cy_cap_coll(&top_cap, &bot_cap, in, px, cy->index);
	if (test && caps_coll)
		printf("COLL: (%f, %f, %f), dist: %f\n", caps_coll->q.x, caps_coll->q.y, caps_coll->q.z, caps_coll->d);
	return (caps_coll);
}

double	distance_cy(t_info *info, t_shape *cy, t_vector ray)
{
	(void) info;
	(void) cy;
	(void) ray;
	return (0.0);
}