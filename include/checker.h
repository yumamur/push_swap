/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:21:53 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/24 21:45:57 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_ch_load
{
	t_stack	*a;
	t_stack	*b;
}	t_ch_load;

void	free_load(t_ch_load *load);
void	handle_error(int errno, t_ch_load *load);
void	ch_input(char *argv[], int argc, t_ch_load *load);
int		if_sorted(t_stack *stack);
int		ch_opr(t_ch_load *load, int oprs[]);
int		*read_opr(t_ch_load *load);

#endif /* PS_ERRORS */
