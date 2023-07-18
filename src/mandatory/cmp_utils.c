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

int	if_sorted(t_stack *stack)
{
	t_uint	i;

	i = 0;
	while (i < stack->size - 1)
		if ((stack->u_data.i)[i] > (stack->u_data.i)[i + 1])
			i++;
	else
		break ;
	if (i != stack->size - 1)
		return (-1);
	return (0);
}

t_uint	smallest(t_stack *stack)
{
	t_uint	index;
	t_uint	ret;

	index = 0;
	ret = 0;
	while (index < stack->size)
	{
		if (stack->u_data.i[index] < stack->u_data.i[ret])
			ret = index;
		index++;
	}
	return (ret);
}

t_uint	biggest(t_stack *stack)
{
	t_uint	index;
	t_uint	ret;

	index = 0;
	ret = 0;
	while (index < stack->size)
	{
		if (stack->u_data.i[index] > stack->u_data.i[ret])
			ret = index;
		index++;
	}
	return (ret);
}
