/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:17:47 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/20 14:28:25 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	shadow_search(t_info *info, t_lset *light, t_point q)
{
	t_inter		*inter;
	t_vector	ray;
	double		d;

	ray = v_norm(v_get_from2(q, light->point));
	inter = get_closest_collision(ray, q, info);
	d = v_mod(v_get_from2(info->lset->point, q));
	if (inter && inter->d > EPS && inter->d < d + EPS)
		return (free(inter), true);
	return (free(inter), false);
}

static t_color	ambient_light(t_color sh, t_aset *aset)
{
	t_color	result;

	result.r = ft_cl_clamp(sh.r * (aset->color.r * aset->ratio / MAXCOL));
	result.g = ft_cl_clamp(sh.g * (aset->color.g * aset->ratio / MAXCOL));
	result.b = ft_cl_clamp(sh.b * (aset->color.b * aset->ratio / MAXCOL));
	return (result);
}

static t_color	diffuse_light(t_lset *light, t_inter *inter, t_shape *sh)
{
	double		vn;
	t_color		result;

	vn = v_dot_product(v_norm(v_get_from2(inter->q,
					light->point)), inter->norm);
	result.r = ft_cl_clamp(sh->prop.color.r * vn);
	result.g = ft_cl_clamp(sh->prop.color.g * vn);
	result.b = ft_cl_clamp(sh->prop.color.b * vn);
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
	if (!shadow_search(info, info->lset, inter->q))
		result = add_color(result, diffuse_light(info->lset, inter, shape));
	mlx_put_pixel(info->mlx_s.win, px.i, px.j, get_rgba(result));
}
