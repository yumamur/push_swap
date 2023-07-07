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

int	ps_sort(t_stack *stack_a)
{
	t_uint	i;

	i = 0;
	while (i < stack_a->size - 1)
		if (((int *)stack_a->data)[i] > ((int *)stack_a->data)[i + 1])
			i++;
	else
		break ;
	if (i >= stack_a->size - 1)
		return (-1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = ps_input(&argv[1], argc - 1);
	if (ps_sort(stack_a))
		(handle_error(SORTED, &stack_a));
	ft_putmem_fd(1, stack_a->data, (argc - 1) * 4, "\n");
	ft_stack_destroy(&stack_a);
}
