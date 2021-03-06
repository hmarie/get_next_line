/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:33:20 by hmarie            #+#    #+#             */
/*   Updated: 2013/12/03 12:03:25 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(s2 + i) == 0)
		{
			while (*(s1 + i))
			{
				*(s1 + i) = 0;
				i++;
			}
			return (s1);
		}
		*(s1 + i) = *(s2 + i);
		i++;
	}
	return (s1);
}
