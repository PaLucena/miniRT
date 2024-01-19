/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:17:59 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/19 11:22:13 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_mlx(t_info	*info)
{
	info->mlx_s.mlx = mlx_init((int)WIDTH, (int)HEIGHT, "miniRT", true);
	info->mlx_s.win = mlx_new_image(info->mlx_s.mlx, (int)WIDTH, (int)HEIGHT);
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
	new->pl = malloc(sizeof(t_iplane));
	return (new);
}
