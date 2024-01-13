/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:46:05 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/13 18:15:16 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_inter	*get_closest_collision(double x, double y, t_info *info)
{
	t_inter	*tmp_inter;
	t_inter	*new_inter;
	t_shape	*tmp_shape;

	tmp_shape = info->shapes_list;
	tmp_inter = NULL;
	while (tmp_shape)
	{
		if (tmp_shape->type == CY)
			new_inter = inter_cy(info, x, y);
		else if (tmp_shape->type == PL)
			new_inter = inter_pl(info, x, y);
		else if (tmp_shape->type == SP)
			new_inter = inter_sp(info, x, y);
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
	double	x;
	double	y;
	t_inter	*inter_tmp;

	x = 0.0;
	y = 0.0;
	while (x <= WIDTH)
	{
		while (y <= HEIGHT)
		{
			inter_tmp = get_closest_collision(x, y, info);
			if (inter_tmp)
			{
				px_put_coll();
			}
			else
				px_put_black();
			free(inter_tmp);
			y++;
		}
		x++;
	}
}
