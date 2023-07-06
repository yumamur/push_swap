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

void	handle_error(int err, t_stack **st)
{
	if (err == NO_ARG)
		write(2, "No argument is provided.", 24);
	ft_stack_destroy(st);
	if (err == INV_ARG)
		write(2, "Invalid argument.", 17);
	else if (err == DUP_ARG)
		write(2, "Two or more arguments have equal values.", 40);
	exit(0);
}
