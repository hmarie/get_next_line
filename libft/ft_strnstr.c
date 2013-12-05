/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:21:08 by hmarie            #+#    #+#             */
/*   Updated: 2013/12/03 12:03:37 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char                *ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	flag;

	i = 0;
	j = 0;
	flag = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[j] && s2[i] && j < n)
	{
		if (s1[j] == s2[i] && j < n)
		{
			flag = j;
			while (s1[j++] == s2[i++] && j <= n)
			{
				if (!s2[i])
					return ((char *)s1 + flag);
			}
			j = flag;
		}
		j++;
		i = 0;
	}
	return (NULL);
}
