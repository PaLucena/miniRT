/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_extras.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:59:04 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/15 12:50:44 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	col_save(char *str, int *mem, t_info *info)
{
	int	n;

	n = ft_atoi(str);
	free(str);
	if (n < 0 || n > 255)
		ft_print_error("Invalid RGB value", info);
	*mem = n;
}

void	ft_save_rgb(t_color *color, char *str, t_info *info)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (str[i] && ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] && str[i] != ',')
		ft_print_error("Wrong RGB set", info);
	col_save(ft_substr(str, 0, i), &color->r, info);
	i++;
	j = 0;
	while (str[i + j] && ft_isdigit(str[i + j]) == 1)
		j++;
	if (str[i + j] && str[i + j] != ',')
		ft_print_error("Wrong RGB set", info);
	col_save(ft_substr(str, i, j), &color->g, info);
	j++;
	k = 0;
	while (str[i + j + k] && ft_isdigit(str[i + j + k]) == 1)
		k++;
	if (str[i + j + k] && str[i + j + k] != ',')
		ft_print_error("Wrong RGB set", info);
	col_save(ft_substr(str, i + j, k), &color->b, info);
}

static void	pt_save(char *str, double *mem, t_info *info)
{
	if (ft_check_atod(str))
		*mem = ft_atod(str);
	else
	{
		free(str);
		ft_print_error("Wrong values", info);
	}
	free(str);
}

static bool	pt_charcheck(char c)
{
	if (ft_isdigit(c) == 1 || c == '-' || c == '.')
		return (true);
	return (false);
}

void	ft_save_point(t_point *point, char *str, t_info *info)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (str[i] && pt_charcheck(str[i]))
		i++;
	if (str[i] && str[i] != ',')
		ft_print_error("Wrong Camera coordinates", info);
	pt_save(ft_substr(str, 0, i), &point->x, info);
	i++;
	j = 0;
	while (str[i + j] && pt_charcheck(str[i + j]))
		j++;
	if (str[i + j] && str[i + j] != ',')
		ft_print_error("Wrong Camera coordinates", info);
	pt_save(ft_substr(str, i, j), &point->y, info);
	j++;
	k = 0;
	while (str[i + j + k] && pt_charcheck(str[i + j + k]))
		k++;
	if (str[i + j + k] && str[i + j + k] != ',')
		ft_print_error("Wrong Camera coordinates", info);
	pt_save(ft_substr(str, i + j, k), &point->z, info);
}
