/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:04:44 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/11 19:56:58 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

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

static void	par_save_line(char *line, t_info *info)
{
	char	*id;

	id = par_get_ident(line);
	printf("line: %s\n id: %s", line, id);
	if (ft_strcmp(id, "A") == 0)
		par_save_amb(line, info);
 	else if (ft_strcmp(id, "C") == 0)
		par_save_camera(line, info);
/*	else if (ft_strcmp(id, "L"))
		par_save_light();
	else if (ft_strcmp(id, "sp"))
		par_save_sphere();
	else if (ft_strcmp(id, "pl"))
		par_save_plane();
	else if (ft_strcmp(id, "cy"))
		par_save_cylinder(); */
	else
	{
		free(id);
		ft_print_error("Identifier not found", info);
	}
	free(id);
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
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	ft_parser(t_info *info)
{
	int	fd;

	fd = open(info->filename, O_RDONLY);
	if (fd < 0)
		ft_print_error("file not found", info);
	par_extract_file(info, fd);
}
