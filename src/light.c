/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:17:47 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/04 16:49:27 by palucena         ###   ########.fr       */
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

/*  static t_color	ph_iamb(t_info *info, t_color color_obj)
{
	t_color	amb_color;

	amb_color.r = ft_cl_clamp(color_obj.r + ft_cl_clamp(info->aset->color.r * info->aset->ratio));
	amb_color.g = ft_cl_clamp(color_obj.g + ft_cl_clamp(info->aset->color.g * info->aset->ratio));
	amb_color.b = ft_cl_clamp(color_obj.b + ft_cl_clamp(info->aset->color.b * info->aset->ratio));
	return (amb_color);
} */

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
			d2 = distance_cy(info, shape, ray);
		else if (shape->type == PL)
			d2 = -1 * distance_pl(info, shape, ray);
		else if (shape->type == SP)
			d2 = distance_sp(info, shape, ray);
		if (d2 != -1 && shape->type == SP)
			d2 = (d2 * -1) + 2;
		if (d2 > 0 && d2 < d)
			return (true);
		shape = shape->next;
	}
	return (false);
}

void	ft_phong(t_inter *inter, t_info *info, t_pixel px)
{
	t_shape	*shape;
	t_color	result;
	/* t_color	amb;
	t_color	diff; */

	shape = info->shapes_list;
	while (shape->index != inter->index)
		shape = shape->next;
	result = diffuse_light(info, inter, shape);
	shadow_search(info, inter->q);
		//printf("%f ", diff);
/* 	amb = ph_iamb(info, shape->prop.color);
	diff = ph_idiffuse(amb, info, shape, *inter); // FIXME: no va bien */
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