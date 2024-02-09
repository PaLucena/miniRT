/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:24:50 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/09 14:04:50 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/miniRT_bonus.h"

void	free_shapes(t_shape *root)
{
	t_shape	*tmp;
	t_shape	*next;

	tmp = root;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void	ft_exit_program(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	free(info->filename);
	free(info->aset);
	free(info->lset);
	free(info->cset);
	free_shapes(info->shapes_list);
	mlx_terminate(info->mlx_s.mlx);
	free(info);
	printf("a little to the outside\n");
	exit(EXIT_SUCCESS);
}
