/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:17:59 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/12 16:41:02 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_info	*init_info(char *filename)
{
	t_info	*new;

	new = malloc(sizeof(t_info));
	new->filename = ft_strdup(filename);
	new->mlx_s.mlx = mlx_init(255, 255, "miniRT", false);
	//new->mlx_s.win = mlx_new_image(new->mlx_s.mlx, 255, 255);
	new->aset = NULL;
	new->lset = NULL;
	new->cset = NULL;
	new->shapes_list = NULL;
	return (new);
}
