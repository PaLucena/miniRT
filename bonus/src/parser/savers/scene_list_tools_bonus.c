/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_list_tools_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:38:18 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/03/04 21:36:41 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_shape	*shapes_newnode(t_type type, int last_idx)
{
	t_shape	*new;

	new = malloc(sizeof(t_shape));
	new->type = type;
	new->next = NULL;
	new->index = last_idx + 1;
	new->prop.checkerboard = false;
	return (new);
}

int	shapes_get_last_idx(t_shape *root)
{
	t_shape	*tmp;

	tmp = root;
	if (!tmp)
		return (-1);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->index);
}

void	shapes_addback(t_shape *root, t_shape *node)
{
	t_shape	*tmp;

	tmp = root;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

bool	sp_checkerboard_info(char *line, int i, t_properties *prop)
{
	int		j;
	char	*str;

	j = 0;
	while (line[i + j] && ft_isspace(line[i + j]))
		j++;
	if (!line[i + j])
		return (true);
	i = j;
	j = 0;
	while (line[i + j] && !ft_isspace(line[i + j]))
		j++;
	str = ft_substr(line, i, j);
	if (ft_strcmp(str, "ch") == 0 && prop->checkerboard == false)
	{
		prop->checkerboard = true;
		return (free(str), true);
	}
	free(str);
	return (false);
}
