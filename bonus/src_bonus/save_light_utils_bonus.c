/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_light_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:45:35 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/09 14:53:33 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/miniRT_bonus.h"

static t_lset	*lset_get_last_node(t_info *info)
{
	t_lset	*tmp;

	tmp = info->lset;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	lset_add_node(t_info *info, t_lset *new)
{
	t_lset	*tmp;

	tmp = lset_get_last_node(info);
	if (tmp == NULL)
		info->lset = new;
	else
		tmp->next = new;
}

t_lset	*lset_new_node(void)
{
	t_lset	*new;

	new = malloc(sizeof(t_lset));
	new->next = NULL;
	return (new);
}
