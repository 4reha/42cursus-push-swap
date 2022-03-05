/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:39:55 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/20 17:54:15 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ms_n_over(int fd, char *over)
{
	char	buff;
	int		rc;

	rc = 1;
	buff = 0;
	while (buff != '\n' && rc != 0)
	{
		rc = read(fd, &buff, 1);
		if (rc <= 0 || buff == '\0')
			return (NULL);
		over = ft_joinchr(over, buff);
	}
	return (over);
}

char	*get_next_line(int fd)
{
	char	*over;

	over = NULL;
	if (fd < 0)
		return (NULL);
	over = ms_n_over(fd, over);
	if (!over)
		return (NULL);
	return (over);
}
