/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:46:05 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/19 12:09:02 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_inter	*get_closest_collision(t_pixel px, t_info *info)
{
	t_inter	*tmp_inter;
	t_inter	*new_inter;
	t_shape	*tmp_shape;

	tmp_shape = info->shapes_list;
	tmp_inter = NULL;
	while (tmp_shape)
	{
		if (tmp_shape->type == CY)
			new_inter = inter_cy(info, tmp_shape, px);
		else if (tmp_shape->type == PL)
			new_inter = inter_pl(info, tmp_shape, px);
		else if (tmp_shape->type == SP)
			new_inter = inter_sp(info, tmp_shape, px);
		if (new_inter)
		{
			if (!tmp_inter)
				tmp_inter = new_inter;
			else if (new_inter->d < tmp_inter->d)
				tmp_inter = new_inter;
		}
		tmp_shape = tmp_shape->next;
	}
	return (tmp_inter);
}

uint32_t	get_rgba(t_inter *inter, t_info *info)
{
	t_shape	*shape;
	int		r;
	int		g;
	int		b;

	if (inter)
	{
		shape = info->shapes_list;
		while (shape->index != inter->index)
			shape = shape->next;
		r = shape->prop.color.r;
		g = shape->prop.color.g;
		b = shape->prop.color.b;
		return (r << 24 | g << 16 | b << 8 | 255);
	}
	else
		return (0 << 24 | 0 << 16 | 0 << 8 | 255);
}

void	put_pixels(t_info *info)
{
	t_pixel	px;
	t_inter	*inter_tmp;

	px.j = 0;
	image_plane_coords(info);
	while (px.j < HEIGHT)
	{
		px.i = 0;
		while (px.i < WIDTH)
		{
			px.p = plane_point_coords(info, px.i, px.j);
			px.d = v_norm(v_get_from2(info->cset->point, px.p));
			inter_tmp = get_closest_collision(px, info);
			if (inter_tmp)
				mlx_put_pixel(info->mlx_s.win, px.i, px.j,
					get_rgba(inter_tmp, info));
			free(inter_tmp);
			px.i++;
		}
		px.j++;
	}
	mlx_image_to_window(info->mlx_s.mlx, info->mlx_s.win, 0, 0);
}
