/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:17:59 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/15 15:24:17 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_mlx(t_info	*info)
{
	info->mlx_s.mlx = mlx_init(WIDTH_INT, HEIGHT_INT, "miniRT", false);
	info->mlx_s.win = mlx_new_image(info->mlx_s.mlx, WIDTH_INT, HEIGHT_INT);
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
