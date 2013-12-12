/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 10:34:23 by hmarie            #+#    #+#             */
/*   Updated: 2013/12/12 11:18:35 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static char	*ft_concat(t_list **lst, t_list **tmp)
{
	char	*s;
	s = ft_strnew(0);
	ft_putendl("TEST 10");
	ft_putendl((*lst)->content);
	*lst = *tmp;
	while (*lst)
	{
		ft_putendl("TEST 11");
		ft_putstr("CONTENT AVANT: ");
		ft_putendl((*lst)->content);
		ft_putstr("CONTENU DE S AVANT: ");
		ft_putendl(s);
		s = ft_strjoin(s, (*lst)->content);
		ft_putstr("CONTENT APRES: ");
		ft_putendl((*lst)->content);
		ft_putstr("CONTENU DE S APRES: ");
		ft_putendl(s);
		*lst = (*lst)->next;
	}
	return (s);
}

static void	ft_newlst(char **buf, t_list **lst, t_list **tmp)
{
	ft_putendl("TEST 7");
	if (*lst)
	{
		ft_putendl("TEST 9");
		*lst = ft_lstnewend(*buf, ft_strlen(*buf), *lst);
		ft_putendl((*lst)->content);
		ft_putendl("TEST 9-");
	}
	else
	{
		ft_putendl("TEST 8");
		*lst = ft_lstnew(*buf, ft_strlen(*buf));
		*tmp = *lst;
		ft_putendl((*lst)->content);
		ft_putendl("TEST 8-");
	}
}

static int	ft_check_buf(char **line, char **save, char *buf, t_list **lst, t_list **tmp)
{
	int	i;
	ft_putendl("TEST 5");

	if ((i = ft_strichr(buf, '\n')) >= 0)
	{
		ft_putendl("TEST 6");
		ft_putnbr(i);
		ft_strncpy(*line, buf, i);
		ft_putendl(*line);
		**(line + i) = 0;
		ft_putendl(*line);
		ft_newlst(line, lst, tmp);
		*save = ft_strsub(buf, i + 1, (BUF_SIZE - i));
		ft_putendl(*save);
		*line = ft_concat(lst, tmp);
		return (1);
	}
	else
	{
		ft_putendl("TEST 6.5");
		ft_newlst(&buf, lst, tmp);
		return (0);
	}
}

static int	ft_check_save(char **line, char **save, t_list **lst, t_list **tmp)
{
	int	i;

	if ((i = ft_strichr(*save, '\n')) >= 0)
	{
		ft_putendl("TEST 12");
		ft_strncpy(*line, *save, i);
		*(line + i) = 0;
		*save = ft_strsub(*save, i + 1, ft_strlen(*save));
		return (1);
	}
	else
	{
	ft_putendl("TEST 13");
		*lst = ft_lstnew(*save, ft_strlen(*save));
	ft_putendl("TEST 14");
		*tmp = *lst;
		ft_putendl(*save);
	ft_putendl("TEST 15");
		free (*save);
	ft_putendl("TEST 16");
		*save = NULL;
	ft_putendl("TEST 17");
		return (0);
	}
}

int			get_next_line(int const fd, char **line)
{
	static char	*save = NULL;
	t_list		*lst;
	t_list		*tmp;
	char		*buf;

	*line = ft_strnew(0);
	buf = ft_strnew(BUF_SIZE + 1);
	lst = NULL;
	tmp = NULL;
	ft_putendl("TEST 1");
	if (save)
	{
		ft_putendl("TEST 2");
		if (ft_check_save(line, &save, &lst, &tmp) == 1)
		{
			return (1);
		}
	}
	ft_putendl("TEST 2.5");
	while (read(fd, buf, BUF_SIZE) > 0)
	{
		ft_putendl("TEST 4");
		if (ft_check_buf(line, &save, buf, &lst, &tmp) == 1)
			return (1);
	}
	return (0);
}
