/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:24:50 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/21 14:30:40 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	free_shapes(t_shape *root)
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

static void	free_lights(t_lset *root)
{
	t_lset	*tmp;
	t_lset	*next;

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
	free_lights(info->lset);
	free(info->cset);
	free_shapes(info->shapes_list);
	mlx_terminate(info->mlx_s.mlx);
	free(info);
	printf("a little to the outside\n");
	exit(EXIT_SUCCESS);
}
