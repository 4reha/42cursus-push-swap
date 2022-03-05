/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:22:06 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/20 15:39:54 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(int *stack_a, char	*msg)
{
	free(stack_a);
	write(1, msg, 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc != 1)
	{
		stack_storing(argc, argv, &stack);
		if (checking_numbers(stack.a, stack.a_len))
			exit(1);
		if (stack.a_len <= 3 || stack.a_len <= 5)
			mini_sort(&stack);
		else
			indexing(&stack);
		free(stack.b);
	}
	return (0);
}
