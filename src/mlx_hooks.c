/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:18:39 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/12 16:44:47 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static void	khook_left(t_info *info)
{
	(void)info;
	printf("a little to the left\n");
}

static void	khook_right(t_info *info)
{
	(void)info;
	printf("a little to the right\n");
}

static void	khook_up(t_info *info)
{
	(void)info;
	printf("a little to the top\n");
}

static void	khook_down(t_info *info)
{
	(void)info;
	printf("a little to the bottom\n");
}

void	ft_keyhook(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_ESCAPE))
		ft_exit_program(param);
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_LEFT))
		khook_left(info);
	else if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_UP))
		khook_up(info);
	else if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_DOWN))
		khook_down(info);
	else if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_RIGHT))
		khook_right(info);
	else
		return ;
}
