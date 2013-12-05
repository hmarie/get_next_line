/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 12:37:23 by hmarie            #+#    #+#             */
/*   Updated: 2013/12/05 16:53:20 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(int const fd, char ** line)
{
	int					ret;
 	char				*buf[BUF_SIZE + 1];
	static t_list		*lst;
	t_list				*ptr;
	int					i;
	char				*str;
	char				*str2;
	void				(*ft)(void *, size_t);

	i = 1;
	ft = ft_lstmdel;
	lst = ft_lstnew(buf, BUF_SIZE + 1);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = 0;
		if (ft_memchr(buf, '\n', BUF_SIZE) == NULL)
		{
			lst->next = ft_lstnew(buf, BUF_SIZE + 1);
			i++;
		}
		else
			break ;
	}
	if ((str = (char *)malloc(sizeof(str) * (BUF_SIZE * i)  + 1)) == NULL)
		return (0);
	while (lst)
	{
		str = ft_strjoin(str, lst->content);
		ptr = lst->next;
		ft_lstdelone(&lst, ft);
		lst = ptr;
	}
	i = 0;
	while (str[i] != '\n')
		i++;
	while (str[i])
		str[i] = 0;
	lst->content = ft_strcpy(ft_strnew(ft_memlen(lst->content, '\n', BUF_SIZE)), ft_strchr(lst->content, '\n'));
	*line = *str;
	return (0);
}

