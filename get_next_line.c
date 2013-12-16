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

	ft_putendl("BEGIN CONCAT");
	s = ft_strnew(0);
	ft_putendl((*lst)->content);
	*lst = *tmp;
	while (*lst)
	{
		ft_putendl("-");
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
	ft_putendl("BEGIN NEWLST");
	if (*lst)
	{
		ft_putendl("LST FOUND");
		*lst = ft_lstnewend(*buf, ft_strlen(*buf), *lst);
		ft_putendl((*lst)->content);
		ft_putendl("LST FOUND END-");
	}
	else
	{
		ft_putendl("LST NOT FOUND");
		*lst = ft_lstnew(*buf, ft_strlen(*buf));
		*tmp = *lst;
		ft_putendl((*lst)->content);
		ft_putendl("LST NOT FOUND END-");
	}
}

static int	ft_check_buf(char **line, char **save, char *buf, t_list **lst,\
						t_list **tmp)
{
	int	i;
	ft_putendl("BEGIN CHECK BUF");

	if ((i = ft_strichr(buf, '\n')) >= 0)
	{
		ft_putendl("CHECK BUF - n FOUND");
		ft_strncpy(*line, buf, i);
		*(line + i) = 0;
		ft_putendl(*line);
		ft_newlst(line, lst, tmp);
		*save = ft_strsub(buf, i + 1, (BUF_SIZE - i));
		ft_putendl(*save);
		*line = ft_concat(lst, tmp);
		return (1);
	}
	else
	{
		ft_putendl("CHECK BUF - n NOT FOUND");
		ft_newlst(&buf, lst, tmp);
		return (0);
	}
}

static int	ft_check_save(char **line, char **save, t_list **lst, t_list **tmp)
{
	int	i;

	ft_putendl("BEGIN CHECK SAVE");
	ft_putendl(*save);
	if ((i = ft_strichr(*save, '\n')) >= 0)
	{
	    ft_putendl("CHECK SAVE - n FOUND");
	    ft_strncpy(*line, *save, i);
	    *(line + i) = 0;
	    *save = ft_strsub(*save, i + 1, ft_strlen(*save));
	    return (1);
	}
	else
	{
	    ft_putendl("CHECK SAVE - n NOT FOUND");
	    *lst = ft_lstnew(*save, ft_strlen(*save));
	    *tmp = *lst;
	    ft_putendl(*save);
	    free (*save);
	    *save = NULL;
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
	ft_putendl("START PROG");
	if (save)
	{
		ft_putendl("SAVE FOUND");
		if (ft_check_save(line, &save, &lst, &tmp) == 1)
		{
			return (1);
		}
	}
	ft_putendl("PRE SAVE NOT FOUND");
	while (read(fd, buf, BUF_SIZE) > 0)
	{
		ft_putendl("SAVE NOT FOUND");
		if (ft_check_buf(line, &save, buf, &lst, &tmp) == 1)
			return (1);
	}
	return (0);
}
