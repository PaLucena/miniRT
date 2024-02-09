/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:26:11 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/01/12 13:08:41 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief checks if the character received is a separator
 * 
 * @param c -> the character to check
 * @return true -> if the character is a separator
 * @return false -> if the character is not a separator
 */
bool	ft_isspace(char c)
{
	if (c == 9 || c == '\n' || c == 32)
		return (true);
	return (false);
}
