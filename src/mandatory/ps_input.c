/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:28:07 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/07 01:44:43 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	atol_no_ws(t_c_char *str, long *ptr)
{
	long	ret;
	t_uint	i;
	char	sign;

	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = (str[i] - 48) + (ret * 10);
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	*ptr = ret * sign;
	return (0);
}

int	argctl(char *str, int *nbr)
{
	long	ret;

	if (atol_no_ws(str, &ret))
		return (-1);
	if (ret < INT_MIN || ret > INT_MAX)
		return (-1);
	*nbr = ret;
	return (0);
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
	ft_stack_init(st, argc, sizeof(int));
	while (argc)
	{
		if (argctl(argv[--argc], &nbr))
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
