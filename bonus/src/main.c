/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:11:39 by palucena          #+#    #+#             */
/*   Updated: 2024/02/20 16:06:26 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

bool ayuda;

void	ft_print_error(char *str, t_info *info)
{
	ft_putstr_fd("Error:\n\t", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	if (info)
		free(info);
	exit(1);
}

void	ft_leaks(void)
{
	system("leaks -q miniRT_bonus");
}

void	ft_check_parsed(t_info *info)
{
	if (!info->cset)
		ft_print_error("Camera not declared", info);
	if (!info->lset)
		ft_print_error("Light not declared", info);
	if (!info->aset)
		ft_print_error("Ambient lightning not declared", info);
	if (!info->shapes_list)
		ft_print_error("You must provide at least 1 figure", info);
}

int	main(int ac, char **av)
{
	t_info	*info;

	atexit(ft_leaks);
	if (ac != 2)
		ft_print_error("Wrong number of arguments", NULL);
	info = init_info(av[1]);
	ft_parser(info);
	ft_check_parsed(info);
	init_mlx(info);
	put_pixels(info);
	mlx_loop(info->mlx_s.mlx);
	return (0);
}
