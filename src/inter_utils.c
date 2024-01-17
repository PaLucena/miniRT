/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:47:34 by palucena          #+#    #+#             */
/*   Updated: 2024/01/17 12:22:07 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	v_norm(t_vector v)
{
	t_vector	v_norm;
	double		tmp;

	v_norm.i = 0;
	v_norm.j = 0;
	v_norm.k = 0;
	tmp = sqrt((v.i * v.i) + (v.j * v.j) + (v.k * v.k));
	if (tmp != 0)
	{
		v_norm.i = v.i / tmp;
		v_norm.j = v.j / tmp;
		v_norm.k = v.k / tmp;
	}
	return (v_norm);
}

void	image_plane_coords(t_info *i)
{
	i->pl->l = i->cset->point.x - WIDTH / 2;
	i->pl->r = i->cset->point.x + WIDTH / 2;
	i->pl->t = i->cset->point.y + HEIGHT / 2;
	i->pl->b = i->cset->point.y - HEIGHT / 2;
}

/* t_vector	*ray_direction(t_info *in, double i, double j)
{
	t_vector	cp;
	t_point		p;

	p.x = in->pl->l + (in->pl->r - in->pl->l) * (i + 0.5) / WIDTH;
	p.y = in->pl->b + (in->pl->t - in->pl->b) * (j + 0.5) / HEIGHT;
	p.z = in->cset->point.z + (WIDTH / 2) / (in->cset->fov / 2);
	cp.i = p.x - in->cset->point.x;
	cp.j = p.y - in->cset->point.y;
	cp.k = p.z - in->cset->point.z;
	return (normalize_vector(&cp));
} */
