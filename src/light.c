/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:17:47 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/19 12:29:09 by ealgar-c         ###   ########.fr       */
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

 static t_color	ph_iamb(t_info *info, t_color color_obj)
{
	t_color	amb_color;

	amb_color.r = ft_cl_clamp(color_obj.r + ft_cl_clamp(info->aset->color.r * info->aset->ratio));
	amb_color.g = ft_cl_clamp(color_obj.g + ft_cl_clamp(info->aset->color.g * info->aset->ratio));
	amb_color.b = ft_cl_clamp(color_obj.b + ft_cl_clamp(info->aset->color.b * info->aset->ratio));
	return (amb_color);
}

void	ft_phong(t_inter *inter, t_info *info, double x, double y)
{
	t_shape	*shape;
	t_color	amb;
	t_color	diff;

	shape = info->shapes_list;
	while (shape->index != inter->index)
		shape = shape->next;
	amb = ph_iamb(info, shape->prop.color);
	//printf("(AMB) R:%i, G:%i, B:%i\n", amb.r, amb.g, amb.b);
	diff = ph_idiffuse(amb, info, shape, *inter); // FIXME: no va bien
	mlx_put_pixel(info->mlx_s.win, x, y, get_rgba(shape->prop.color));
}

void	ft_darkness(t_info *info, double x, double y)
{
	t_color	black;

	black.r = 0;
	black.g = 0;
	black.b = 0;
	mlx_put_pixel(info->mlx_s.win, x, y, get_rgba(black));
}