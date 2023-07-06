/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:47:00 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/06 16:56:10 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ps_opr(t_stack st[], int mode)
{
	if ((mode == PS_SA && !ft_stack_swap(&st[0], 0, 1))
		|| (mode == PS_SB && !ft_stack_swap(&st[1], 0, 1))
		|| (mode == PS_SS && !ft_stack_swap(&st[0], 0, 1)
			&& !ft_stack_swap(&st[1], 0, 1))
		|| (mode == PS_PA && !ft_stack_push(&st[0], ft_stack_pop(&st[1]).buf))
		|| (mode == PS_PB && !ft_stack_push(&st[1], ft_stack_pop(&st[0]).buf))
		|| (mode == PS_RA && !ft_stack_shift_nup(&st[0], 1))
		|| (mode == PS_RB && !ft_stack_shift_nup(&st[1], 1))
		|| (mode == PS_RR && !ft_stack_shift_nup(&st[0], 1)
			&& !ft_stack_shift_nup(&st[1], 1))
		|| (mode == PS_RRA && !ft_stack_shift_ndown(&st[0], 1))
		|| (mode == PS_RRB && !ft_stack_shift_ndown(&st[1], 1))
		|| (mode == PS_RRR && !ft_stack_shift_ndown(&st[0], 1)
			&& !ft_stack_shift_ndown(&st[1], 1)))
		return (0);
	return (-1);
}
