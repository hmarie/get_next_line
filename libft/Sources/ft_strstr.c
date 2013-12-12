/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:00:33 by hmarie            #+#    #+#             */
/*   Updated: 2013/11/25 18:56:30 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[j] && s2[i])
	{
		if (s1[j] == s2[i])
		{
			flag = j;
			while (s1[j++] == s2[i++])
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
