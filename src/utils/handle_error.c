/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:22:29 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/13 17:22:36 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	handle_error(int err, t_stack **st)
{
	ft_stack_destroy(st);
	if (err == NO_ARG)
		exit(EXIT_FAILURE);
	if (err == DUP_ARG)
		exit(127);
	exit(0);
}
