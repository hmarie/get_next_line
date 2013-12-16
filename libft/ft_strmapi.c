/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 14:35:07 by hmarie            #+#    #+#             */
/*   Updated: 2013/12/12 11:02:36 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*s2;

	i = 0;
	if (s && s2 && f)
	{
		if ((s2 = ft_strnew(ft_strlen(s))) == NULL)
			return (NULL);
		while (*(s + i))
		{
			*(s2 + i) = f(i, *(s + i));
			i++;
		}
	}
	return (s2);
}
