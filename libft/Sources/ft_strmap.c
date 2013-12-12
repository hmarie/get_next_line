/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:47:20 by hmarie            #+#    #+#             */
/*   Updated: 2013/11/26 15:08:04 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s2;

	i = 0;
	if (s && f)
	{
		if ((s2 = ft_strnew(ft_strlen(s))) == NULL)
			return (NULL);
		while (*(s + i))
		{
			*(s2 + i) = f(*(s + i));
			i++;
		}
		*(s2 + i) = 0;
	}
	return (s2);
}
