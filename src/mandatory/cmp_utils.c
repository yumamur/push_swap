/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:41:21 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/11 18:41:22 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_uint	smallest(t_stack *stack)
{
	t_uint	index;
	t_uint	ret;

	index = stack->size - 1;
	ret = index - 1;
	while (index + 1)
	{
		if (stack->u_data.i[index] < stack->u_data.i[ret])
			ret = index;
		index--;
	}
	return (ret);
}

t_uint	biggest(t_stack *stack)
{
	t_uint	index;
	t_uint	ret;

	index = stack->size - 1;
	ret = index - 1;
	while (index + 1)
	{
		if (stack->u_data.i[index] > stack->u_data.i[ret])
			ret = index;
		index--;
	}
	return (ret);
}
