/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:28:07 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/13 16:28:08 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>

int	argctl(char *str, int *nbr)
{
	int		i;
	long	ret;

	i = -1;
	while (str[++i])
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
			return (0);
	ret = ft_atol_no_ws(str);
	if (ret < INT_MIN || ret > INT_MAX)
		return (0);
	*nbr = ret;
	return (1);
}

t_stack	*ps_input(char *argv[], int argc)
{
	t_stack	*st;
	int		nbr;
	t_uint	i;
	int		*pt;

	if (!argc || !argv)
		handle_error(NO_ARG, NULL);
	st = malloc(sizeof(t_stack));
	ft_stack_init(st, --argc, sizeof(int));
	while (argc)
	{
		if (!argctl(argv[argc--], &nbr))
			handle_error(INV_ARG, &st);
		i = 0;
		pt = (int *)st->data;
		while (i < st->size)
			if (nbr == pt[i++])
				handle_error(DUP_ARG, &st);
		ft_stack_push(st, &nbr);
	}
	return (st);
}
