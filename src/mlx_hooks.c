/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:18:39 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/04 20:38:54 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	khook_debug(struct mlx_key_data keydata, void *param)
{
	t_info	*info = (t_info *)param;
	t_pixel	px;
	int32_t	x;
	int32_t	y;

	if (keydata.action == MLX_RELEASE && keydata.key == MLX_KEY_D)
	{
		mlx_get_mouse_pos(info->mlx_s.mlx, &x, &y);
		printf("\n\nXY: %d %d\n", x, y);
		px.i = x;
		px.j = y;
		px.d = camera_ray_direction(info, px);
		t_inter	*inter = get_closest_collision(px, info);
		t_shape	*sh = info->shapes_list;
		while (sh && inter && sh->index != inter->index)
			sh = sh->next;
		t_color	color = diffuse_light(info, inter, sh);
		if (sh->type == SP)
			printf("Sphere (%d)", sh->index);
		else if (sh->type == PL)
			printf("Plane (%d)", sh->index);
		else if (sh->type == CY)
			printf("Cylinder (%d)", sh->index);
		printf(" type: %d RGB: %d %d %d\n", sh->type, color.r, color.g, color.b);
		printf("Inter -> d: %f\n", inter->d);
		printf("Direction -> %f %f %f\n", px.d.i, px.d.j, px.d.k);
		printf("q: %f %f %f\n", inter->q.x, inter->q.y, inter->q.z);
		t_vector v = v_norm(v_get_from2(inter->q, info->lset->point));
		printf("V: %f %f %f\n", v.i, v.j, v.k);
		printf("\nPunto de luz: %f %f %f\n", info->lset->point.x, info->lset->point.y, info->lset->point.z);
		if (sh->type == SP)
		{
			t_vector n = v_norm(v_get_from2(sh->prop.c, inter->q));
			printf("N: %f %f %f\n", n.i, n.j, n.k);
			printf("Facing ratio -> %f\n\n", v_dot_product(v, n));
		}
		else if (sh->type == PL)
		{
			t_vector n = sh->prop.n_vec;
			printf("N: %f %f %f\n", n.i, n.j, n.k);
			printf("Facing ratio -> %f\n\n", v_dot_product(v_norm(v_get_from2(inter->q, info->lset->point)), sh->prop.n_vec));
		}
		printf("\n--------------------------------------------------------------------\n");
	}
}

static bool	ft_keyhook2(t_info *info)
{
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_UP))
	{
		info->cset->point.y += 0.1;
		printf("a little to the top\n");
		return (true);
	}
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_DOWN))
	{
		info->cset->point.y -= 0.1;
		printf("a little to the bottom\n");
		return (true);
	}
	return (false);
}

void	ft_keyhook(void *param)
{
	t_info	*info;
	bool	redo;

	redo = false;
	info = (t_info *)param;
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_ESCAPE))
		ft_exit_program(param);
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_LEFT))
	{
		redo = true;
		info->cset->point.x -= 0.1;
		printf("a little to the left\n");
	}
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_RIGHT))
	{
		redo = true;
		info->cset->point.x += 0.1;
		printf("a little to the right\n");
	}
	if (ft_keyhook2(info))
		redo = true;
	if (redo)
		put_pixels(info);
}
