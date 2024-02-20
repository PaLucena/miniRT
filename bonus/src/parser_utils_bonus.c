/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:30:04 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/20 14:42:01 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

char	*par_clean_id(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	j = 0;
	while (line[i + j] && !ft_isspace(line[i + j]))
		j++;
	str = ft_substr(line, i + j, ft_strlen(line) - i + j);
	free (line);
	return (str);
}

void	par_options(char *id, char *line, t_info *info)
{
	if (ft_strcmp(id, "A") == 0)
		par_save_amb(line, info);
	else if (ft_strcmp(id, "C") == 0)
		par_save_camera(line, info);
	else if (ft_strcmp(id, "L") == 0)
		par_save_light(line, info);
	else if (ft_strcmp(id, "sp") == 0)
		par_save_sphere(line, info);
	else if (ft_strcmp(id, "pl") == 0)
		par_save_plane(line, info);
	else if (ft_strcmp(id, "cy") == 0)
		par_save_cylinder(line, info);
	else if (ft_strcmp(id, "co") == 0)
		par_save_cone(line, info);
	else
	{
		free(id);
		free(line);
		ft_print_error("Identifier not found", info);
	}
}
