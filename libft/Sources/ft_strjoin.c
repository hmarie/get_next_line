/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:50:00 by hmarie            #+#    #+#             */
/*   Updated: 2013/12/11 17:02:03 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ct;

	if (!s1 || !s2 || !(ct = (char *)malloc(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	return (ft_strcat(ft_strcpy(ct, s1), s2));
}
