/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cone_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:12:49 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/22 13:18:31 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	co_save_pt(char *line, int start, t_properties *prop, t_info *info)
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
	ft_save_point(&prop->c, str, info);
	free(str);
	return (i + j);
}

static int	co_save_vec(char *line, int start, t_properties *prop, t_info *info)
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
	ft_save_vector(&prop->n_vec, str, info);
	free(str);
	return (i + j);
}

static int	co_save_rgb(char *line, int start, t_properties *prop, t_info *info)
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
	ft_save_rgb(&prop->color, str, info);
	free(str);
	return (i + j);
}

static int	co_save_rad(char *line, int start, t_properties *prop, t_info *info)
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
	prop->rad = (ft_atod(str) / 2.0);
	free(str);
	return (i + j);
}

void	par_save_cone(char *line, t_info *info)
{
	int		i;
	t_shape	*new;

	new = shapes_newnode(CO, shapes_get_last_idx(info->shapes_list));
	if (info->shapes_list)
		shapes_addback(info->shapes_list, new);
	else
		info->shapes_list = new;
	i = co_save_pt(line, 0, &new->prop, info);
	i = co_save_vec(line, i, &new->prop, info);
	i = co_save_rad(line, i, &new->prop, info);
	i = cy_co_save_hei(line, i, &new->prop, info);
	i = co_save_rgb(line, i, &new->prop, info);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i])
		ft_print_error("Unknown Cone info", info);
}
