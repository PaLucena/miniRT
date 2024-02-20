/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:17:24 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/20 14:42:01 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

t_shape	*cy_circle_to_plane(t_circle *c)
{
	t_shape	*shp;

	shp = malloc(sizeof(t_shape));
	shp->index = c->shape_id;
	shp->next = NULL;
	shp->prop.c = c->p;
	shp->prop.n_vec = c->v;
	return (shp);
}

static t_inter	*cy_valid_coll(t_circle *top, t_circle *bot)
{
	bool	top_valid;
	bool	bot_valid;

	top_valid = false;
	bot_valid = false;
	if (top->coll && (v_mod(v_get_from2(top->p,
					top->coll->q)) <= top->diam / 2))
		top_valid = true;
	if (bot->coll && (v_mod(v_get_from2(bot->p,
					bot->coll->q)) <= bot->diam / 2.0))
		bot_valid = true;
	if (top_valid && bot_valid)
	{
		if (top->coll->d < bot->coll->d)
			return (free(bot->coll), top->coll);
		return (free(top->coll), bot->coll);
	}
	if (top_valid)
		return (free(bot->coll), top->coll);
	else if (bot_valid)
		return (free(top->coll), bot->coll);
	return (free(bot->coll), free(top->coll), NULL);
}

t_inter	*cy_cap_coll(t_circle *top, t_circle *bot, t_vector ray, t_point orig)
{
	top->plane = cy_circle_to_plane(top);
	bot->plane = cy_circle_to_plane(bot);
	top->coll = inter_pl(top->plane, ray, orig);
	bot->coll = inter_pl(bot->plane, ray, orig);
	return (free(top->plane), free(bot->plane), cy_valid_coll(top, bot));
}
