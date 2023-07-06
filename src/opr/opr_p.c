/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:47:05 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/17 13:34:33 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	opr_pa(t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_stack_valid(stack_a, 0) || !ft_stack_valid(stack_b, 0))
		return (-1);
	ft_stack_push(stack_a, ft_stack_pop(stack_b).buf);
	return (0);
}

int	opr_pb(t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_stack_valid(stack_a, 0) || !ft_stack_valid(stack_b, 0))
		return (-1);
	ft_stack_push(stack_b, ft_stack_pop(stack_a).buf);
	return (0);
}
