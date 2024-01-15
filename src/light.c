/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:17:47 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/13 19:43:09 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_color	ph_iamb(t_info *info, int sh_idx)
{
	t_shape	*shape;
	t_color	amb_color;

	shape = info->shapes_list;
	while (shape->index != sh_idx)
		shape = shape->index;
	amb_color.r = info->aset->color.r * info->aset->ratio;
	amb_color.g = info->aset->color.g * info->aset->ratio;
	amb_color.b = info->aset->color.b * info->aset->ratio;
	return ()
}

t_color	ft_phong(t_inter *inter, t_info *info)
{
	t_color	ph_col;

	
}
