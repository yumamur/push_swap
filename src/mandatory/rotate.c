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

static int	assign_func(t_load *load, void (*ptr)(int, t_load *))
{
	if (!ptr)
		handle_error(OPR_ERROR, load);
	load->func = ptr;
	load->nbr = load->ptr[load->i];
	return (0);
}

void	rotate(int mode, t_load *load)
{
	t_uint	calc;

	if (mode)
		load->ptr = load->b->u_data.i;
	else
		load->ptr = load->a->u_data.i;
	load->ctl = INT_MAX;
	load->i = 0;
	while ((mode && load->i < load->b->size) || (!mode && load->i < load->a->size))
	{
		calc = calc_rrarrb(mode, load);
		if (load->ctl > calc && !assign_func(load, &apply_rrarrb))
			load->ctl = calc;
		calc = calc_rrarb(mode, load);
		if (load->ctl > calc && !assign_func(load, &apply_rrarb))
			load->ctl = calc;
		calc = calc_rarrb(mode, load);
		if (load->ctl > calc && !assign_func(load, &apply_rarrb))
			load->ctl = calc;
		calc = calc_rarb(mode, load);
		if (load->ctl > calc && !assign_func(load, &apply_rarb))
			load->ctl = calc;
		load->i++;
	}
}
