/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:55:10 by palucena          #+#    #+#             */
/*   Updated: 2024/02/20 14:42:01 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

void	set_camera_matrix(t_cset *camera, t_vector v1, t_vector v2, t_vector v3)
{
	camera->m.m[0][0] = v3.i;
	camera->m.m[1][0] = v3.j;
	camera->m.m[2][0] = v3.k;
	camera->m.m[3][0] = 0;
	camera->m.m[0][1] = v2.i;
	camera->m.m[1][1] = v2.j;
	camera->m.m[2][1] = v2.k;
	camera->m.m[3][1] = 0;
	camera->m.m[0][2] = v1.i;
	camera->m.m[1][2] = v1.j;
	camera->m.m[2][2] = v1.k;
	camera->m.m[3][2] = 0;
	camera->m.m[0][3] = camera->point.x;
	camera->m.m[1][3] = camera->point.y;
	camera->m.m[2][3] = camera->point.z;
	camera->m.m[3][3] = 1;
}

void	set_camera(t_cset *c)
{
	t_vector	v_perp1;
	t_vector	v_perp2;

	c->n_vec = v_norm(c->n_vec);
	if (c->n_vec.k == 1 || c->n_vec.k == -1)
		v_perp1 = v_cross_product((t_vector){-c->n_vec.k, 0, 1}, c->n_vec);
	else
		v_perp1 = v_cross_product((t_vector){0, 0, 1}, c->n_vec);
	v_perp1 = v_norm(v_perp1);
	v_perp2 = v_norm(v_cross_product(v_perp1, c->n_vec));
	set_camera_matrix(c, c->n_vec, v_perp1, v_perp2);
}

t_vector	camera_ray_direction(t_info *in, t_pixel px)
{
	t_vector	dir;

	dir = p_to_v(plane_point_coords(in, px.i, px.j));
	dir = v_matrix_product(dir, in->cset->m);
	dir = v_norm(v_get_from2(in->cset->point, v_to_p(dir)));
	return (dir);
}
