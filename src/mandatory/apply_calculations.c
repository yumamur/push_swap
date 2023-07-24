/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_calculations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:42:37 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/24 19:44:35 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	apply_rarb(t_load *load)
{
	t_uint	place;

	place = load->b->size - find_place_b(load->b, load->nbr);
	while (load->a->u_data.i[load->a->size - 1] != load->nbr
		&& place)
	{
		ps_opr(load, PS_RR);
		--place;
	}
	while (load->a->u_data.i[load->a->size - 1] != load->nbr)
		ps_opr(load, PS_RA);
	while (place)
	{
		ps_opr(load, PS_RB);
		--place;
	}
	ps_opr(load, PS_PB);
	load->func = NULL;
}

void	apply_rrarb(t_load *load)
{
	t_uint	place;

	while (load->a->u_data.i[load->a->size - 1] != load->nbr)
		ps_opr(load, PS_RRA);
	place = load->b->size - find_place_b(load->b, load->nbr);
	while (place--)
		ps_opr(load, PS_RB);
	ps_opr(load, PS_PB);
	load->func = NULL;
}

void	apply_rarrb(t_load *load)
{
	t_uint	place;

	place = find_place_b(load->b, load->nbr);
	while (load->a->u_data.i[load->a->size - 1] != load->nbr)
		ps_opr(load, PS_RA);
	while (place--)
		ps_opr(load, PS_RRB);
	ps_opr(load, PS_PB);
	load->func = NULL;
}

void	apply_rrarrb(t_load *load)
{
	t_uint	place;

	place = find_place_b(load->b, load->nbr);
	while (load->a->u_data.i[load->a->size - 1] != load->nbr
		&& place)
	{
		ps_opr(load, PS_RRR);
		place--;
	}
	while (load->a->u_data.i[load->a->size - 1] != load->nbr)
		ps_opr(load, PS_RRA);
	while (place)
	{
		ps_opr(load, PS_RRB);
		place--;
	}
	ps_opr(load, PS_PB);
	load->func = NULL;
}
