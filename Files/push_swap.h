/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:23:20 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/20 15:20:53 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     PUSH_SWAP_H
# define    PUSH_SWAP_H

# include "libftX/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define MAX_INT	2147483647
# define MIN_INT	-2147483648

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	a_len;
	int	b_len;
}	t_stack;

// OPERATIONS FUNCTIONS

void	swap_oper(int *stack_a, int len, char *oper);
void	rotate_oper(int *stack, int len, char *oper);
void	rev_rotate_oper(int *stack, int len, char *oper);
void	pb_oper(t_stack *stack, char *oper);
void	pa_oper(t_stack *stack, char *oper);

// INITIAL FUNCTIONS

void	stack_storing(int argc, char **argv, t_stack *stack);
int		checking_numbers(int *stack_a, int length);
void	ft_exit(int *stack_a, char	*msg);
int		*ft_sort_int_tab(int *tab, int size);
void	indexing(t_stack *stack);
void	sort(t_stack *stack, t_stack *index, int stack_len);
void	mini_sort(t_stack *stack);
int		is_it_sorted(int *stack_a, int lenght);

#endif
