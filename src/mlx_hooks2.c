/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:53:46 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/19 13:18:40 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

void	ft_resizehook(int32_t new_w, int32_t new_h, void *param)
{
	t_info	*info;

	info = (t_info *)param;
	info->width = new_w;
	info->height = new_h;
	mlx_resize_image(info->mlx_s.win, new_w, new_h);
	put_pixels(info);
}

bool	aux_keyhook(t_info	*info)
{
	bool	redo;

	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_DOWN))
	{
		redo = true;
		khook_down(info);
	}
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_RIGHT))
	{
		redo = true;
		khook_right(info);
	}
	return (true);
}
