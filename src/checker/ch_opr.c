/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_opr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:40:36 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/23 22:40:37 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

int	ch_opr(t_ch_load *ld, int moves[])
{
	int	ct;

	ct = 0;
	while (ct++ < moves[0])
		if ((moves[ct] == PS_RA && ft_stack_shift_ndown(ld->a, 1))
			|| (moves[ct] == PS_RB && ft_stack_shift_ndown(ld->b, 1))
			|| (moves[ct] == PS_RR && ft_stack_shift_ndown(ld->a, 1)
				&& ft_stack_shift_ndown(ld->b, 1))
			|| (moves[ct] == PS_RRA && ft_stack_shift_nup(ld->a, 1))
			|| (moves[ct] == PS_RRB && ft_stack_shift_nup(ld->b, 1))
			|| (moves[ct] == PS_RRR && ft_stack_shift_nup(ld->a, 1)
				&& ft_stack_shift_nup(ld->b, 1))
			|| (moves[ct] == PS_PA
				&& ft_stack_push(ld->a, ft_stack_pop(ld->b).buf))
			|| (moves[ct] == PS_PB
				&& ft_stack_push(ld->b, ft_stack_pop(ld->a).buf))
			|| (moves[ct] == PS_SA
				&& ft_stack_swap(ld->a, ld->a->size - 2, ld->a->size - 1))
			|| (moves[ct] == PS_SB
				&& ft_stack_swap(ld->b, ld->a->size - 2, ld->a->size - 1))
			|| (moves[ct] == PS_SS && ft_stack_swap(ld->a, 0, 1)
				&& ft_stack_swap(ld->b, 0, 1)))
			handle_error(OPR_ERROR, ld);
	return (0);
}
