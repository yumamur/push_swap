/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:47:00 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/07 10:41:13 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	wr(int opr)
{
	if (opr == 0)
		return (0xFF && write(1, "ra\n", 3));
	else if (opr == 1)
		return (0xFF && write(1, "rb\n", 3));
	else if (opr == 2)
		return (0xFF && write(1, "rr\n", 3));
	else if (opr == 3)
		return (0xFF && write(1, "rra\n", 4));
	else if (opr == 4)
		return (0xFF && write(1, "rrb\n", 4));
	else if (opr == 5)
		return (0xFF && write(1, "rrr\n", 4));
	else if (opr == 6)
		return (0xFF && write(1, "pa\n", 3));
	else if (opr == 7)
		return (0xFF && write(1, "pb\n", 3));
	else if (opr == 8)
		return (0xFF && write(1, "sa\n", 3));
	else if (opr == 9)
		return (0xFF && write(1, "sb\n", 3));
	else if (opr == 10)
		return (0xFF && write(1, "ss\n", 3));
	return (0);
}

int	ps_opr(t_load *ld, int move)
{
	if ((move == PS_RA && wr(0) && ft_stack_shift_ndown(ld->a, 1))
		|| (move == PS_RB && wr(1) && ft_stack_shift_ndown(ld->b, 1))
		|| (move == PS_RR && wr(2) && (ft_stack_shift_ndown(ld->a, 1)
				|| ft_stack_shift_ndown(ld->b, 1)))
		|| (move == PS_RRA && wr(3) && ft_stack_shift_nup(ld->a, 1))
		|| (move == PS_RRB && wr(4) && ft_stack_shift_nup(ld->b, 1))
		|| (move == PS_RRR && wr(5) && (ft_stack_shift_nup(ld->a, 1)
				|| ft_stack_shift_nup(ld->b, 1)))
		|| (move == PS_PA && wr(6)
			&& ft_stack_push(ld->a, ft_stack_pop(ld->b).buf))
		|| (move == PS_PB && wr(7)
			&& ft_stack_push(ld->b, ft_stack_pop(ld->a).buf))
		|| (move == PS_SA && wr(8)
			&& ft_stack_swap(ld->a, ld->a->size - 2, ld->a->size - 1))
		|| (move == PS_SB && wr(9)
			&& ft_stack_swap(ld->b, ld->b->size - 2, ld->b->size - 1))
		|| (move == PS_SS && wr(10)
			&& (ft_stack_swap(ld->a, ld->a->size - 1, ld->a->size - 1)
				|| ft_stack_swap(ld->b, ld->b->size - 2, ld->b->size - 1))))
		handle_error(OPR_ERROR, ld);
	return (0);
}
