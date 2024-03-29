/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:30:04 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/02/05 22:34:44 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	*par_clean_id(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	j = 0;
	while (line[i + j] && !ft_isspace(line[i + j]))
		j++;
	str = ft_substr(line, i + j, ft_strlen(line) - i + j);
	free (line);
	return (str);
}
