/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:56:41 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/20 15:13:46 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		c;
	char	*str;

	str = malloc((ft_strlen(s1)+ ft_strlen(s2)) * sizeof(char) + 2);
	if (!str)
	{
		free(s1);
		exit(1);
	}
	i = -1;
	c = 0;
	while (++i < ft_strlen(s1))
		str[i] = s1[i];
	str[i] = ' ';
	while (c < ft_strlen(s2))
		str[++i] = s2[c++];
	str[++i] = '\0';
	free(s1);
	return (str);
}
