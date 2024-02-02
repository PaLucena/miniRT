/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:46:05 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/02 14:40:30 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_inter	*get_closest_collision(t_pixel px, t_info *info, bool a)
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
			new_inter = inter_sp(info, tmp_shape, px, a);
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

void	put_pixels(t_info *info)
{
	t_pixel	px;
	t_inter	*inter_tmp;

	px.j = 0;
	set_camera(info->cset);
	while (px.j < info->w_height)
	{
		px.i = 0;
		while (px.i < info->w_width)
		{
			px.p = plane_point_coords(info, px.i, px.j);
			px.d = camera_ray_direction(info, px);
			bool a = false;
			if (px.i == 700 && px.j == 500)
				a = true;
			//	printf("HELLO %f %F %f\n", inter_tmp->q.x, inter_tmp->q.y, inter_tmp->q.z);
			inter_tmp = get_closest_collision(px, info, a);
			a = false;
			if (inter_tmp)
				ft_phong(inter_tmp, info, px);
			else
				ft_darkness(info, px.i, px.j);
			free(inter_tmp);
			px.i++;
		}
		px.j++;
	}
	mlx_image_to_window(info->mlx_s.mlx, info->mlx_s.win, 0, 0);
}
