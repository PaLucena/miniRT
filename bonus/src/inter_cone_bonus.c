/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cone_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:30:13 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/20 14:42:01 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

static t_inter	*co_valid_cap_coll(t_circle *cap)
{
	if (cap->coll && (v_mod(v_get_from2(cap->p,
					cap->coll->q)) <= cap->diam / 2))
		return (cap->coll);
	return (free(cap->coll), NULL);
}

static t_inter	*co_cap_coll(t_circle *cap, t_vector ray, t_point orig)
{
	cap->plane = cy_circle_to_plane(cap);
	cap->coll = inter_pl(cap->plane, ray, orig);
	return (free(cap->plane), co_valid_cap_coll(cap));
}

static void	co_get_norm_vec(t_shape *co, t_inter *inter)
{
	t_vector	d;
	double		hp;
	double		rp;
	t_vector	vp;

	vp = v_get_from2(co->prop.c, inter->q);
	d = v_norm(co->prop.n_vec);
	hp = v_mod(v_esc_mult(d, v_dot_product(vp, d) / (pow(v_mod(d), 2) + EPS)));
	rp = (hp / co->prop.height) * co->prop.rad;
	inter->norm = v_esc_mult(v_norm(vp), rp);
}

t_inter	*co_body_coll(t_shape *co, t_vector ray, t_point origin)
{
	double		ang;
	t_quad		quad;
	t_inter		*inter;

	inter = malloc(sizeof(t_inter));
	inter->index = co->index;
	ang = atan(co->prop.rad / co->prop.height);
	quad.cc = v_get_from2(co->prop.c, origin);
	quad.a = pow(v_dot_product(ray, co->prop.n_vec), 2) - pow(cos(ang), 2);
	quad.b = 2 * ((v_dot_product(ray, co->prop.n_vec) * v_dot_product(quad.cc,
					co->prop.n_vec)) - (v_dot_product(ray,
					quad.cc) * pow(cos(ang), 2)));
	quad.c = (pow(v_dot_product(quad.cc, co->prop.n_vec),
				2) - v_dot_product(quad.cc, quad.cc) * pow(cos(ang), 2));
	inter->d = quadratic_equation(&quad);
	if (inter->d < EPS)
		return (free(inter), NULL);
	inter->q = v_get_endpoint(ray, inter->d, origin);
	if (!co_outside_lims(co, inter, ang))
		return (free(inter), NULL);
	co_get_norm_vec(co, inter);
	return (inter);
}

t_inter	*inter_co(t_shape *co, t_vector ray, t_point origin)
{
	t_inter		*inter_body;
	t_inter		*inter_cap;
	t_circle	cap;

	cap.shape_id = co->index;
	cap.p = v_get_endpoint(co->prop.n_vec, co->prop.height, co->prop.c);
	cap.v = co->prop.n_vec;
	cap.diam = co->prop.rad * 2;
	inter_cap = co_cap_coll(&cap, ray, origin);
	inter_body = co_body_coll(co, ray, origin);
	return (cy_co_check_closest(inter_cap, inter_body));
}
