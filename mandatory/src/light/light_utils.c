/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:19:30 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/03/05 17:00:13 by palucena         ###   ########.fr       */
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
	if (EPS > runcl)
		return (0);
	if (MAXCOL < runcl)
		return (255);
	return (runcl);
}

t_color	add_color(t_color c1, t_color c2)
{
	t_color	result;

	result.r = ft_cl_clamp(c1.r + c2.r);
	result.g = ft_cl_clamp(c1.g + c2.g);
	result.b = ft_cl_clamp(c1.b + c2.b);
	return (result);
}

void	ft_darkness(t_info *info, double x, double y)
{
	t_color	black;

	black.r = 80;
	black.g = 80;
	black.b = 80;
	mlx_put_pixel(info->mlx_s.win, x, y, get_rgba(black));
}
