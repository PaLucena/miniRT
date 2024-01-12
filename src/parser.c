/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:04:44 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/12 18:04:21 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static char	*par_get_ident(char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	j = 0;
	while (line[i + j] && !ft_isspace(line[i + j]))
		j++;
	return (ft_substr(line, i, j));
}

static char	*par_clean_id(char *line)
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

static void	par_save_line(char *line, t_info *info)
{
	char	*id;

	id = par_get_ident(line);
	line = par_clean_id(line);
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
	else
	{
		free(id);
		free(line);
		ft_print_error("Identifier not found", info);
	}
	free(id);
	free(line);
}

static bool	par_useful_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (true);
		i++;
	}
	return (false);
}

static void	par_extract_file(t_info *info, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (par_useful_line(line))
			par_save_line(line, info);
		else
			free(line);
		line = get_next_line(fd);
	}
}

void	ft_parser(t_info *info)
{
	int	fd;

	fd = open(info->filename, O_RDONLY);
	// TODO: check extension
	if (fd < 0)
		ft_print_error("file not found", info);
	par_extract_file(info, fd);
}
