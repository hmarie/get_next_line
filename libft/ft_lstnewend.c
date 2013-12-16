/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 10:38:27 by hmarie            #+#    #+#             */
/*   Updated: 2013/12/11 11:25:12 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnewend(void const *content, size_t content_size, t_list *lst)
{
	t_list	*newlst;

	if ((newlst = (t_list *)malloc(sizeof(*newlst))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		newlst->content = NULL;
		newlst->content_size = 0;
	}
	else
	{
		if ((newlst->content = malloc(content_size)) == NULL)
			return (NULL);
		newlst->content = ft_memcpy(newlst->content, content, content_size);
		newlst->content_size = content_size;
	}
	newlst->next = NULL;
	if (lst)
		lst->next = newlst;
	return (newlst);
}
