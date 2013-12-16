/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:31:12 by hmarie            #+#    #+#             */
/*   Updated: 2013/11/26 14:16:30 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	void	* s3;
	size_t	i;

	i = 0;
	if ((s3 = (char *)malloc(sizeof(s2) * ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	while (*((char *)s2 + i))
	{
		*((char *)s3 + i) = *((char *)s2 + i);
		i++;
	}
	*((char *)s3 + i) = 0;
	ft_memcpy(s1, s3, n);
	free(s3);
	return (s1);
}
