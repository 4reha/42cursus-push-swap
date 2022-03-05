/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:06:21 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/18 15:46:00 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cpy(int *sorted, int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		sorted[i] = tab[i];
}

int	*ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	*sorted;
	int	temp;

	i = -1;
	sorted = malloc(size * sizeof(int));
	if (!sorted)
		return (NULL);
	cpy(sorted, tab, size);
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (sorted[i] > sorted[j])
			{
				temp = sorted[j];
				sorted[j] = sorted[i];
				sorted[i] = temp;
			}
		}
	}
	return (sorted);
}
