/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:41:46 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/24 21:42:26 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

int	if_sorted(t_stack *stack)
{
	t_uint	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if ((stack->u_data.i)[i] > (stack->u_data.i)[i + 1])
			i++;
		else
			break ;
	}
	if (i == stack->size - 1)
		return (-1);
	return (0);
}
