/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:18:39 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/19 12:14:32 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static void	khook_left(t_info *info)
{
	info->cset->point.x -= 0.01;
	printf("a little to the left\n");
}

static void	khook_right(t_info *info)
{
	info->cset->point.x += 0.01;
	printf("a little to the right\n");
}

static void	khook_down(t_info *info)
{
	info->cset->point.y -= 0.01;
	printf("a little to the bottom\n");
}

static void	khook_up(t_info *info)
{
	info->cset->point.y += 0.01;
	printf("a little to the top\n");
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
		khook_left(info);
	}
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_UP))
	{
		redo = true;
		khook_up(info);
	}

	if (redo)
		put_pixels(info);
}
