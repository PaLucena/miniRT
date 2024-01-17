/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:13:17 by palucena          #+#    #+#             */
/*   Updated: 2024/01/17 17:19:38 by palucena         ###   ########.fr       */
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
	if (a1 >= 0 && a2 >= 0 && a1 < a2)
		return (a1);
//	printf("t1 -> %f  t2 -> %f            abc: %f %f %f\n", a1, a2, a, b, c);
	return (a2);
}

t_vector	v_unitary(t_vector a)
{
	t_vector	new;
	double		mod;

	mod = sqrt((pow(a.i, 2)) + (pow(a.j, 2)) + (pow(a.k, 2)));
	new.i = a.i / mod;
	new.j = a.j / mod;
	new.k = a.k / mod;
	return (new);
}

double	v_mod(t_vector v)
{
	return (sqrt((v.i * v.i) + (v.j * v.j) + (v.k * v.k)));
}

t_vector	v_get_from2(t_point from, t_point to)
{
	t_vector	new;

	new.i = to.x - from.x;
	new.j = to.y - from.y;
	new.k = to.z - from.z;
//	if (from.z == 0)
//		printf("%f  %f  %f\n", new.i, new.j, new.k);
	return (new);
}

t_vector	v_mult(t_vector a, t_vector b)
{
	t_vector	new;

	new.i = a.i * b.i;
	new.j = a.j * b.j;
	new.k = a.k * b.k;
	return (new);
}

t_inter	*inter_sp(t_info *in, t_shape *sp, double i, double j)
{
	t_inter		*inter;
	t_vector	d;
	t_vector	cc;
	t_point		p;
	t_point		abc;

	inter = malloc(sizeof(t_inter));
	inter->index = sp->index;
	p.x = in->pl->l + i;
	p.y = in->pl->b + j;
	p.z = (WIDTH / 2) / sin((in->cset->fov / 2) * (M_PI / 180)) + in->cset->point.z;
/* 	if (in->cset->n_vec.k < 0)
		p.z = ((WIDTH / 2) / sin((in->cset->fov / 2) * (M_PI / 180))) * (-1) + in->cset->point.z; */
	d = v_norm(v_get_from2(in->cset->point, p));
	cc = v_get_from2(in->cset->point, sp->prop.c);
//	cc.k = -5;
	//printf("%f - %f = %f\n", sp->prop.c.z, in->cset->point.z, cc.k);
	abc.x = pow(v_mod(d), 2);
	abc.y = 2 * (d.i * cc.i + d.j * cc.j + d.k * cc.k);
	abc.z = pow(v_mod(v_get_from2(sp->prop.c, in->cset->point)), 2) - pow(sp->prop.rad, 2);
	inter->d = quadratic_equation(abc.x, abc.y, abc.z);
/* 	if (i == WIDTH / 2 && j == HEIGHT / 2 - 10)
	{
		printf("Camara: %f  %f  %f\n", in->cset->point.x, in->cset->point.y, in->cset->point.z);
		printf("Pixel: %f  %f  %f\n", p.x, p.y, p.z);
		printf("Dirección: %f  %f  %f\n", d.i, d.j, d.k);
		printf("Vector CC: %f  %f  %f\n", cc.i, cc.j, cc.k);
		printf("ABC: %f  %f  %f\n", abc.x, abc.y, abc.z);
		printf("Distancia a colision en el centro del plano: %f\n", inter->d);
	//	printf("Centro de la esfera: %f %f %f\n", inter->q.x, inter->q.y, inter->q.z);
	} */
	if (inter->d < 0)
	{
/* 		if (i == WIDTH / 2 && j == (HEIGHT / 2) - 5)
			printf("P: %f  %f  %f ABC: %f  %f  %f  Distancia: %f\n\n", p.x, p.y, p.z, abc.x, abc.y, abc.z, inter->d); */
		free (inter);
		return (NULL);
	}
	cc = v_norm(cc);
	//inter->d *= sqrt(pow((p.x - in->cset->point.x), 2) + pow((p.y - in->cset->point.y), 2) + pow((p.z - in->cset->point.z), 2));
	inter->q.x = in->cset->point.x + inter->d * cc.i;
	inter->q.y = in->cset->point.y + inter->d * cc.j;
	inter->q.z = in->cset->point.z + inter->d * cc.k;
	if (i == WIDTH / 2 && j == HEIGHT / 2)
	{
		printf("Punto ->%f %f %f\n", inter->q.x, inter->q.y, inter->q.z);
		printf("Camara ->%f %f %f\n", in->cset->point.x, in->cset->point.y, in->cset->point.z);
		printf("Distancia ->%f\n", inter->d);
		printf("Vector ->%f %f %f\n", cc.i, cc.j, cc.k);
	}
	return (inter);
}
