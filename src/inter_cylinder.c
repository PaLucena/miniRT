/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:14:03 by palucena          #+#    #+#             */
/*   Updated: 2024/02/05 16:38:21 by ealgar-c         ###   ########.fr       */
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
	return (shp);
}

t_inter	*cy_valid_coll(t_circle *top, t_circle *bot)
{
	bool	top_valid;
	bool	bot_valid;

	top_valid = false;
	bot_valid = false;
	if (top->coll && (v_mod(v_get_from2(top->p,
					top->coll->q)) <= top->diam / 2))
		top_valid = true;
	if (bot->coll && (v_mod(v_get_from2(bot->p,
					bot->coll->q)) <= bot->diam / 2.0))
		bot_valid = true;
	if (top_valid && bot_valid)
	{
		if (top->coll->d < bot->coll->d)
			return (free(bot->coll), top->coll);
		return (free(top->coll), bot->coll);
	}
	if (top_valid)
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
	return (cy_valid_coll(top, bot));
}

t_inter	*cy_body_coll(t_vector ray, t_shape *cy, t_info *in)
{
	t_inter		*coll;
	t_point		abc;
	t_vector	cross_cc;

	coll = malloc(sizeof(t_inter));
	abc.x = v_dot_product(v_cross_product(cy->prop.n_vec, ray), v_cross_product(cy->prop.n_vec, ray));
	cross_cc = v_cross_product(cy->prop.n_vec, v_get_from2(cy->prop.c, in->cset->point));
	abc.y = 2 * (v_dot_product(cross_cc, v_cross_product(cy->prop.n_vec, ray)));
	abc.z = v_dot_product(cross_cc, cross_cc) - pow(cy->prop.rad, 2);
	if (test)
		printf("a: %f b: %f c: %f\n", abc.x, abc.y, abc.z);
	coll->d = quadratic_equation(abc.x, abc.y, abc.z);
	if (coll->d < 0)
		return (free(coll), NULL);
	coll->q = inter_point_coords(in, coll, ray, cy->type);
	if (test)
		printf("pt %f %f %f\n", coll->q.x, coll->q.y, coll->q.z);
	return (coll);
}

t_inter	*cy_check_closest(t_inter *caps, t_inter *body)
{
	if (caps && body)
	{
		if (caps->d < body->d)
			return (free(body), caps);
		return (free(caps), body);
	}
	else if (caps)
		return (caps);
	else if (body)
		return (body);
	return (NULL);
}

t_inter	*inter_cy(t_info *in, t_shape *cy, t_pixel px)
{
	t_circle	top_cap;
	t_circle	bot_cap;
	t_inter		*caps_coll;
	t_inter		*body_coll;

	top_cap.v = cy->prop.n_vec;
	top_cap.p = cy_cap_center(cy->prop.c, cy->prop.n_vec, cy->prop.height / 2);
	top_cap.diam = cy->prop.rad * 2;
	bot_cap.v = v_opposite_vec(cy->prop.n_vec);
	bot_cap.p = cy_cap_center(cy->prop.c, v_opposite_vec(cy->prop.n_vec), cy->prop.height / 2);
	bot_cap.diam = cy->prop.rad * 2;
	caps_coll = cy_cap_coll(&top_cap, &bot_cap, in, px, cy->index);
	body_coll = cy_body_coll(px.d, cy, in);
	return (cy_check_closest(caps_coll, body_coll));
}

double	distance_cy(t_info *info, t_shape *cy, t_vector ray)
{
	(void) info;
	(void) cy;
	(void) ray;
	return (0.0);
}