/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:58:38 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/20 15:21:57 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(int *stack_a, char *msg)
{
	free(stack_a);
	write(1, msg, 7);
	exit(1);
}

void	part_2(t_stack *stack, char *oper)
{
	if (!ft_strncmp(oper, "ra\n", 3))
		rotate_oper(stack->a, stack->a_len, NULL);
	else if (!ft_strncmp(oper, "rb\n", 3))
		rotate_oper(stack->b, stack->b_len, NULL);
	else if (!ft_strncmp(oper, "rr\n", 3))
	{
		rotate_oper(stack->a, stack->a_len, NULL);
		rotate_oper(stack->b, stack->b_len, NULL);
	}
	else if (!ft_strncmp(oper, "rra\n", 4))
		rev_rotate_oper(stack->a, stack->a_len, NULL);
	else if (!ft_strncmp(oper, "rrb\n", 4))
		rev_rotate_oper(stack->b, stack->b_len, NULL);
	else if (!ft_strncmp(oper, "rrr\n", 4))
	{
		rev_rotate_oper(stack->a, stack->a_len, NULL);
		rev_rotate_oper(stack->b, stack->b_len, NULL);
	}
	else
		ft_exit(stack->a, "Error\n");
}

void	part_1(t_stack *stack, char *oper)
{
	if (!ft_strncmp(oper, "sa\n", 3))
		swap_oper(stack->a, stack->a_len, NULL);
	else if (!ft_strncmp(oper, "sb\n", 3))
		swap_oper(stack->b, stack->b_len, NULL);
	else if (!ft_strncmp(oper, "ss\n", 3))
	{
		swap_oper(stack->a, stack->a_len, NULL);
		swap_oper(stack->b, stack->b_len, NULL);
	}
	else if (!ft_strncmp(oper, "pa\n", 3))
		pa_oper(stack, NULL);
	else if (!ft_strncmp(oper, "pb\n", 3))
		pb_oper(stack, NULL);
	else
		part_2(stack, oper);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	char	*oper;

	if (argc != 1)
	{
		stack_storing(argc, argv, &stack);
		checking_numbers(stack.a, stack.a_len);
		oper = get_next_line(0);
		while (oper)
		{
			part_1(&stack, oper);
			free(oper);
			oper = get_next_line(0);
		}
		if (is_it_sorted(stack.a, stack.a_len) && stack.b_len == 0)
			write(1, "OK\n", 4);
		else
			write(1, "KO\n", 4);
	}
}
