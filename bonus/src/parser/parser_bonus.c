/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:04:44 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/20 15:27:46 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

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
	line = par_clean_id(line);
	par_options(id, line, info);
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
	int		fd;
	char	*ext;

	fd = open(info->filename, O_RDONLY);
	ext = ft_substr(info->filename, ft_strlen(info->filename) - 3, 3);
	if (ft_strcmp(ext, ".rt") != 0)
	{
		free(ext);
		ft_print_error("invalid file extension", info);
	}
	free(ext);
	if (fd < 0)
		ft_print_error("file not found", info);
	par_extract_file(info, fd);
}
