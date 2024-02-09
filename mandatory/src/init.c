/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:17:59 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/09 15:47:31 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	khook_debug(struct mlx_key_data keydata, void *param) //FIXME: esto fuera
{
	t_info	*info = (t_info *)param;
	int32_t	x;
	int32_t	y;

	if (keydata.action == MLX_RELEASE && keydata.key == MLX_KEY_D)
	{
		mlx_get_mouse_pos(info->mlx_s.mlx, &x, &y);
		printf("\n\nXY: %d %d\n", x, y);
		printf("Posición: %d %d\n", x, y);
	}
}

void	init_mlx(t_info	*info)
{
	info->mlx_s.mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	info->mlx_s.win = mlx_new_image(info->mlx_s.mlx, WIDTH, HEIGHT);
	mlx_get_monitor_size(0, &info->width, &info->height);
	if (!info->width || !info->height)
	{
		ft_printf("No monitor\n");
		info->width = WIDTH;
		info->height = HEIGHT;
	}
	mlx_close_hook(info->mlx_s.mlx, &ft_exit_program, (void *)info);
	mlx_loop_hook(info->mlx_s.mlx, &ft_keyhook, (void *)info);
	mlx_key_hook(info->mlx_s.mlx, &khook_debug, info); //FIXME: esto fuera
	mlx_resize_hook(info->mlx_s.mlx, &ft_resizehook, (void *)info);
}

t_info	*init_info(char *filename)
{
	t_info	*new;

	new = malloc(sizeof(t_info));
	new->filename = ft_strdup(filename);
	new->aset = NULL;
	new->lset = NULL;
	new->cset = NULL;
	new->shapes_list = NULL;
	new->w_width = WIDTH;
	new->w_height = HEIGHT;
	return (new);
}
