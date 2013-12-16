/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:54:26 by hmarie            #+#    #+#             */
/*   Updated: 2013/11/26 14:15:59 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void * s1, const void * s2, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)s1 + i) = *((char *)s2 + i);
		if (*((char *)s2 + i) == (unsigned char)c)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
