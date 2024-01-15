/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:13:17 by palucena          #+#    #+#             */
/*   Updated: 2024/01/15 20:27:12 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	quadratic_equation(int a, int b, int c)
{
	double		dis;
	double		a1;
	double		a2;

	dis = (b * b) - 4 * a * c;
	if (dis < 0)
		return (-1);
	a1 = ((b * -1) + sqrt(dis)) / (2 * a);
	a2 = ((b * -1) - sqrt(dis)) / (2 * a);
	if (a1 > 0 && a1 < a2)
		return (a1);
	//if (a2 > 0 && a2 < a1)
		return (a2);
}

t_inter	*inter_sp(t_info *in, t_shape *sp, double i, double j)
{
	t_inter		*inter;
	t_point		p;
	t_point		abc;
	//double		t;

	inter = malloc(sizeof(t_inter));
	inter->index = sp->index;
	p.x = in->pl->l + (in->pl->r - in->pl->l) * (i + 0.5) / WIDTH;
	p.y = in->pl->b + (in->pl->t - in->pl->b) * (j + 0.5) / HEIGHT;
	p.z = in->cset->point.z + (WIDTH / 2) / (in->cset->fov / 2);
	abc.x = pow((in->cset->point.x - sp->prop.c.x), 2) + pow((in->cset->point.y - sp->prop.c.y), 2) + pow((in->cset->point.z - sp->prop.c.z), 2);
	abc.z = pow((p.x - sp->prop.c.x), 2) + pow((p.y - sp->prop.c.y), 2) + pow((p.z - sp->prop.c.z), 2) - (sp->prop.rad * sp->prop.rad);
	abc.y = pow((in->cset->point.x - p.x), 2) + pow((in->cset->point.y - p.y), 2) + pow((in->cset->point.z - p.z), 2) - abc.z - abc.x - (sp->prop.rad * sp->prop.rad);
	inter->d = quadratic_equation(abc.x, abc.y, abc.z);
	if (inter->d == -1)
		return (NULL);
	printf("HELLO %f\n", inter->d);
	inter->d *= sqrt(pow((p.x - sp->prop.c.x), 2) + pow((p.y - sp->prop.c.y), 2) + pow((p.z - sp->prop.c.z), 2));
	inter->q.x = in->cset->point.x + inter->d * in->cset->n_vec.i;
	inter->q.y = in->cset->point.y + inter->d * in->cset->n_vec.j;
	inter->q.z = in->cset->point.z + inter->d * in->cset->n_vec.k;
	return (inter);
}
