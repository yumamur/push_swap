/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:42:30 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/20 18:42:31 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_uint	find_place_a(t_stack *stack, int nbr)
{
	t_uint	btw;

	if (nbr < stack->u_data.i[stack->size - 1]
		&& nbr > stack->u_data.i[0])
		return (0);
	else if (nbr > stack->u_data.i[biggest(stack)]
			|| nbr < stack->u_data.i[smallest(stack)])
		return (smallest(stack));
	else
	{
		btw = stack->size - 1;
		while (btw > 1 && !(nbr > stack->u_data.i[btw] && nbr < stack->u_data.i[btw - 1]))
			--btw;
	}
	return (btw);
}

t_uint	find_place_b(t_stack *stack, int nbr)
{
	t_uint	btw;

	if (nbr > stack->u_data.i[stack->size - 1]
		&& nbr < stack->u_data.i[0])
		return (0);
	else if (nbr > stack->u_data.i[biggest(stack)]
			|| nbr < stack->u_data.i[smallest(stack)])
		return (smallest(stack));
	else
	{
		btw = stack->size - 1;
		while (btw > 1
			&& !(nbr < stack->u_data.i[btw] && nbr > stack->u_data.i[btw - 1]))
			--btw;
		return (btw);
	}
}
