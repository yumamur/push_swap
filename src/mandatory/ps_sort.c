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
	t_uint	top;

	if (load->a->size <= 5)
		return (sort_five(load));
	if (!ps_opr(load, PS_PB) && load->a->size >= 4)
		ps_opr(load, PS_PB);
	while (load->a->size)
		rotate(load);
	while (load->b->size)
		ps_opr(load, PS_PA);
	top = smallest(load->a);
	if (top < load->a->size / 2 && ++top)
		while (top--)
			ps_opr(load, PS_RRA);
	else
		while (++top != load->a->size)
			ps_opr(load, PS_RA);
	return (0);
}
