/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:14:03 by palucena          #+#    #+#             */
/*   Updated: 2024/02/05 18:44:00 by ealgar-c         ###   ########.fr       */
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

double	cy_useful_dist(t_quad quad, t_vector ray, t_info *in, t_shape *cy)
{
	t_point	coll_t1;
	t_point	coll_t2;
	double	q1;
	double	q2;
	double	half;

	half = cy->prop.height / 2;

	coll_t1 = v_get_endpoint(ray, quad.t1, in->cset->point);
	coll_t2 = v_get_endpoint(ray, quad.t2, in->cset->point);
	q1 = v_dot_product(v_get_from2(cy->prop.c, coll_t1), cy->prop.n_vec);
	q2 = v_dot_product(v_get_from2(cy->prop.c, coll_t2), cy->prop.n_vec);
	if ((q1 >= -half && q1 <= half) && (q2 >= -half && q2 <= half))
	{
		if (quad.t1 < quad.t2)
			return (quad.t1);
		return (quad.t2);
	}
	if (q1 >= -half && q1 <= half)
		return (quad.t1);
	if (q2 >= -half && q2 <= half)
		return (quad.t2);
	return (-1.0);
}

t_inter	*cy_body_coll(t_vector ray, t_shape *cy, t_info *in)
{
	t_inter		*coll;
	t_quad		quad;
	t_vector	cross_cc;

	coll = malloc(sizeof(t_inter));
	quad.cc = v_get_from2(cy->prop.c, in->cset->point);
	quad.a = v_dot_product(v_cross_product(cy->prop.n_vec, ray), v_cross_product(cy->prop.n_vec, ray));
	cross_cc = v_cross_product(cy->prop.n_vec, quad.cc);
	quad.b = 2 * (v_dot_product(cross_cc, v_cross_product(cy->prop.n_vec, ray)));
	quad.c = v_dot_product(cross_cc, cross_cc) - pow(cy->prop.rad, 2);
	coll->d = quadratic_equation(&quad);
	if (coll->d < 0)
		return (free(coll), NULL);
	coll->d = cy_useful_dist(quad, ray, in, cy);
	if (coll->d < 0)
		return (free(coll), NULL);
	coll->q = inter_point_coords(in, coll, ray, cy->type);
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

double	distance_cy(t_point orig, t_point coll)
{
	return (v_mod(v_get_from2(orig, coll)));
}
