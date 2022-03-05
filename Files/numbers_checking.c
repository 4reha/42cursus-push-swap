/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:06:42 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/20 15:22:13 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_sorted(int *stack_a, int length)
{
	if (length == 1)
		return (1);
	while (stack_a[length - 1] < stack_a[length - 2])
	{
		if (length - 2 == 0)
			return (1);
		length--;
	}
	return (0);
}

int	checking_numbers(int *stack_a, int length)
{
	int	i;
	int	j;

	i = -1;
	if (length == 0)
		exit(1);
	while (++i < length)
	{
		j = i;
		while (++j < length)
			if (stack_a[i] == stack_a[j])
				ft_exit(stack_a, "Error\n");
	}
	if (is_it_sorted(stack_a, length))
		return (1);
	return (0);
}
