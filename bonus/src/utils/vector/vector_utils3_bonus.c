/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:54:47 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/26 17:14:03 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_vector	v_opposite_vec(t_vector orig)
{
	t_vector	new;

	new.i = orig.i * (-1);
	new.j = orig.j * (-1);
	new.k = orig.k * (-1);
	return (new);
}

t_point	v_get_endpoint(t_vector vector, double d, t_point orig)
{
	t_point	endp;

	endp.x = orig.x + vector.i * d;
	endp.y = orig.y + vector.j * d;
	endp.z = orig.z + vector.k * d;
	return (endp);
}

double	v_magnitude(t_vector v)
{
	return (sqrt(pow(v.i, 2) + pow(v.j, 2) + pow(v.k, 2)));
}
