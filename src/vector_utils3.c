/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:54:47 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/04 19:58:22 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	v_opposite_vec(t_vector orig)
{
	t_vector	new;

	new.i = orig.i * (-1);
	new.j = orig.j * (-1);
	new.k = orig.k * (-1);
	return (new);
}
