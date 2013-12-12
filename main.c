/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 17:50:42 by hmarie            #+#    #+#             */
/*   Updated: 2013/12/10 16:53:42 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

int     main(void)
{
    int         fd;
    char        *line;

    line = NULL;
    fd = open("file", O_RDONLY);
    while ((get_next_line(fd, &line)))
    {
        ft_putstr("\033[38;5;36mRetour du main : \033[0m");
        ft_putstr(line);
        ft_putchar('\n');
    }
	ft_putstr("\033[38;5;36mRetour du main : \033[0m");
	ft_putendl(line);
    close(fd);
    return (0);
}
