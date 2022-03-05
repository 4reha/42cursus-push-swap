/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:58:14 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/20 16:20:54 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	find_index(int *a, int len, int target)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (a[i] == target)
			return (i);
	}
	return (i);
}

void	indexing(t_stack *stack)
{
	int		*sorted;
	t_stack	index;
	int		i;
	int		j;

	sorted = ft_sort_int_tab(stack->a, stack->a_len);
	index.a = (int *)malloc(sizeof(int) * stack->a_len);
	if (!sorted || !index.a)
		ft_exit(stack->a, NULL);
	index.a_len = stack->a_len;
	index.b_len = 0;
	i = -1;
	while (++i < stack->a_len)
	{
		j = find_index(stack->a, stack->a_len, sorted[i]);
		index.a[j] = i;
	}
	sort(stack, &index, index.a_len);
	free(index.a);
	free(index.b);
	free(sorted);
}
