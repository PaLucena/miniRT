/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sphere_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:30:27 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/26 17:40:27 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	sp_save_pt(char *line, int start, t_properties *prop, t_info *info)
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

static int	sp_save_rad(char *line, int start, t_properties *prop, t_info *info)
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

int	sp_save_rgb(char *line, int start, t_properties *prop, t_info *info)
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
	if (ft_strcmp(str, "ch") == 0)
	{
		prop->checkerboard = true;
		prop->color = (t_color){0, 0, 0};
	}
	else
		ft_save_rgb(&prop->color, str, info);
	free(str);
	return (i + j);
}

void	par_save_sphere(char *line, t_info *info)
{
	int		i;
	t_shape	*new;

	new = shapes_newnode(SP, shapes_get_last_idx(info->shapes_list));
	if (info->shapes_list)
		shapes_addback(info->shapes_list, new);
	else
		info->shapes_list = new;
	i = sp_save_pt(line, 0, &new->prop, info);
	i = sp_save_rad(line, i, &new->prop, info);
	i = sp_save_rgb(line, i, &new->prop, info);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!sp_checkerboard_info(line, i, &new->prop))
		ft_print_error("Unknown Sphere info", info);
}
