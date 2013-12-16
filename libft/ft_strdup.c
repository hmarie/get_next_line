/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:55:55 by hmarie            #+#    #+#             */
/*   Updated: 2013/11/26 18:38:42 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	if ((s2 = (char *)malloc(sizeof(s1) * ft_strlen(s1))) == NULL)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
