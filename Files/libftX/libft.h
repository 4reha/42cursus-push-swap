/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:36:57 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/02/19 15:44:32 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFFER_SIZE 10

//Part 1 - Libc Functions
int		ft_isdigit(int c);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, int n);
long	ft_atoi(char *str, int *stack_a);

char	*ft_strdup(const char *s1);

//Part 2 - Additional Fanctions
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);

//Gnl Part
char	*ft_joinchr(char *s1, char s2);

char	*get_next_line(int fd);

#endif
