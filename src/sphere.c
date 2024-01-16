/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:13:17 by palucena          #+#    #+#             */
/*   Updated: 2024/01/16 19:47:50 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	quadratic_equation(double a, double b, double c)
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
	return (a2);
}

double	v_mod(t_vector v)
{
	return (sqrt((v.i * v.i) + (v.j * v.j) + (v.k * v.k)));
}

t_vector	v_get_from2(t_point from, t_point to)
{
	t_vector	new;

	new.i = to.x - from.x;
	new.i = to.y - from.y;
	new.i = to.z - from.z;
	return (new);
}

t_inter	*inter_sp(t_info *in, t_shape *sp, double i, double j)
{
	t_inter		*inter;
	t_point		p;
	t_point		abc;

	inter = malloc(sizeof(t_inter));
	inter->index = sp->index;
	p.x = in->pl->l + i;
	p.y = in->pl->t - j;
	p.z = (WIDTH / 2) / sin((in->cset->fov / 2) * (M_PI / 180)) + in->cset->point.z;
	if (in->cset->n_vec.k < 0)
		p.z = ((WIDTH / 2) / sin((in->cset->fov / 2) * (M_PI / 180))) * (-1) + in->cset->point.z;
	if (i == WIDTH / 2 && j == HEIGHT / 2)
		printf("Coordenadas del pixel central: %f %f %f\n", p.x, p.y, p.z);
	abc.x = pow(v_mod(in->cset->n_vec), 2);
	abc.y = 2 * (v_mod(in->cset->n_vec) * (v_mod(v_get_from2(sp->prop.c, p))));
	abc.z = pow(v_mod(v_get_from2(sp->prop.c, p)), 2) - pow(sp->prop.rad, 2);
/* 	abc.x = pow((in->cset->point.x - sp->prop.c.x), 2) + pow((in->cset->point.y - sp->prop.c.y), 2) + pow((in->cset->point.z - sp->prop.c.z), 2);
	abc.z = pow((in->cset->point.x - p.x), 2) + pow((in->cset->point.y - p.y), 2) + pow((in->cset->point.z - p.z), 2) - (sp->prop.rad * sp->prop.rad);
	abc.y = pow((sp->prop.c.x - p.x), 2) + pow((sp->prop.c.y - p.y), 2) + pow((sp->prop.c.z - p.z), 2) - abc.z - abc.x - (sp->prop.rad * sp->prop.rad); */
	inter->d = quadratic_equation(abc.x, abc.y, abc.z);
	if (i == WIDTH / 2 && j == HEIGHT / 2)
		printf("Discriminante: %f\n", abc.y * abc.y - 4 * abc.x * abc.z);
	if (i == WIDTH / 2 && j == HEIGHT / 2)
	{
		printf("Distancia a colision en el centro del plano: %f\n", inter->d);
	}
		printf("ABC: %f  %f  %f\n", abc.x, abc.y, abc.z);
	if (inter->d == -1)
	{
		free (inter);
		return (NULL);
	}
	inter->d *= sqrt(pow((p.x - sp->prop.c.x), 2) + pow((p.y - sp->prop.c.y), 2) + pow((p.z - sp->prop.c.z), 2));
	inter->q.x = in->cset->point.x + inter->d * in->cset->n_vec.i;
	inter->q.y = in->cset->point.y + inter->d * in->cset->n_vec.j;
	inter->q.z = in->cset->point.z + inter->d * in->cset->n_vec.k;
	return (inter);
}
