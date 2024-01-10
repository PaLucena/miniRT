/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:05:50 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/10 19:33:04 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

bool	ft_check_atod(char *str)
{
	int		i;
	int		dot;
	bool	post;

	i = 0;
	dot = 0;
	post = false;
	while (str[i] && (ft_isdigit(str[i]) == 1 || str[i] == '.'))
	{
		if (str[i] == '.')
			dot++;
		if (dot != 0 && ft_isdigit(str[i]) == 1)
			post = true;
		i++;
	}
	if (!str[i] && dot == 1 && post)
		return (true);
	return (false);
}
# include <stdio.h>
# include <math.h>
double	ft_atod(char *str)
{
	char	*save;
	int		i;
	double	res;
	int		n;

	i = 0;
	while (str[i] != '.')
		i++;
	save = ft_substr(str, 0, i);
	n = ft_atoi(save);
	printf("Primera parte %i\n", n);
	free(save);
	save = ft_substr(str, i + 1, ft_strlen(str) - i + 1);
	res = (double)ft_atoi(save) / pow(10, ft_strlen(save));
	printf("Segunda parte antes de dividir %i\ncast: %f\n", ft_atoi(save), (float)ft_atoi(save));
	printf("Segunda parte diviendo entre %f: %f\n", pow(10, ft_strlen(save)), res);
	res += n;
	return (res);
}
// FIXME: leak