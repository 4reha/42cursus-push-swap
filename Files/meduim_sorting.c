/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meduim_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:17:33 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/18 20:11:52 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shift_counter(int stack_len)
{
	int	i;

	i = 1;
	if (stack_len >= 2)
		i++;
	if (stack_len >= 4)
		i++;
	if (stack_len >= 8)
		i++;
	if (stack_len >= 16)
		i++;
	if (stack_len >= 32)
		i++;
	if (stack_len >= 64)
		i++;
	if (stack_len >= 128)
		i++;
	if (stack_len >= 256)
		i++;
	if (stack_len >= 512)
		i++;
	return (i);
}

static	int	is_rev_sorted(int *stack, int len)
{
	if (len != 0)
	{
		if (len == 1)
			return (1);
		while (stack[len - 1] > stack[len - 2])
		{
			if (len - 2 == 0)
				return (1);
			len--;
		}
		return (0);
	}
	return (0);
}

static	void	to_be_continued2(t_stack *stack, t_stack *index, int a, int i)
{
	a = index->b_len;
	while (a-- > 0)
	{
		if (!(index->b[index->b_len - 1] & 1 << (i + 1)))
		{
			if (!is_rev_sorted(index->b, index->b_len)
				|| !(index->b[index->b_len - 1] & 1 << (i + 1)))
			{
				rotate_oper(index->b, index->b_len, "rb\n");
				rotate_oper(stack->b, stack->b_len, NULL);
			}
		}
		else
		{
			pa_oper(index, "pa\n");
			pa_oper(stack, NULL);
		}
	}
}

static	void	to_be_continued1(t_stack *stack, t_stack *index, int a, int i)
{
	while (a-- > 0)
	{
		if (index->a[index->a_len - 1] & 1 << i)
		{
			rotate_oper(index->a, index->a_len, NULL);
			rotate_oper(stack->a, stack->a_len, "ra\n");
		}
		else if (!(is_it_sorted(index->a, index->a_len)))
		{
			pb_oper(index, NULL);
			pb_oper(stack, "pb\n");
		}
	}
}

void	sort(t_stack *stack, t_stack *index, int stack_len)
{
	int	left_shift;
	int	i;
	int	a;

	left_shift = shift_counter(stack_len);
	i = 0;
	while (i < left_shift)
	{
		a = index->a_len;
		to_be_continued1(stack, index, a, i);
		to_be_continued2(stack, index, a, i);
		i++;
	}
	while (index->b_len > 0)
	{
		pa_oper(index, "pa\n");
		pa_oper(stack, NULL);
	}
}
