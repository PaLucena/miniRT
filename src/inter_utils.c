/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:47:34 by palucena          #+#    #+#             */
/*   Updated: 2024/01/15 17:36:24 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	*normalize_vector(t_vector *v)
{
	t_vector	*v_norm;
	
	v_norm = malloc(sizeof(t_vector));
	v_norm->i = v->i / sqrt((v->i * v->i) + (v->j * v->j) + (v->k * v->k));
	v_norm->j = v->j / sqrt((v->i * v->i) + (v->j * v->j) + (v->k * v->k));
	v_norm->k = v->k / sqrt((v->i * v->i) + (v->j * v->j) + (v->k * v->k));
	return (v_norm);
}

void	image_plane_coords(t_info *i)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	*v1_n;
	t_vector	*v2_n;
	double		fov_adj;

	v1.i = 0;
	v1.j = i->cset->n_vec.k;
	v1.k = i->cset->n_vec.j * -1;
	v1_n = normalize_vector(&v1);
	v2.i = i->cset->n_vec.j * (-i->cset->n_vec.j) - pow(i->cset->n_vec.k, 2);
	v2.j = (-i->cset->n_vec.i) * (-i->cset->n_vec.j);
	v2.k = i->cset->n_vec.i * i->cset->n_vec.k;
	v2_n = normalize_vector(&v2);
	fov_adj = (WIDTH / 2) / (i->cset->fov / 2); // Magnitud (distancia) del vector normal cámara-plano imagen
	i->pl->l = i->cset->point.x - fov_adj * v1_n->i + (HEIGHT / 2) * v2_n->i;
	i->pl->r = i->cset->point.x + fov_adj * v1_n->i + (HEIGHT / 2) * v2_n->i;
	i->pl->t = i->cset->point.y + fov_adj * v1_n->j + (HEIGHT / 2) * v2_n->j;
	i->pl->b = i->cset->point.y + fov_adj * v1_n->j - (HEIGHT / 2) * v2_n->j;
	free(v1_n);
	free(v2_n);
}

t_vector	*ray_direction(t_info *in, double i, double j)
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
}
