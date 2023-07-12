/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:21:53 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/06 23:04:59 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include "libft/stackft.h"
# include "libft/libft.h"
# include "operation_modes.h"
# include "ps_errno.h"

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

typedef struct s_load
{
	t_stack	*a;
	t_stack	*b;
}	t_load;

typedef struct t_moves
{
	int32_t	ar;
	int32_t	arr;
	int32_t	br;
	int32_t	brr;
}	t_moves;

void	handle_error(int errno, t_load *load);
t_load	ps_input(char *argv[], int argc);
int		ps_opr(t_load *load, int moves[]);

int		sort_two(t_load *load);
int		sort_three(t_load *load);
int		sort_four(t_load *load);
int		sort_five(t_load *load);

t_uint	smallest(t_stack *stack);
t_uint	biggest(t_stack *stack);
#endif /* PS_ERRORS */
