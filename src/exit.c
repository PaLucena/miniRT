/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:24:50 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/09 13:03:29 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

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
	exit(EXIT_SUCCESS);
}
