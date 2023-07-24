/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:42:46 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/24 18:42:28 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_uint	find_place_b(t_stack *stack, int nbr)
{
	t_uint	btw;

	if (nbr > stack->u_data.i[stack->size - 1]
		&& nbr < stack->u_data.i[0])
		return (0);
	else if (nbr > stack->u_data.i[biggest(stack)]
		|| nbr < stack->u_data.i[smallest(stack)])
		return (smallest(stack));
	else
	{
		btw = stack->size - 1;
		while (btw
			&& !(nbr < stack->u_data.i[btw] && nbr > stack->u_data.i[btw - 1]))
			--btw;
		return (btw);
	}
}

t_uint	calc_rarb(t_load *load)
{
	t_uint	ret;
	t_uint	place;

	place = find_place_b(load->b, load->ptr[load->i]);
	ret = 0;
	if (place)
		ret = load->b->size - place;
	if (load->i != load->a->size - 1
		&& ret < load->a->size - load->i)
		return (load->a->size - 1 - load->i);
	return (ret);
}

t_uint	calc_rarrb(t_load *load)
{
	t_uint	ret;

	ret = find_place_b(load->b, load->ptr[load->i]);
	if (load->i != load->a->size - 1)
		ret += load->a->size - 1 - load->i;
	return (ret);
}

t_uint	calc_rrarb(t_load *load)
{
	t_uint	ret;
	t_uint	place;

	ret = 0;
	place = find_place_b(load->b, load->ptr[load->i]);
	if (load->i != load->a->size - 1)
		ret = load->i;
	if (place)
		ret += load->b->size - place;
	return (ret);
}

t_uint	calc_rrarrb(t_load *load)
{
	t_uint	ret;

	ret = find_place_b(load->b, load->ptr[load->i]);
	if (load->i != load->a->size - 1
		&& ret < load->i)
		ret = load->i;
	return (ret);
}
