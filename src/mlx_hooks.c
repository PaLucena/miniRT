/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:18:39 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/06 17:03:36 by palucena         ###   ########.fr       */
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
