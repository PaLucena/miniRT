/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:18:39 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/09 15:48:14 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static bool	ft_keyhook2(t_info *info)
{
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_UP))
	{
		info->cset->point.y += 0.1;
		printf("a little to the top\n");
		return (true);
	}
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_DOWN))
	{
		info->cset->point.y -= 0.1;
		printf("a little to the bottom\n");
		return (true);
	}
	return (false);
}

void	ft_resizehook(int32_t new_w, int32_t new_h, void *param)
{
	t_info	*info;

	info = (t_info *)param;
	info->w_width = new_w;
	info->w_height = new_h;
	mlx_resize_image(info->mlx_s.win, new_w, new_h);
	put_pixels(info);
}

void	ft_keyhook(void *param)
{
	t_info	*info;
	bool	redo;

	redo = false;
	info = (t_info *)param;
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_ESCAPE))
		ft_exit_program(param);
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_LEFT))
	{
		redo = true;
		info->cset->point.x -= 0.1;
		printf("a little to the left\n");
	}
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_RIGHT))
	{
		redo = true;
		info->cset->point.x += 0.1;
		printf("a little to the right\n");
	}
	if (ft_keyhook2(info))
		redo = true;
	if (redo)
		put_pixels(info);
}
