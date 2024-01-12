/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:17:59 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/12 16:46:01 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	init_mlx(t_info	*info)
{
	info->mlx_s.mlx = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	info->mlx_s.win = mlx_new_image(info->mlx_s.mlx, WIDTH, HEIGHT);
	mlx_close_hook(info->mlx_s.mlx, &ft_exit_program, (void *)info);
	mlx_loop_hook(info->mlx_s.mlx, &ft_keyhook, (void *)info);
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
	init_mlx(new);
	return (new);
}
