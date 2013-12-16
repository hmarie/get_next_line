/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 12:04:44 by hmarie            #+#    #+#             */
/*   Updated: 2013/12/12 12:06:47 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#includes "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	while (*alst)
	{
		ft_lstdelone(alst, del);
		*alst = (*alst)->next;
	}
}
