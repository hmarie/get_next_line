/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:48:52 by hmarie            #+#    #+#             */
/*   Updated: 2013/11/26 16:50:50 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tr;
	size_t	i;

	i = 0;
	if ((tr = ft_strnew(len)) == NULL || start > ft_strlen(s))
		return (NULL);
	if (s)
		while (i < len)
		{
			*(tr + i) = *(s + i + start);
			i++;
		}
	return (tr);
}
