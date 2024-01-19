/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:53:46 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/19 11:58:14 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


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
	return
}