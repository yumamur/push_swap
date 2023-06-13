/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:45:54 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/13 18:45:55 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = ps_input(argv, argc);
	ft_putmem_fd(1, stack_a->data, (argc - 1) * 4, "\n");
	ft_stack_destroy(&stack_a);
}
