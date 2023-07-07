/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:35:37 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/07 21:40:17 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	sort_two(t_stack *stack_a)
{
	if (stack_a->u_data.i[0] > stack_a->u_data.i[1])
		ps_opr(stack_a, PS_SA);
	return (0);
}

int	sort_three(t_stack *stack_a)
{
	t_uint	small;

	small = smallest(stack_a->u_data.i);
	if (small == 0)
		return (ps_opr(stack_a, PS_RRA) || ps_opr(stack_a, PS_SA));
	else if (small == 1)
	{
		if (stack_a->u_data.i[0] > stack_a->u_data.i[2])
			return (ps_opr(stack_a, PS_RA));
		else
			return (ps_opr(stack_a, PS_SA));
	}
	else if (small == 2)
	{
		if (stack_a->u_data.i[0] < stack_a->u_data.i[1])
			return (ps_opr(stack_a, PS_RRA));
		else
			return (ps_opr(stack_a, PS_RA) || ps_opr(stack_a, PS_SA));
	}
	return (-1);
}

int	sort_four(t_stack stack[])
{
	t_uint	small;

	smalll = smallest(stack_a->u_data.i);
	if (small == 0)
		return (ps_opr(stack, ))
}
