/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:17:47 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/09 17:59:13 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/miniRT_bonus.h"

static bool	shadow_search(t_info *info, t_lset *light, t_point q)
{
	t_inter		*inter;
	t_vector	ray;
	double		d;

	ray = v_norm(v_get_from2(q, light->point));
	inter = get_closest_collision(ray, q, info);
	d = v_mod(v_get_from2(info->lset->point, q));
	if (inter && inter->d > EPS && inter->d < d)
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

static t_color	diffuse_light(t_lset *light, t_inter *inter, t_shape *sh)
{
	t_vector	v;
	t_vector	n;
	double		vn;
	t_color		result;

	v = v_norm(v_get_from2(inter->q, light->point));
	if (sh->type == PL)
		n = v_norm(sh->prop.n_vec);
	else
		n = v_norm(v_get_from2(sh->prop.c, inter->q));
	vn = v_dot_product(v, n);
	result.r = sh->prop.color.r * (light->color.r * light->brightness / 255);
	result.r = ft_cl_clamp(result.r * vn);
	result.g = sh->prop.color.g * (light->color.g * light->brightness / 255);
	result.g = ft_cl_clamp(result.g * vn);
	result.b = sh->prop.color.b * (light->color.b * light->brightness / 255);
	result.b = ft_cl_clamp(result.b * vn);
	return (result);
}

static t_color	specular_ref(t_info *in, t_lset *l, t_inter *inter, t_shape *sh)
{
	double		refr;
	t_vector	v_refr;
	t_vector	tmp;
	t_vector	n;
	t_color		result;

	if (sh->type == PL)
		n = v_norm(sh->prop.n_vec);
	else
		n = v_norm(v_get_from2(sh->prop.c, inter->q));
	v_refr = v_norm(v_opposite_vec(v_get_from2(inter->q, l->point)));
 	refr = v_dot_product(n, v_refr);
	v_refr = v_norm(v_opposite_vec(v_get_from2(inter->q, l->point)));
 	v_refr = v_get_from2(v_to_p(v_esc_mult(n, (2 * refr))), v_to_p(v_refr));
	tmp = v_norm(v_get_from2(in->cset->point, inter->q));
	refr = v_dot_product(v_refr, tmp);
	if (refr > 0)
		return ((t_color){0,0,0});
	result.r = ft_cl_clamp(l->color.r * pow(refr, BRIGHTNESS));
	result.g = ft_cl_clamp(l->color.g * pow(refr, BRIGHTNESS));
	result.b = ft_cl_clamp(l->color.b * pow(refr, BRIGHTNESS));
	return (result);
}   

void	ft_phong(t_inter *inter, t_info *info, t_pixel px)
{
	t_shape	*shape;
	t_lset	*light;
	t_color	rslt;

	shape = info->shapes_list;
	light = info->lset;
	while (shape->index != inter->index)
		shape = shape->next;
	rslt = shape->prop.color;
	rslt = ambient_light(shape->prop.color, info->aset);
	while (light)
	{
		if (!shadow_search(info, light, inter->q))
		{
			rslt = add_color(rslt, diffuse_light(light, inter, shape));
			rslt = add_color(rslt, specular_ref(info, light, inter, shape));
		}
		light = light->next;
	}
	mlx_put_pixel(info->mlx_s.win, px.i, px.j, get_rgba(rslt));
}
