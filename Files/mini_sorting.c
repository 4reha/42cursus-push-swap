/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:34:39 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/18 20:08:43 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	to_be_continued2(int *stack_a, int *i)
{
	if (stack_a[2] > stack_a[1] && stack_a[1] > stack_a[0])
	{
		swap_oper(stack_a, 3, "sa\n");
		rev_rotate_oper(stack_a, 3, "rra\n");
		*i += 1;
	}
	if (stack_a[0] < stack_a[1])
	{
		rev_rotate_oper(stack_a, 3, "rra\n");
		*i += 1;
	}
	if (stack_a[0] < stack_a[2])
	{
		rotate_oper(stack_a, 3, "ra\n");
		*i += 1;
	}
	if (stack_a[1] < stack_a[2])
	{
		swap_oper(stack_a, 3, "sa\n");
		*i += 1;
	}
}

void	sort_three(t_stack *stack)
{
	int	i;

	i = 1;
	if (stack->a_len == 2 && !is_it_sorted(stack->a, stack->a_len))
	{
		swap_oper(stack->a, 2, "sa\n");
	}
	else if (stack->a_len > 2)
	{
		while (i != 0)
		{
			i = 0;
			to_be_continued2(stack->a, &i);
		}
	}
}

static	void	to_be_continued(t_stack *stack, int i)
{
	if (i < 2)
	{
		if (i == 1)
		{
			rev_rotate_oper(stack->a, stack->a_len, "rra\n");
			rev_rotate_oper(stack->a, stack->a_len, "rra\n");
		}
		else
			rev_rotate_oper(stack->a, stack->a_len, "rra\n");
	}
	else
	{
		if ((i == 2 && stack->a_len == 4) || i == 3)
			rotate_oper(stack->a, stack->a_len, "ra\n");
		else if (i == 2)
		{
			rotate_oper(stack->a, stack->a_len, "ra\n");
			rotate_oper(stack->a, stack->a_len, "ra\n");
		}
	}
}

void	sort_five(t_stack *stack)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = ft_sort_int_tab(stack->a, stack->a_len);
	i = -1;
	j = 0;
	while (++i < stack->a_len && j <= 1)
	{
		if (sorted[j] == stack->a[i])
		{
			if (i != stack->a_len - 1)
			{
				to_be_continued(stack, i);
			}
			pb_oper(stack, "pb\n");
			j++;
			i = -1;
		}
	}
	sort_three(stack);
	pa_oper(stack, "pa\n");
	pa_oper(stack, "pa\n");
}

void	mini_sort(t_stack *stack)
{
	if (stack->a_len <= 3)
		sort_three(stack);
	else if (stack->a_len <= 5)
		sort_five(stack);
}
