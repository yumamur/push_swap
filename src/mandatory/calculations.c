/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:42:46 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/20 18:42:46 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_uint	calc_rarb(int mode, t_load *load)
{
	t_uint	ret;
	t_stack	*ptr;

	ret = 0;
	if (mode == TO_A)
	{
		ptr = load->b;
		if (find_place_a(load->a, load->ptr[load->i]))
			ret = load->a->size - find_place_a(load->a, load->ptr[load->i]);
	}
	else
	{
		ptr = load->a;
		if (find_place_b(load->b, load->ptr[load->i]))
			ret = load->b->size - find_place_b(load->b, load->ptr[load->i]);
	}
	if (load->i != ptr->size - 1
		&& ret < ptr->size - load->i)
		return (ptr->size - 1 - load->i);
	return (ret);
}

t_uint	calc_rarrb(int mode, t_load *load)
{
	t_uint	ret;

	ret = 0;
	if (mode == TO_A)
	{
		if (load->i != load->b->size - 1)
			ret = load->i;
		if (find_place_a(load->a, load->ptr[load->i]))
			ret += load->a->size - find_place_a(load->a, load->ptr[load->i]);
		return (ret);
	}
	else
	{
		ret = find_place_b(load->b, load->ptr[load->i]);
		if (load->i != load->a->size - 1)
			ret += load->a->size - 1 - load->i;
		return (ret);
	}
}

t_uint	calc_rrarb(int mode, t_load *load)
{
	t_uint	ret;

	ret = 0;
	if (mode == TO_A)
	{
		ret = find_place_a(load->a, load->ptr[load->i]);
		if (load->i != load->b->size - 1)
			ret += load->b->size - 1 - load->i;
		return (ret);
	}
	else
	{
		if (load->i != load->a->size - 1)
			ret = load->i;
		if (find_place_b(load->b, load->ptr[load->i]))
			ret += load->b->size - find_place_b(load->b, load->ptr[load->i]);
		return (ret);
	}
}

t_uint	calc_rrarrb(int mode, t_load *load)
{
	t_uint	ret;
	t_stack	*ptr;

	if (mode == TO_A)
	{
		ptr = load->b;
		ret = find_place_a(load->a, load->ptr[load->i]);
	}
	else
	{
		ptr = load->a;
		ret = find_place_b(load->b, load->ptr[load->i]);
	}
	if (load->i != ptr->size - 1
		&& ret < load->i)
		ret = load->i;
	return (ret);
}
