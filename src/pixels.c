/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:46:05 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/12 17:55:52 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	put_pixels(t_info *info)
{
	double	x;
	double	y;
	t_inter	*inter_tmp;

	x = 0.0;
	y = 0.0;
	while (x <= WIDTH)
	{
		while (y <= HEIGHT)
		{
			inter_tmp = get_closest_collision(x, y, info);
			if (inter_tmp)
			{
				px_put_coll();
			}
			else
				px_put_black();
			y++;
		}
		x++;
	}
}
