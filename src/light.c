/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:17:47 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/26 14:38:10 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

uint32_t	get_rgba(t_color color)
{
	return (color.r << 24 | color.g << 16 | color.b << 8 | 255);
}

int	ft_cl_clamp(double unclamped)
{
	int	runcl;

	runcl = round(unclamped);
	if (0 > runcl)
		return (0);
	if (255 < runcl)
		return (255);
	return (runcl);
}

/*  static t_color	ph_iamb(t_info *info, t_color color_obj)
{
	t_color	amb_color;

	amb_color.r = ft_cl_clamp(color_obj.r + ft_cl_clamp(info->aset->color.r * info->aset->ratio));
	amb_color.g = ft_cl_clamp(color_obj.g + ft_cl_clamp(info->aset->color.g * info->aset->ratio));
	amb_color.b = ft_cl_clamp(color_obj.b + ft_cl_clamp(info->aset->color.b * info->aset->ratio));
	return (amb_color);
} */

double	shadow_cy(t_info *info, t_shape *shape, t_vector ray)
{
	return (-1);
}


double	shadow_pl(t_info *info, t_shape *shape, t_vector ray)
{
	//TODO: esto
	t_inter	*inter;
	double	top;
	double	bot;

	if (!plane_hit(in, pl, px))
		return (NULL);
	inter = malloc(sizeof(t_inter));
	inter->index = pl->index;
	top = v_dot_product(v_get_from2(in->cset->point, pl->prop.c),
			pl->prop.n_vec);
	bot = v_dot_product(px.d, pl->prop.n_vec);
	inter->d = (top / bot);
	inter->q = inter_point_coords(in, inter, px.d, pl->type);
	inter->q.x *= -1;
	inter->d *= (-1);
}

double	shadow_sp(t_info *info, t_shape *shape, t_vector ray)
{
	//TODO: esto
}

bool	shadow_search(t_info *info, t_point q)
{
	t_shape		*tmp_shape;
	t_vector	ray;
	double		d;

	tmp_shape = info->shapes_list;
	ray = v_norm(v_get_from2(info->lset->point, q));
	d = v_mod(v_get_from2(info->lset->point, q));
	while (tmp_shape)
	{
		if (tmp_shape->type == CY && 0 < shadow_cy(info, tmp_shape, ray) &&
				shadow_cy(info, tmp_shape, ray) < d)
			return (true);
		else if (tmp_shape->type == PL && 0 < shadow_pl(info, tmp_shape, ray) &&
				shadow_pl(info, tmp_shape, ray) < d)
			return (true);
		else if (tmp_shape->type == SP && 0 < shadow_sp(info, tmp_shape, ray) &&
				shadow_sp(info, tmp_shape, ray) < d)
			return (true);
		tmp_shape = tmp_shape->next;
	}
	return (false);
}

void	ft_phong(t_inter *inter, t_info *info, t_pixel px)
{
	t_shape	*shape;
	t_color	result;
	/* t_color	amb;
	t_color	diff; */

	shape = info->shapes_list;
	//printf("KLK: %d %d %d %d \n", shape->index, shape->prop.color.r, shape->prop.color.g, shape->prop.color.b);
	while (shape->index != inter->index)
		shape = shape->next;
	result = diffuse_light(info, inter, shape);
	shadow_search(info, inter->q);
		//printf("%f ", diff);
/* 	amb = ph_iamb(info, shape->prop.color);
	//printf("(AMB) R:%i, G:%i, B:%i\n", amb.r, amb.g, amb.b);
	diff = ph_idiffuse(amb, info, shape, *inter); // FIXME: no va bien */
	mlx_put_pixel(info->mlx_s.win, px.i, px.j, get_rgba(result));
}

void	ft_darkness(t_info *info, double x, double y)
{
	t_color	black;

	black.r = 0;
	black.g = 0;
	black.b = 0;
	mlx_put_pixel(info->mlx_s.win, x, y, get_rgba(black));
}