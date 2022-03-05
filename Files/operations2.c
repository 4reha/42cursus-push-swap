/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:23:10 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/20 15:09:35 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	*plus_one(int *stack, int *len)
{
	int	*tmp;
	int	i;

	i = -1;
	*len += 1;
	tmp = malloc(sizeof(int) * *len);
	if (!tmp)
		exit (0);
	if (*len == 1)
		return (tmp);
	else
	{
		while (++i < *len)
			tmp[i] = stack[i];
		free(stack);
	}
	return (tmp);
}

static	int	*minus_one(int *stack, int *len)
{
	int	*tmp;
	int	i;

	i = -1;
	*len -= 1;
	if (*len == 0)
	{
		free(stack);
		return (0);
	}
	tmp = malloc(sizeof(int) * *len);
	if (!tmp)
		exit(1);
	if (stack)
		while (++i < *len)
			tmp[i] = stack[i];
	free(stack);
	return (tmp);
}

// PUSH TO STACK B
void	pb_oper(t_stack *stack, char *oper)
{
	if (stack->a_len)
	{	
		stack->b = plus_one(stack->b, &stack->b_len);
		stack->b[stack->b_len - 1] = stack->a[stack->a_len - 1];
		stack->a = minus_one(stack->a, &stack->a_len);
		write(1, oper, 3);
	}
}

// PUSH TO SATCK A
void	pa_oper(t_stack *stack, char *oper)
{
	if (stack->b_len)
	{
		stack->a = plus_one(stack->a, &stack->a_len);
		stack->a[stack->a_len - 1] = stack->b[stack->b_len - 1];
		stack->b = minus_one(stack->b, &stack->b_len);
		write(1, oper, 3);
	}
}
