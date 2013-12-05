/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:45:56 by hmarie            #+#    #+#             */
/*   Updated: 2013/11/26 17:35:18 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	if ((s = (char *) malloc(sizeof(s) * size + 1)) == NULL)
		return (NULL);
	i = 0;
	ft_bzero(s, size + 1);
	return (s);
}
