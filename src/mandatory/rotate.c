/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:43:35 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/20 18:43:36 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	assign_func(t_load *load, void (*ptr)(t_load *))
{
	if (!ptr)
		handle_error(OPR_ERROR, load);
	load->func = ptr;
	load->nbr = load->ptr[load->i];
	return (0);
}

void	rotate(t_load *load)
{
	load->ptr = load->a->u_data.i;
	load->ctl = INT_MAX;
	load->i = 0;
	while (load->i < load->a->size)
	{
		load->calc = calc_rrarrb(load);
		if (load->ctl > load->calc && !assign_func(load, &apply_rrarrb))
			load->ctl = load->calc;
		load->calc = calc_rrarb(load);
		if (load->ctl > load->calc && !assign_func(load, &apply_rrarb))
			load->ctl = load->calc;
		load->calc = calc_rarrb(load);
		if (load->ctl > load->calc && !assign_func(load, &apply_rarrb))
			load->ctl = load->calc;
		load->calc = calc_rarb(load);
		if (load->ctl > load->calc && !assign_func(load, &apply_rarb))
			load->ctl = load->calc;
		load->i++;
	}
	load->func(load);
}
