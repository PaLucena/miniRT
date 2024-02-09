/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:46:05 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/08 20:19:01 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static t_inter	*px_pick_closest(t_inter *old, t_inter *new)
{
	if (new)
	{
		if (!old)
			old = new;
		else if (new && new->d > EPS && new->d < old->d)
		{
			free (old);
			old = new;
		}
		else
			free(new);
	}
	return (old);
}

t_inter	*get_closest_collision(t_vector ray, t_point origin, t_info *info)
{
	t_inter	*tmp_inter;
	t_inter	*new_inter;
	t_shape	*tmp_shape;

	tmp_shape = info->shapes_list;
	tmp_inter = NULL;
	while (tmp_shape)
	{
		if (tmp_shape->type == CY)
			new_inter = inter_cy(tmp_shape, ray, origin);
		else if (tmp_shape->type == PL)
			new_inter = inter_pl(tmp_shape, ray, origin);
		else if (tmp_shape->type == SP)
			new_inter = inter_sp(tmp_shape, ray, origin);
		tmp_inter = px_pick_closest(tmp_inter, new_inter);
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
			px.d = camera_ray_direction(info, px);
			inter_tmp = get_closest_collision(px.d, info->cset->point, info);
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
	//printf("test 3\n");
}
