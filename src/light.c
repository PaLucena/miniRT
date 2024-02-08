/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:17:47 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/08 15:53:00 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	shadow_search(t_info *info, t_point q)
{
	t_shape		*shape;
	t_vector	ray;
	t_inter		*inter;
	double		d;

	shape = info->shapes_list;
	ray = v_norm(v_get_from2(q, info->lset->point));
	inter = get_closest_collision(ray, q, info);
	d = v_mod(v_get_from2(info->lset->point, q));
	if (inter && inter->d > 0.000001 && inter->d < d)
		return (free(inter), true);
	return (free(inter), false);
}

static t_color	ambient_light(t_color sh, t_aset *aset)
{
	t_color	result;

	result.r = ft_cl_clamp(sh.r * (aset->color.r * aset->ratio / 255));
	result.g = ft_cl_clamp(sh.g * (aset->color.g * aset->ratio / 255));
	result.b = ft_cl_clamp(sh.b * (aset->color.b * aset->ratio / 255));
	return (result);
}

static t_color	diffuse_light(t_info *in, t_inter *inter, t_shape *sh)
{
	double		facing_ratio;
	t_vector	v;
	t_vector	n;
	t_color		result;

	if (shadow_search(in, inter->q))
		return ((t_color){0,0,0});
	v = v_norm(v_get_from2(inter->q, in->lset->point));
	if (sh->type == PL)
		n = v_norm(sh->prop.n_vec);
	else
		n = v_norm(v_get_from2(sh->prop.c, inter->q));
	facing_ratio = v_dot_product(v, n);
	result.r = ft_cl_clamp(sh->prop.color.r * (in->lset->color.r * in->lset->brightness / 255) * facing_ratio);
	result.g = ft_cl_clamp(sh->prop.color.g * (in->lset->color.g * in->lset->brightness / 255) * facing_ratio);
	result.b = ft_cl_clamp(sh->prop.color.b * (in->lset->color.b * in->lset->brightness / 255) * facing_ratio);
	return (result);
}

void	ft_phong(t_inter *inter, t_info *info, t_pixel px)
{
	t_shape	*shape;
	t_color	result;

	shape = info->shapes_list;
	while (shape->index != inter->index)
		shape = shape->next;
	result = shape->prop.color;
	result = ambient_light(shape->prop.color, info->aset);
	result = add_color(result, diffuse_light(info, inter, shape));
	mlx_put_pixel(info->mlx_s.win, px.i, px.j, get_rgba(result));
}
