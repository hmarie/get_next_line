/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 09:57:56 by hmarie            #+#    #+#             */
/*   Updated: 2013/12/11 14:59:06 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strichr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s) + 1)
	{
		if (*(s + i) == (char)c)
			return (i);
		i++;
	}
	return (-1);
}