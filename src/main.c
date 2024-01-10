/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:11:39 by palucena          #+#    #+#             */
/*   Updated: 2024/01/10 15:02:43 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	main(void)
{
	t_info	*info;

	info = init_info();
	info->aset.color.r = 45;
	mlx_loop(info->mlx_s.mlx);
	return (0);
}
