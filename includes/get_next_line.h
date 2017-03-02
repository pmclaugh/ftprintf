/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:32:50 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/12/14 15:52:03 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <fcntl.h>
# include "libft.h"

typedef struct	s_rem
{
	int				fd;
	char			rem[BUFF_SIZE];
	int				len;
	struct s_rem	*next;
}				t_rem;

int				get_next_line(const int fd, char **line);

#endif
