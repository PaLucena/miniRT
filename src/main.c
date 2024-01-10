/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:11:39 by palucena          #+#    #+#             */
/*   Updated: 2024/01/10 19:31:40 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	ft_print_error(char *str, t_info *info)
{
	ft_putstr_fd("Error:\n\t", 2);
	ft_putstr_fd(str, 2);
	if (info)
		free(info);
	exit(1);
}

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac != 2)
		ft_print_error("Wrong number of arguments", NULL);
	info = init_info(av[1]);
	//ft_parser(info);
	//mlx_loop(info->mlx_s.mlx);
	
	char *str = "42.123";
	if (ft_check_atod(str))
	{
		float n = ft_atod(str);
		printf("%f\n", n);
	}
	else
		printf("invalid\n");
	return (0);
}
