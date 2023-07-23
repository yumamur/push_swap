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

void	apply_rarb(int mode, t_load *load)
{
	if (mode)
	{
		while (load->b->u_data.i[load->b->size - 1] != load->nbr
			&& find_place_a(load->a, load->nbr))
			ps_opr(load, PS_RR);
		while (load->b->u_data.i[load->b->size - 1] != load->nbr)
			ps_opr(load, PS_RB);
		while (find_place_a(load->a, load->nbr))
			ps_opr(load, PS_RA);
	}
	else
	{
		while (load->a->u_data.i[load->a->size - 1] != load->nbr
			&& find_place_b(load->b, load->nbr))
			ps_opr(load, PS_RR);
		while (load->a->u_data.i[load->a->size - 1] != load->nbr)
			ps_opr(load, PS_RA);
		while (find_place_b(load->b, load->nbr))
			ps_opr(load, PS_RB);
	}
	ps_opr(load, PS_PB + mode);
	load->func = NULL;
}

void	apply_rrarb(int mode, t_load *load)
{
	if (mode)
	{
		while (load->b->u_data.i[load->b->size - 1] != load->nbr)
			ps_opr(load, PS_RB);
		while (find_place_a(load->a, load->nbr))
			ps_opr(load, PS_RRA);
	}
	else
	{
		while (load->a->u_data.i[load->a->size - 1] != load->nbr)
			ps_opr(load, PS_RRA);
		while (find_place_b(load->b, load->nbr))
			ps_opr(load, PS_RB);
	}
	ps_opr(load, PS_PB + mode);
	load->func = NULL;
}

void	apply_rarrb(int mode, t_load *load)
{
	if (mode)
	{
		while (load->b->u_data.i[load->b->size - 1] != load->nbr)
			ps_opr(load, PS_RRB);
		while (find_place_a(load->a, load->nbr))
			ps_opr(load, PS_RA);
	}
	else
	{
		while (load->a->u_data.i[load->a->size - 1] != load->nbr)
			ps_opr(load, PS_RA);
		while (find_place_b(load->b, load->nbr))
			ps_opr(load, PS_RRB);
	}
	ps_opr(load, PS_PB + mode);
	load->func = NULL;
}

void	apply_rrarrb(int mode, t_load *load)
{
	if (mode)
	{
		while (load->b->u_data.i[load->b->size - 1] != load->nbr
			&& find_place_a(load->a, load->nbr))
			ps_opr(load, PS_RRR);
		while (load->b->u_data.i[load->b->size - 1] != load->nbr)
			ps_opr(load, PS_RRB);
		while (find_place_a(load->a, load->nbr))
			ps_opr(load, PS_RRA);
	}
	else
	{
		while (load->a->u_data.i[load->a->size - 1] != load->nbr
			&& find_place_b(load->b, load->nbr))
			ps_opr(load, PS_RRR);
		while (load->a->u_data.i[load->a->size - 1] != load->nbr)
			ps_opr(load, PS_RRA);
		while (find_place_b(load->b, load->nbr))
			ps_opr(load, PS_RRB);
	}
	ps_opr(load, PS_PB + mode);
	load->func = NULL;
}
