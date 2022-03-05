/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:43:18 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/18 20:13:19 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinchr(char *s1, char s2)
{
	int		i;
	int		c;
	char	*str;
	int		len;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	len = ft_strlen(s1);
	str = (char *)malloc((len + 1) * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	while (++i < len)
		str[i] = s1[i];
	str[i++] = s2;
	str[i] = '\0';
	free(s1);
	return (str);
}
