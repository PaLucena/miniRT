/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:46:05 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/15 18:11:20 by ealgar-c         ###   ########.fr       */
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
			printf("No cylinder :'(\n"); //new_inter = inter_cy(info, x, y);
		else if (tmp_shape->type == PL)
			printf("No plane :'(\n"); //new_inter = inter_pl(info, x, y);
		else if (tmp_shape->type == SP)
			new_inter = inter_sp(info, tmp_shape, x, y);
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
	if (inter)
	{
		shape = info->shapes_list;
		while (shape->index != inter->index)
			shape = shape->next;
		return (shape->prop.color.r << 24 | shape->prop.color.g << 16 | shape->prop.color.b << 8 | 255);
	}
	else
		return (0 << 24 | 0 << 16 | 0 << 8 | 255);
}

void	put_pixels(t_info *info)
{
	double	x;
	double	y;
	t_inter	*inter_tmp;

		y = 0;
	image_plane_coords(info);
	while (y < WIDTH)
	{
	x = 0;
		while (x < HEIGHT)
		{
			inter_tmp = get_closest_collision(x, y, info);
			if (inter_tmp)
			{
				printf("(%f)", inter_tmp->d);
				mlx_put_pixel(info->mlx_s.win, x, y, get_rgba(inter_tmp, info));
			}
			else
			{
				printf("()");
				mlx_put_pixel(info->mlx_s.win, x, y, get_rgba(NULL, info));
			}
			free(inter_tmp);
			x++;
		}
		printf("\n");
		y++;
	}
	mlx_image_to_window(info->mlx_s.mlx, info->mlx_s.win, 0, 0);
}

/* void	put_pixels(t_info *info)
{
	int32_t	x;
	int32_t	y;
	//t_inter		*inter_tmp;

	x = 0;
	image_plane_coords(info);
	while (x < WIDTH_INT)
	{
		y = 0;
		while (y < HEIGHT_INT)
		{
			mlx_put_pixel(info->mlx_s.win, x, y, get_rgba(0, 0, 255, 255));
			y++;
		}
		x++;
		printf("new x iter (%i)\n", x);
	}
	mlx_image_to_window(info->mlx_s.mlx, info->mlx_s.win, 0, 0);
	printf("fuera del loop\n");
} */
