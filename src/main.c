/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:11:39 by palucena          #+#    #+#             */
/*   Updated: 2024/01/19 11:53:06 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* void	ft_print_shapes(t_shape *root)
{
	t_shape	*tmp;

	tmp = root;
	while (tmp)
	{
		printf("INDEX: %i:", tmp->index);
		if (tmp->type == CY)
		{
			printf("CYLINDER:\n");
			printf("\tpoint:\n\t\tX: %f\n\t\tY: %f\n\t\tZ: %f\n",
				tmp->prop.c.x, tmp->prop.c.y, tmp->prop.c.z);
			printf("\theight: %f\n\tdiam: %f\n",
				tmp->prop.height, tmp->prop.rad * 2.0);
			printf("\tcolor:\n\t\tR: %i\n\t\tG: %i\n\t\tB: %i\n",
				tmp->prop.color.r, tmp->prop.color.g, tmp->prop.color.b);
			printf("\tvector:\n\t\tI: %f\n\t\tJ: %f\n\t\tK: %f\n",
				tmp->prop.n_vec.i, tmp->prop.n_vec.j,
				tmp->prop.n_vec.k);
		}
		else if (tmp->type == SP)
		{
			printf("SPHERE:\n");
			printf("\tpoint:\n\t\tX: %f\n\t\tY: %f\n\t\tZ: %f\n",
				tmp->prop.c.x, tmp->prop.c.y, tmp->prop.c.z);
			printf("\tdiam: %f\n", tmp->prop.rad * 2.0);
			printf("\tcolor:\n\t\tR: %i\n\t\tG: %i\n\t\tB: %i\n",
				tmp->prop.color.r, tmp->prop.color.g, tmp->prop.color.b);
		}
		else if (tmp->type == PL)
		{
			printf("PLANE:\n");
			printf("\tpoint:\n\t\tX: %f\n\t\tY: %f\n\t\tZ: %f\n",
				tmp->prop.c.x, tmp->prop.c.y, tmp->prop.c.z);
			printf("\tcolor:\n\t\tR: %i\n\t\tG: %i\n\t\tB: %i\n",
				tmp->prop.color.r, tmp->prop.color.g, tmp->prop.color.b);
			printf("\tvector:\n\t\tI: %f\n\t\tJ: %f\n\t\tK: %f\n",
				tmp->prop.n_vec.i, tmp->prop.n_vec.j,
				tmp->prop.n_vec.k);
		}
		tmp = tmp->next;
	}
}

void	ft_printparser(t_info *info)
{
	printf("ASET: \n\tratio: %f\n\tcolor:\n\t\tR: %i\n\t\tG: %i\n\t\tB: %i\n",
		info->aset->ratio, info->aset->color.r, info->aset->color.g,
		info->aset->color.b);
	printf("CSET: \n\tpoint:\n\t\tX: %f\n\t\tY: %f\n\t\tZ: %f\n\tFOV:
	 %i\n\tvector:\n\t\tI: %f\n\t\tJ: %f\n\t\tK: %f\n",
		info->cset->point.x, info->cset->point.y, info->cset->point.z,
		info->cset->fov, info->cset->n_vec.i,
		info->cset->n_vec.j, info->cset->n_vec.k);
	printf("LSET: \n\tpoint:\n\t\tX: %f\n\t\tY: 
	%f\n\t\tZ: %f\n\tcolor:\n\t\tR: %i\n\t\tG: %i\n\t\tB:
	 %i\n\tbrightness: %f\n",
		info->lset->point.x, info->lset->point.y, info->lset->point.z,
		info->lset->color.r, info->lset->color.g,
		info->lset->color.b, info->lset->brightness);
	ft_print_shapes(info->shapes_list);
} */

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
	system("leaks -q miniRT");
}

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac != 2)
		ft_print_error("Wrong number of arguments", NULL);
	info = init_info(av[1]);
	ft_parser(info);
	printf("parsed\n\n");
	init_mlx(info);
	put_pixels(info);
	mlx_loop(info->mlx_s.mlx);
	return (0);
}
