/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:50:46 by hmarie            #+#    #+#             */
/*   Updated: 2013/11/26 18:42:18 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s1, size_t len)
{
	size_t	i;
	char	*s2;

	i = 0;
	if ((s2 = (char *)malloc(sizeof(s1) * len)) == NULL)
		return (NULL);
	ft_strncpy(s2, s1, len);
	return (s2);
}

char	*ft_strtrim(char const *s)
{
	int		j;
	int		len;
	char	*s2;

	j = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	len = ft_strlen(s);
	while (len > 0 && (*s == ' ' || *s == '\n' || *s == '\t'))
		len--;
	return (ft_strndup(s, len));
}
