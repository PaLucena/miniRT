/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:17:47 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/09 15:44:48 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	shadow_search(t_info *info, t_lset *light, t_point q)
{
	t_inter		*inter;
	t_vector	ray;
	double		d;

	ray = v_norm(v_get_from2(q, light->point));
	inter = get_closest_collision(ray, q, info);
	d = v_mod(v_get_from2(info->lset->point, q));
	if (inter && inter->d > EPS && inter->d < d)
		return (free(inter), true);
	return (free(inter), false);
}

static t_color	ambient_light(t_color sh, t_aset *aset)
{
	t_color	result;

	result.r = ft_cl_clamp(sh.r * (aset->color.r * aset->ratio / 255));
	result.g = ft_cl_clamp(sh.g * (aset->color.g * aset->ratio / 255));
	result.b = ft_cl_clamp(sh.b * (aset->color.b * aset->ratio / 255));
	return (result);
}

static t_color	diffuse_light(t_lset *light, t_inter *inter, t_shape *sh)
{
	t_vector	v;
	t_vector	n;
	double		vn;
	t_color		result;

	v = v_norm(v_get_from2(inter->q, light->point));
	if (sh->type == PL)
		n = v_norm(sh->prop.n_vec);
	else
		n = v_norm(v_get_from2(sh->prop.c, inter->q));
	vn = v_dot_product(v, n);
	result.r = sh->prop.color.r * (light->color.r * light->brightness / 255);
	result.r = ft_cl_clamp(result.r * vn);
	result.g = sh->prop.color.g * (light->color.g * light->brightness / 255);
	result.g = ft_cl_clamp(result.g * vn);
	result.b = sh->prop.color.b * (light->color.b * light->brightness / 255);
	result.b = ft_cl_clamp(result.b * vn);
	return (result);
}

/* t_v3	vec3_reflection(t_v3 incident, t_v3 normal)
{
	t_v3	refelction;
	double	dot;

	dot = vec3_dot(incident, normal);
	refelction = vec3_sub(incident, (vec3_multk(normal, (2.0 * dot))));
	return (refelction);
} */

/* static int	specular(t_hit *hit, double *dot, t_ray *shadow, t_light *light)
{
	t_v3	reflection;
	t_v3	incident;

	(void) light;
	incident = vec3_negative(shadow->direction);
	reflection = vec3_reflection(incident, hit->normal);
	*dot = vec3_dot(reflection, hit->view);
	if (*dot > 0)
		return (0);
	*dot = (pow(*dot, SHININESS) * SPECULAR);
	return (1);
} */

static t_color	specular_ref(t_info *in, t_lset *l, t_inter *inter, t_shape *sh)
{
	double		refr;
	t_vector	v_refr;
	t_vector	n;
	t_color		result;

	if (sh->type == PL)
		n = v_norm(sh->prop.n_vec);
	else
		n = v_norm(v_get_from2(sh->prop.c, inter->q));
 	refr = v_dot_product(n, v_norm(v_opposite_vec(v_get_from2(inter->q, l->point))));
 	v_refr = v_get_from2(v_to_p(v_esc_mult(n, (2 * refr))), v_to_p(v_norm(v_opposite_vec(v_get_from2(inter->q, l->point)))));
	refr = v_dot_product(v_refr, v_norm(v_get_from2(in->cset->point, inter->q)));
	if (refr > 0)
		return ((t_color){0,0,0});
	refr = pow(refr, BRIGHTNESS);
	result.r = ft_cl_clamp(l->color.r * refr);
	result.g = ft_cl_clamp(l->color.g * refr);
	result.b = ft_cl_clamp(l->color.b * refr);
	return (result);
}   

void	ft_phong(t_inter *inter, t_info *info, t_pixel px)
{
	t_shape	*shape;
	t_lset	*light;
	t_color	result;

	shape = info->shapes_list;
	light = info->lset;
	while (shape->index != inter->index)
		shape = shape->next;
	result = shape->prop.color;
	result = ambient_light(shape->prop.color, info->aset);
	if (!shadow_search(info, light, inter->q))
	{
		result = add_color(result, diffuse_light(light, inter, shape));
		result = add_color(result, specular_ref(info, light, inter, shape));
	}
	mlx_put_pixel(info->mlx_s.win, px.i, px.j, get_rgba(result));
}

//TODO: quedarse con esta versión
/* void	ft_phong(t_inter *inter, t_info *info, t_pixel px)
{
	t_shape	*shape;
	t_color	result;

	shape = info->shapes_list;
	while (shape->index != inter->index)
		shape = shape->next;
	result = shape->prop.color;
	result = ambient_light(shape->prop.color, info->aset);
	if (!shadow_search(info, light, inter->q))
		result = add_color(result, diffuse_light(inter, shape));
	mlx_put_pixel(info->mlx_s.win, px.i, px.j, get_rgba(result));
} */
