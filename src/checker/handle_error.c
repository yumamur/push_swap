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

#include "../../include/checker.h"

void	free_load(t_ch_load *load)
{
	if (load->b->u_data.v)
		free(load->b->u_data.v);
	if (load->b)
		free(load->b);
	if (load->a->u_data.v)
		free(load->a->u_data.v);
	if (load->a)
		free(load->a);
}

static int	puterror(char *str, int errno)
{
	ft_putstr_fd(2, str);
	return (errno);
}

void	handle_error(int err, t_ch_load *load)
{
	free_load(load);
	if (err == MALLOC_ERROR)
		exit(puterror("Malloc error.\n", 1));
	else if (err == READ_ERROR)
		exit(puterror("Read error.\n", 1));
	else if (err == NO_ARG)
		exit(puterror("No argument is provided.\n", 127));
	else if (err == DUP_ARG)
		exit(puterror("Two or more arguments have equal values.\n", 127));
	else if (err == INV_ARG)
		exit(puterror("Invalid argument.\n", 127));
	else if (err == INV_OPR)
		exit(puterror("Invalid operation.\n", 127));
	else if (err == OPR_ERROR)
		exit(puterror("Operation is not possible.\n", 127));
	exit(0);
}
