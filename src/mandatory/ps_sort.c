/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:43:41 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/20 18:43:42 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ps_sort(t_load *load)
{
	if (load->a->size == 2)
		return (ps_opr(load, PS_SA));
	else if(load->a->size == 3)
		return (sort_three(load));
	else if(load->a->size == 4)
		return (sort_four(load));
	else if(load->a->size == 5)
		return (sort_five(load));
	if (!ps_opr(load, PS_PB) && load->a->size >= 5)
		ps_opr(load, PS_PB);
	while (load->a->size)
	{
		rotate(TO_B, load);
		load->func(TO_B, load);
	}
	while (load->b->size)
		ps_opr(load, PS_PA);
	if (smallest(load->a) < load->a->size / 2)
		while (smallest(load->a) != load->a->size - 1)
			ps_opr(load, PS_RRA);
	else
		while (smallest(load->a) != load->a->size - 1)
			ps_opr(load, PS_RA);
	return (0);
}
