/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:11:39 by palucena          #+#    #+#             */
/*   Updated: 2024/01/08 20:11:19 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	main(int ac, char **av)
{
	mlx_t		*mlx;
	mlx_image_t	*win;

	(void)ac;
	(void)av;
	mlx = mlx_init(64, 64, "fract-ol", false);
	if (!mlx)
		exit(EXIT_FAILURE);
	win = mlx_new_image(mlx, 64, 64);
	if (!win)
		exit(EXIT_FAILURE);
	return (0);
}
