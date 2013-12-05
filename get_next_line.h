/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarie <hmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 14:25:27 by hmarie            #+#    #+#             */
/*   Updated: 2013/12/05 12:51:17 by hmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H__
# define __GET_NEXT_LINE_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	get_next_line(int const ft, char ** line);

#endif
