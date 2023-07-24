/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:39:38 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/24 21:45:47 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

int	main(int argc, char *argv[])
{
	t_ch_load	load;
	int			*oprs;

	ch_input(&argv[1], argc - 1, &load);
	oprs = read_opr(&load);
	ch_opr(&load, oprs);
	if (if_sorted(load.a))
		write(1, "OK!\n", 4);
	else
		write(1, "KO!\n", 4);
	free(oprs);
	free(load.b->u_data.v);
	ft_stack_destroy(&load.a);
}
