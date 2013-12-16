/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:28:24 by hmarie            #+#    #+#             */
/*   Updated: 2013/11/26 12:02:36 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t                i;
	size_t                lendst;
	size_t                lensrc;

	lensrc = ft_strlen(src);
	if (size <= (lendst = ft_strlen(dst)))
		return (size + lensrc);
	i = lendst;
	while (*src && size-- > lendst + 1)
		dst[i++] = *(src++);
	if (!*src || size == lendst)
		dst[i] = '\0';
	return (lendst + lensrc);
}
