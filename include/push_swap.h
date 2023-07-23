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

#include <stdio.h>
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

# define TO_A -1
# define TO_B 0

typedef struct s_load
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*cur;
	t_c_int	*ptr;
	t_uint	i;
	t_uint	ctl;
	int		nbr;
	void	(*func)(int, struct s_load *);
}	t_load;

void	ps_input(char *argv[], int argc, t_load *load);
int		ps_opr(t_load *load, int move);
int		ps_sort(t_load *load);
void	handle_error(int errno, t_load *load);

int		if_sorted(t_stack *stack);
t_uint	find_index(t_stack *stack, int nbr);
t_uint	smallest(t_stack *stack);
t_uint	biggest(t_stack *stack);

int		sort_three(t_load *load);
int		sort_four(t_load *load);
int		sort_five(t_load *load);
void	rotate(int mode, t_load *load);

t_uint	find_place_a(t_stack *stack, t_c_int nbr);
t_uint	find_place_b(t_stack *stack, t_c_int nbr);

t_uint	calc_rarb(int mode, t_load *load);
t_uint	calc_rrarrb(int mode, t_load *load);
t_uint	calc_rarrb(int mode, t_load *load);
t_uint	calc_rrarb(int mode, t_load *load);

void	apply_rarb(int mode, t_load *load);
void	apply_rrarrb(int mode, t_load *load);
void	apply_rarrb(int mode, t_load *load);
void	apply_rrarb(int mode, t_load *load);

#endif /* PS_ERRORS */
