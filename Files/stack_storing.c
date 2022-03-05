/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_storing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:19:56 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/20 15:22:52 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_freee(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}

void	arg_checker(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (argv[++i])
	{
		count = 0;
		j = -1;
		while (argv[i][++j])
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				count++;
		if (count == 0)
			ft_exit(NULL, "Error\n");
	}
}

void	storing(t_stack *stack, char **ptr, int len)
{
	int	j;

	stack->a_len = len;
	stack->b_len = 0;
	j = -1;
	while (++j < len)
	{	
		if (ft_atoi(ptr[len - 1 - j], stack->a) > MAX_INT
			|| ft_atoi(ptr[len - 1 - j], stack->a) < MIN_INT)
			ft_exit(stack->a, "Error\n");
		stack->a[j] = ft_atoi(ptr[len - 1 - j], stack->a);
	}
	ft_freee(ptr);
}

void	stack_storing(int argc, char **argv, t_stack *stack)
{
	int		i;
	char	*str;
	char	**ptr;

	i = 0;
	arg_checker(argv);
	str = ft_strdup(argv[++i]);
	while (++i < argc)
		str = ft_strjoin(str, argv[i]);
	ptr = ft_split(str, ' ');
	free(str);
	if (!ptr)
		exit(1);
	i = -1;
	while (ptr[++i])
		;
	stack->a = malloc(sizeof(int) * i);
	if (!stack->a)
	{
		ft_freee(ptr);
		exit(1);
	}
	storing(stack, ptr, i);
}
