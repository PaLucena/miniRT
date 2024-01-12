/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:43:10 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/12 14:01:31 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static int	lset_save_point(char *line, int start, t_lset *new, t_info *info)
{
	int		i;
	int		j;
	char	*str;

	i = start;
	while (line[i] && ft_isspace(line[i]))
		i++;
	j = 0;
	printf("\n");
	while (line[i + j] && !ft_isspace(line[i + j]))
		j++;
	str = ft_substr(line, i, j);
	ft_save_point(&new->point, str, info);
	free(str);
	return (i + j);
}

static int	lset_save_rgb(char *line, int start, t_lset *new, t_info *info)
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

static int	lset_save_ratio(char *line, int start, t_lset *new, t_info *info)
{
	int		i;
	int		j;
	char	*str;

	i = start;
	while (line[i] && ft_isspace(line[i]))
		i++;
	j = 0;
	printf("\n");
	while (line[i + j] && !ft_isspace(line[i + j]))
		j++;
	str = ft_substr(line, i, j);
	if (!ft_check_atod(str))
	{
		free(str);
		ft_print_error("", info);
	}
	new->brightness = ft_atod(str);
	free(str);
	if (new->brightness < 0.0 || new->brightness > 1.0)
		ft_print_error("Light brightness outside parameters", info);
	return (i + j);
}

void	par_save_light(char *line, t_info *info)
{
	int		i;
	t_lset	*new;

	new = malloc(sizeof(t_lset));
	if (info->lset != NULL)
		ft_print_error("Light info redeclared", info);
	info->lset = new;
	i = lset_save_point(line, 0, new, info);
	i = lset_save_ratio(line, i, new, info);
	i = lset_save_rgb(line, i, new, info);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i])
		ft_print_error("Unknown Light info", info);
}
