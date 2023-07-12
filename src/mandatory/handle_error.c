/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:22:29 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/07 01:54:41 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	handle_error(int err, t_load *load)
{
	if (err == MEM_ERROR)
		write(2, "Malloc error.\n", 13);
	if (err == NO_ARG)
		write(2, "No argument is provided.\n", 25);
	ft_stack_destroy(&load->a);
	ft_stack_destroy(&load->b);
	if (err == INV_ARG)
		write(2, "Invalid argument.\n", 18);
	else if (err == DUP_ARG)
		write(2, "Two or more arguments have equal values.\n", 41);
	exit(0);
}
