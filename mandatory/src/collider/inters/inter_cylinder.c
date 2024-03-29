/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:14:03 by palucena          #+#    #+#             */
/*   Updated: 2024/02/19 20:29:10 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	cy_useful_dist(t_quad quad, t_vector ray, t_point origin, t_shape *cy)
{
	t_point	coll_t1;
	t_point	coll_t2;
	double	q1;
	double	q2;
	double	half;

	half = cy->prop.height / 2;
	coll_t1 = v_get_endpoint(ray, quad.t1, origin);
	coll_t2 = v_get_endpoint(ray, quad.t2, origin);
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

static t_vector	cy_get_body_norm(t_shape *cy, t_inter *coll)
{
	t_vector	base_coll;
	double		projection;
	t_vector	surf;
	t_vector	result;

	base_coll = v_get_from2(cy->prop.c, coll->q);
	projection = v_dot_product(base_coll, cy->prop.n_vec);
	surf = v_sum((t_vector){cy->prop.c.x, cy->prop.c.y, cy->prop.c.z},
			v_esc_mult(cy->prop.n_vec, projection));
	result = v_norm(v_get_from2((t_point){surf.i, surf.j, surf.k}, coll->q));
	return (result);
}

t_inter	*cy_body_coll(t_shape *cy, t_vector ray, t_point origin)
{
	t_inter		*coll;
	t_quad		quad;
	t_vector	cross_cc;

	coll = malloc(sizeof(t_inter));
	coll->index = cy->index;
	quad.cc = v_get_from2(cy->prop.c, origin);
	quad.a = v_dot_product(v_cross_product(cy->prop.n_vec, ray),
			v_cross_product(cy->prop.n_vec, ray));
	cross_cc = v_cross_product(cy->prop.n_vec, quad.cc);
	quad.b = 2 * (v_dot_product(cross_cc,
				v_cross_product(cy->prop.n_vec, ray)));
	quad.c = v_dot_product(cross_cc, cross_cc) - pow(cy->prop.rad, 2);
	coll->d = quadratic_equation(&quad);
	if (coll->d < EPS)
		return (free(coll), NULL);
	coll->d = cy_useful_dist(quad, ray, origin, cy);
	if (coll->d < EPS)
		return (free(coll), NULL);
	coll->q = inter_point_coords(origin, coll, ray);
	coll->norm = cy_get_body_norm(cy, coll);
	return (coll);
}

t_inter	*cy_check_closest(t_inter *caps, t_inter *body)
{
	if (caps && body)
	{
		if (caps->d < body->d && caps->d > EPS)
			return (free(body), caps);
		else if (body->d > EPS)
			return (free(caps), body);
	}
	else if (caps && caps->d > EPS)
		return (caps);
	else if (body && body->d > EPS)
		return (body);
	if (body)
		free(body);
	if (caps)
		free(caps);
	return (NULL);
}

t_inter	*inter_cy(t_shape *cy, t_vector ray, t_point origin)
{
	t_circle	top_cap;
	t_circle	bot_cap;
	t_inter		*caps_coll;
	t_inter		*body_coll;

	top_cap.v = cy->prop.n_vec;
	top_cap.p = v_get_endpoint(top_cap.v, cy->prop.height / 2, cy->prop.c);
	top_cap.diam = cy->prop.rad * 2;
	top_cap.shape_id = cy->index;
	bot_cap.v = v_opposite_vec(cy->prop.n_vec);
	bot_cap.p = v_get_endpoint(bot_cap.v, cy->prop.height / 2, cy->prop.c);
	bot_cap.diam = cy->prop.rad * 2;
	bot_cap.shape_id = cy->index;
	caps_coll = cy_cap_coll(&top_cap, &bot_cap, ray, origin);
	body_coll = cy_body_coll(cy, ray, origin);
	return (cy_check_closest(caps_coll, body_coll));
}
