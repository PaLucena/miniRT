/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:05:50 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/11 19:21:48 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <math.h>

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

double	ft_atod(char *str)
{
	char	*save;
	int		i;
	double	res;
	double	n;

	i = 0;
	while (str[i] != '.')
		i++;
	save = ft_substr(str, 0, i);
	n = ft_atoi(save);
	free(save);
	save = ft_substr(str, i + 1, ft_strlen(str) - i + 1);
	res = ft_atoi(save) / pow(10, ft_strlen(save));
	res += n;
	free(save);
	return (res);
}
