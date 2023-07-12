/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:45:54 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/07 16:04:49 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	if_sorted(t_stack *stack)
{
	t_uint	i;

	i = 0;
	while (i < stack->size - 1)
		if ((stack->u_data.i)[i] > (stack->u_data.i)[i + 1])
			i++;
	else
		break ;
	if (i >= stack->size - 1)
		return (-1);
	return (0);
}

int	ps_sort(t_load *load)
{
	if (if_sorted(load->a))
		return (-1);
	if (load->a->size == 5)
		sort_five(load);
	else if (load->a->size == 4)
		sort_four(load);
	else if (load->a->size == 3)
		sort_three(load);
	else if (load->a->size == 3)
		sort_three(load);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_load	load;

	load = ps_input(&argv[1], argc - 1);
	if (ps_sort(&load))
		(handle_error(SORTED, &load));
	if (if_sorted(load.a))
		write(1, "OK!\n", 4);
	free(load.b->u_data.v);
	ft_stack_destroy(&load.a);
}
