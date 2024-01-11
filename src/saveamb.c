/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveamb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:14:32 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/11 19:16:39 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static int	aset_save_ratio(char *line, int start, t_aset *new, t_info *info)
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
	if (ft_check_atod(str))
		new->ratio = ft_atod(str);
	else
		ft_print_error("Invalid Ambient Lightning ratio input", info);
	if (new->ratio < 0.0 && new->ratio > 1.0)
		ft_print_error("Ambient Lightning ratio out of range", info);
	printf("amb l ratio: %f\n", new->ratio);
	return (i + j);
}

static int	aset_save_rgb(char *line, int start, t_aset *new, t_info *info)
{
	int		i;
	int		j;
	char	*str;

	i = start;
	(void)new;
	(void)info;
	while (line[i] && ft_isspace(line[i]))
		i++;
	j = 0;
	while (line[i + j] && !ft_isspace(line[i + j]))
		j++;
	str = ft_substr(line, i, j);
	printf("valores rgb: %s\n", str);
	ft_save_rgb(&new->color, str, info);
	printf("R: %i, G: %i, B: %i\n", new->color.r, new->color.g, new->color.b);
	return (i + j);
}

void	par_save_amb(char *line, t_info *info)
{
	int		i;
	int		j;
	t_aset	*new;

	new = malloc(sizeof(t_aset));
	i = 0;
	if (info->aset != NULL)
		ft_print_error("Ambient Lightning redeclared", info);
	info->aset = new;
	while (line[i] && ft_isspace(line[i]))
		i++;
	j = 0;
	while (line[i + j] && ft_isspace(line[i + j]) == 0)
		j++;
	i += j;
	i += aset_save_ratio(line, i, new, info);
	i += aset_save_rgb(line, i, new, info);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i])
		ft_print_error("Invalid Ambient Lightning info", info);
}
