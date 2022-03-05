/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:44:39 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/18 15:44:50 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SWAP
void	swap_oper(int *stack_a, int len, char *oper)
{
	int	x;

	x = stack_a[len - 1];
	stack_a[len - 1] = stack_a[len - 2];
	stack_a[len - 2] = x;
	write(1, oper, 3);
}

// ROTATE

void	rotate_oper(int *stack, int len, char *oper)
{
	int	x;

	x = stack[len - 1];
	while (len - 1 > 0)
	{
		stack[len - 1] = stack[len - 2];
		len--;
	}
	stack[len - 1] = x;
	write(1, oper, 3);
}

//REVERSE ROTATE

void	rev_rotate_oper(int *stack, int len, char *oper)
{
	int	x;
	int	i;

	i = 0;
	x = stack[i];
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = x;
	write(1, oper, 4);
}
