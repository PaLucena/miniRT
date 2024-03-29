/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_extras2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:08:53 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/22 13:18:52 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	vec_check_unitary(t_vector *vec, t_info *info)
{
	if (round(v_mod(*vec)) != 1.0)
		ft_print_error("Non unitary vector", info);
}

static void	vec_save(char *str, double *mem, t_info *info)
{
	if (ft_check_atod(str))
	{
		*mem = ft_atod(str);
		if (ft_atod(str) < -1.0 || ft_atod(str) > 1.0)
		{
			free(str);
			ft_print_error("Wrong values", info);
		}
		free (str);
	}
	else
	{
		free(str);
		ft_print_error("Wrong values", info);
	}
}

static bool	vec_charcheck(char c)
{
	if (ft_isdigit(c) == 1 || c == '-' || c == '.')
		return (true);
	return (false);
}

void	ft_save_vector(t_vector *vector, char *str, t_info *info)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (str[i] && vec_charcheck(str[i]))
		i++;
	if (str[i] && str[i] != ',')
		ft_print_error("Wrong vector input", info);
	vec_save(ft_substr(str, 0, i), &vector->i, info);
	i++;
	j = 0;
	while (str[i + j] && vec_charcheck(str[i + j]))
		j++;
	if (str[i + j] && str[i + j] != ',')
		ft_print_error("Wrong vector input", info);
	vec_save(ft_substr(str, i, j), &vector->j, info);
	j++;
	k = 0;
	while (str[i + j + k] && vec_charcheck(str[i + j + k]))
		k++;
	if (str[i + j + k] && str[i + j + k] != ',')
		ft_print_error("Wrong vector input", info);
	vec_save(ft_substr(str, i + j, k), &vector->k, info);
	vec_check_unitary(vector, info);
}

int	cy_co_save_hei(char *line, int start, t_properties *prop, t_info *info)
{
	int		i;
	int		j;
	char	*str;

	i = start;
	while (line[i] && ft_isspace(line[i]))
		i++;
	j = 0;
	while (line[i + j] && !ft_isspace(line[i + j]))
		j++;
	str = ft_substr(line, i, j);
	if (!ft_check_atod(str))
	{
		free(str);
		ft_print_error("Value not valid", info);
	}
	prop->height = ft_atod(str);
	free(str);
	return (i + j);
}
