/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_calculations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:42:37 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/20 18:42:38 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	apply_rarb(t_load *load)
{
	t_uint	place;

	place = find_place_b(load->b, load->nbr);
	while (load->a->u_data.i[load->a->size - 1] != load->nbr
		&& place++ < load->b->size - 1)
		ps_opr(load, PS_RR);
	while (load->a->u_data.i[load->a->size - 1] != load->nbr)
		ps_opr(load, PS_RA);
	while (place++ < load->b->size - 1)
		ps_opr(load, PS_RB);
	ps_opr(load, PS_PB);
	load->func = NULL;
}

void	apply_rrarb(t_load *load)
{
	t_uint	place;
	while (load->a->u_data.i[load->a->size - 1] != load->nbr)
		ps_opr(load, PS_RRA);
	while (find_place_b(load->b, load->nbr))
		ps_opr(load, PS_RB);
	ps_opr(load, PS_PB);
	load->func = NULL;
}

void	apply_rarrb(t_load *load)
{
	while (load->a->u_data.i[load->a->size - 1] != load->nbr)
		ps_opr(load, PS_RA);
	while (find_place_b(load->b, load->nbr))
		ps_opr(load, PS_RRB);
	ps_opr(load, PS_PB);
	load->func = NULL;
}

void	apply_rrarrb(t_load *load)
{
	while (load->a->u_data.i[load->a->size - 1] != load->nbr
		&& find_place_b(load->b, load->nbr))
		ps_opr(load, PS_RRR);
	while (load->a->u_data.i[load->a->size - 1] != load->nbr)
		ps_opr(load, PS_RRA);
	while (find_place_b(load->b, load->nbr))
		ps_opr(load, PS_RRB);
	ps_opr(load, PS_PB);
	load->func = NULL;
}
