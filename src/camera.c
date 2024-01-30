/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:55:10 by palucena          #+#    #+#             */
/*   Updated: 2024/01/30 16:20:50 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

set_camera_matrix(t_info *i, t_vector v1, t_vector v2, t_vector v3)
{
	i->cset->matrix[0][0] = v3.i;
	i->cset->matrix[1][0] = v3.j;
	i->cset->matrix[2][0] = v3.k;
	i->cset->matrix[3][0] = 0;
	i->cset->matrix[0][1] = v2.i;
	i->cset->matrix[1][1] = v2.j;
	i->cset->matrix[2][1] = v2.k;
	i->cset->matrix[3][1] = 0;
	i->cset->matrix[0][2] = v1.i;
	i->cset->matrix[1][2] = v1.j;
	i->cset->matrix[2][2] = v1.k;
	i->cset->matrix[3][2] = 0;
	i->cset->matrix[0][3] = i->cset->point.x;
	i->cset->matrix[1][3] = i->cset->point.y;
	i->cset->matrix[2][3] = i->cset->point.z;
	i->cset->matrix[3][3] = 1;
}

void	set_camera(t_info *i)
{
	t_vector	v_perp1;
	t_vector	v_perp2;

	i->cset->n_vec = v_norm(i->cset->n_vec);
	v_perp1 = v_norm(v_cross_product((t_vector){0, 0, 1}, i->cset->n_vec));
	v_perp2 = v_norm(v_cross_product(v_perp1, i->cset->n_vec));
	set_camera_matrix(i, i->cset->n_vec, v_perp1, v_perp2);
}
