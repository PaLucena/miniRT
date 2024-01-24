/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:18:39 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/24 15:30:03 by palucena         ###   ########.fr       */
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
		px.p = plane_point_coords(info, px.i, px.j);
		px.d = v_norm(v_get_from2(info->cset->point, px.p));
		t_inter	*inter = get_closest_collision(px, info);
		t_shape	*sh = info->shapes_list;
		while (sh->index != inter->index)
			sh = sh->next;
		t_color	color = diffuse_light(info, inter, sh);
		printf("Shape -> %d type: %d RGB: %d %d %d\n", sh->index, sh->type, color.r, color.g, color.b);
		printf("Inter -> d: %f\n", inter->d);
		printf("Direction -> %f %f %f\n", px.d.i, px.d.j, px.d.k);
		printf("q: %f %f %f\n", inter->q.x, inter->q.y, inter->q.z);
		t_vector v = v_norm(v_get_from2(inter->q, info->lset->point));
		t_vector n = v_norm(v_get_from2(sh->prop.c, inter->q));
		printf("V: %f %f %f\n", v.i, v.j, v.k);
		printf("N: %f %f %f\n", n.i, n.j, n.k);
		printf("\nPunto de luz: %f %f %f\n", info->lset->point.x, info->lset->point.y, info->lset->point.z);
		if (sh->type == SP)
		{
			printf("Sp Facing ratio -> %f\n\n", v_dot_product(v, n));
		}
		else if (sh->type == PL)
		{
			printf("Pl Facing ratio -> %f\n\n", v_dot_product(v_norm(v_get_from2(inter->q, info->lset->point)), sh->prop.n_vec));
		}
		printf("\n--------------------------------------------------------------------\n");
	}
}

static void	khook_left(t_info *info)
{
	info->cset->point.x -= 0.1;
	printf("a little to the left\n");
}

static void	khook_up(t_info *info)
{
	info->cset->point.y += 0.1;
	printf("a little to the top\n");
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
		khook_left(info);
	}
	if (mlx_is_key_down(info->mlx_s.mlx, MLX_KEY_UP))
	{
		redo = true;
		khook_up(info);
	}

	if (redo)
		put_pixels(info);
}
