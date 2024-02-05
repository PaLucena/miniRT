/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:17:47 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/05 18:26:12 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

uint32_t	get_rgba(t_color color)
{
	return (color.r << 24 | color.g << 16 | color.b << 8 | 255);
}

int	ft_cl_clamp(double unclamped)
{
	int	runcl;

	runcl = round(unclamped);
	if (0 > runcl)
		return (0);
	if (255 < runcl)
		return (255);
	return (runcl);
}

bool	shadow_search(t_info *info, t_point q)
{
	t_shape		*shape;
	t_vector	ray;
	double		d;
	double		d2;

	shape = info->shapes_list;
	ray = v_norm(v_get_from2(info->lset->point, q));
	d = v_mod(v_get_from2(info->lset->point, q));
	while (shape)
	{
		if (shape->type == CY)
			d2 = distance_cy(info->lset->point, shape, ray);
		else if (shape->type == PL)
			d2 = distance_pl(info->lset->point, shape, ray);
		else if (shape->type == SP)
			d2 = distance_sp(info->lset->point, shape, ray);
		if (d2 > 0 && d2 < d)
			return (true);
		shape = shape->next;
	}
	return (false);
}

t_color	add_color(t_color c1, t_color c2)
{
	t_color	result;

	result.r = ft_cl_clamp(c1.r + c2.r);
	result.g = ft_cl_clamp(c1.g + c2.g);
	result.b = ft_cl_clamp(c1.b + c2.b);
	return (result);
}

t_color	ambient_light(t_color sh, t_aset *aset)
{
	t_color	result;

	result.r = ft_cl_clamp(sh.r * (aset->color.r * aset->ratio / 255));
	result.g = ft_cl_clamp(sh.g * (aset->color.g * aset->ratio / 255));
	result.b = ft_cl_clamp(sh.b * (aset->color.b * aset->ratio / 255));
	return (result);
}

void	ft_phong(t_inter *inter, t_info *info, t_pixel px)
{
	t_shape	*shape;
	t_color	result;

	shape = info->shapes_list;
	while (shape->index != inter->index)
		shape = shape->next;
//	result = shape->prop.color;
	result = ambient_light(shape->prop.color, info->aset);
	result = add_color(result, diffuse_light(info, inter, shape, result));
/* 	if (shadow_search(info, inter->q))
	{
		result.r *= 0.5;
		result.g *= 0.5;
		result.b *= 0.5;
	} */
	if (test)
		printf("Resultado: %d %d %d\n", result.r, result.g, result.b);
	mlx_put_pixel(info->mlx_s.win, px.i, px.j, get_rgba(result));
}

void	ft_darkness(t_info *info, double x, double y)
{
	t_color	black;

	black.r = 0;
	black.g = 0;
	black.b = 0;
	mlx_put_pixel(info->mlx_s.win, x, y, get_rgba(black));
}