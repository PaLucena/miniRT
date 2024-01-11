/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:27:52 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/11 19:52:24 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static int	cset_save_point(char *line, int start, t_cset *new, t_info *info)
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

static int	cset_save_vector(char *line, int start, t_cset *new, t_info *info)
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
	(void)new;
	(void)info;
	//TODO: añadir vectores
	free(str);
	return (i + j);
}

static int	cset_save_fov(char *line, int start, t_cset *new, t_info *info)
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
	new->fov = ft_atoi(str);
	free(str);
	if (new->fov < 0 || new->fov > 180)
		ft_print_error("Camera fov outside parameters", info);
	return (i + j);
}

void	par_save_camera(char *line, t_info *info)
{
	int		i;
	int		j;
	t_cset	*new;

	new = malloc(sizeof(t_cset));
	i = 0;
	if (info->cset != NULL)
		ft_print_error("Camera redeclared", info);
	info->cset = new;
	while (line[i] && ft_isspace(line[i]))
		i++;
	j = 0;
	while (line[i + j] && ft_isspace(line[i + j]) == 0)
		j++;
	i += j;
	i += cset_save_point(line, i, new, info);
	i += cset_save_vector(line, i, new, info);
	i += cset_save_fov(line, i, new, info);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i])
		ft_print_error("Invalid Camera info", info);

}
