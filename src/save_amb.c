/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_amb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:14:32 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/12 16:42:56 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	aset_save_ratio(char *line, int start, t_aset *new, t_info *info)
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
	if (ft_check_atod(str))
		new->ratio = ft_atod(str);
	else
	{
		free(str);
		ft_print_error("Invalid Ambient Lightning ratio input", info);
	}
	free(str);
	if (new->ratio < 0.0 && new->ratio > 1.0)
		ft_print_error("Ambient Lightning ratio out of range", info);
	return (i + j);
}

static int	aset_save_rgb(char *line, int start, t_aset *new, t_info *info)
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
	ft_save_rgb(&new->color, str, info);
	return (i + j);
}

void	par_save_amb(char *line, t_info *info)
{
	int		i;
	t_aset	*new;

	new = malloc(sizeof(t_aset));
	if (info->aset != NULL)
		ft_print_error("Ambient Lightning redeclared", info);
	info->aset = new;
	i = aset_save_ratio(line, 0, new, info);
	i = aset_save_rgb(line, i, new, info);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] && line[i] != '\n')
		ft_print_error("Unknown ALight info", info);
}
