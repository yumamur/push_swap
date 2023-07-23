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

int	main(int argc, char *argv[])
{
	t_load	load;

	ps_input(&argv[1], argc - 1, &load);
	if (if_sorted(load.a))
		handle_error(SORTED, &load);
	if (ps_sort(&load))
		(handle_error(SORTED, &load));
	if (if_sorted(load.a))
		write(1, "OK!\n", 4);
	free(load.b->u_data.v);
	ft_stack_destroy(&load.a);
}
