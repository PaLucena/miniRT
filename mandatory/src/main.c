/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaladin <kaladin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:11:39 by palucena          #+#    #+#             */
/*   Updated: 2025/04/30 17:10:01 by kaladin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_print_error(char *str, t_info *info)
{
	ft_putstr_fd("Error:\n\t", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	if (info != NULL)
		ft_exit_program((void *)info);
	exit (1);
}

void	ft_leaks(void)
{
	system("leaks -q miniRT");
	atexit(ft_leaks);
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

	if (ac != 2)
		ft_print_error("Wrong number of arguments", NULL);
	info = init_info(av[1]);
	init_mlx(info);
	ft_parser(info);
	ft_check_parsed(info);
	put_pixels(info);
	mlx_loop(info->mlx_s.mlx);
	atexit(ft_leaks);
	return (0);
}
