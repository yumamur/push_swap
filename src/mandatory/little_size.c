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

int	sort_two(t_load *load)
{
	if (load->a->u_data.i[0] < load->a->u_data.i[1])
		ps_opr(load, PS_SA);
	return (0);
}

int	sort_three(t_load *load)
{
	t_uint	small;

	small = smallest(load->a);
	if (small == 2)
		return (ps_opr(load, PS_RRA) || ps_opr(load, PS_SA));
	else if (small == 1)
	{
		if (load->a->u_data.i[0] < load->a->u_data.i[2])
			return (ps_opr(load, PS_RA));
		else
			return (ps_opr(load, PS_SA));
	}
	else if (small == 0)
	{
		if (load->a->u_data.i[1] > load->a->u_data.i[2])
			return (ps_opr(load, PS_RRA));
		else
			return (ps_opr(load, PS_RA) || ps_opr(load, PS_SA));
	}
	return (-1);
}

int	sort_four(t_load *load)
{
	t_uint small;

	small = smallest(load->a);
	if (small == 3)
		return (ps_opr(load, PS_RRA) || ps_opr(load, PS_PB) || sort_three(load)
			|| ps_opr(load, PS_PA));
	else if (small == 2)
		return (ps_opr(load, PS_RRA) || ps_opr(load, PS_RRA)
		|| ps_opr(load, PS_PB) || sort_three(load) || ps_opr(load, PS_PA));
	else if (small == 1)
		return (ps_opr(load, PS_RA) || ps_opr(load, PS_PB) || sort_three(load)
			|| ps_opr(load, PS_PA));
	else
		return (ps_opr(load, PS_PB) || sort_three(load) || ps_opr(load, PS_PA));
}

int	sort_five(t_load *load)
{
	t_uint	small;

	small = smallest(load->a);
	if (small == 4)
		return (ps_opr(load, PS_PB) || sort_four(load)
			|| ps_opr(load, PS_PA));
	else if (small == 3)
		return (ps_opr(load, PS_RA) || ps_opr(load, PS_PB) || sort_four(load)
			|| ps_opr(load, PS_PA));
	else if (small == 2)
		return (ps_opr(load, PS_RA) || ps_opr(load, PS_RA) || ps_opr(load, PS_PB)
			|| sort_four(load) || ps_opr(load, PS_PA));
	else if (small == 1)
		return (ps_opr(load, PS_RRA) || ps_opr(load, PS_RRA) || ps_opr(load, PS_PB)
			|| sort_four(load) || ps_opr(load, PS_PA));
	else if (small == 0)
		return (ps_opr(load, PS_RRA) || ps_opr(load, PS_PB) || sort_four(load)
			|| ps_opr(load, PS_PA));
	return (-1);
}
