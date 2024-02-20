/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_list_tools_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:38:18 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/20 14:42:01 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

t_shape	*shapes_newnode(t_type type, int last_idx)
{
	t_shape	*new;

	new = malloc(sizeof(t_shape));
	new->type = type;
	new->next = NULL;
	new->index = last_idx + 1;
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
