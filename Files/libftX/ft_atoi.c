/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:41:22 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/20 15:23:18 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

long	ft_atoi(char *str, int *stack_a)
{
	long	res;
	int		s;
	int		i;

	res = 0;
	s = 1;
	i = -1;
	while (str[++i] == ' ')
		if (str[i + 1] == '\0')
			ft_exit(stack_a, "Error\n");
	if (str[i] == '-' || str[i] == '+' )
		if (str[i++] == '-')
			s = -1;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - 48;
		else if (str[i] == ' ')
			break ;
		else
			ft_exit(stack_a, "Error\n");
		i++;
	}
	return (res * s);
}
