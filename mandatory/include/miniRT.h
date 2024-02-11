/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:21:20 by palucena          #+#    #+#             */
/*   Updated: 2024/02/11 19:20:08 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 2560
# define HEIGHT 1440
# define EPS 0.000001

# define BRIGHTNESS 50.0


//# define WIDTH 1400
//# define HEIGHT 1000

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/errno.h>
# include <math.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "miniRT_structs.h"
# include "miniRT_functions.h"

extern bool	center;

#endif