/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_list_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:38:18 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/12 16:42:56 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_shape	*shapes_newnode(t_type type)
{
	t_shape	*new;

	new = malloc(sizeof(t_shape));
	new->type = type;
	new->next = NULL;
	return (new);
}

void	shapes_addback(t_shape *root, t_shape *node)
{
	t_shape	*tmp;

	tmp = root;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}
