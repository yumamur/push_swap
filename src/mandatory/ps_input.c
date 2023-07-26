/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:28:07 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/24 20:55:38 by yumamur          ###   ########.fr       */
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
	if (str[i] == '-' && ++i)
		sign *= -1;
	if (str[i] == 0)
		return (-1);
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

static int	argctl(char *str, int *nbr)
{
	long	ret;

	if (atol_no_ws(str, &ret))
		return (-1);
	if (ret < INT_MIN || ret > INT_MAX)
		return (-1);
	*nbr = ret;
	return (0);
}

static void	load_init(t_load *load, int size)
{
	if (!load || !size)
		handle_error(NO_ARG, NULL);
	load->a = ft_calloc(sizeof(t_stack), 2);
	if (!load->a)
		handle_error(MALLOC_ERROR, NULL);
	load->b = &load->a[1];
	if (ft_stack_init(load->a, size, sizeof(int)))
	{
		free(load->a);
		handle_error(MALLOC_ERROR, NULL);
	}
	if (ft_stack_init(load->b, size, sizeof(int)))
	{
		ft_stack_destroy(&load->a);
		handle_error(MALLOC_ERROR, NULL);
	}
}

static int	count_arg(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	ps_input(char *argv[], int argc, t_load *load)
{
	int		nbr;
	t_uint	i;
	t_c_int	*pt;

	if (!argc || !argv)
		handle_error(NO_ARG, NULL);
	load->args = argv;
	if (argc == 1)
	{
		load->args = ft_split(*argv, 32);
		load->ctl_args = 1;
	}
	argc = count_arg(load->args);
	load_init(load, argc);
	pt = load->a->u_data.i;
	while (argc--)
	{
		if (argctl(load->args[argc], &nbr))
			handle_error(INV_ARG, load);
		i = 0;
		while (i < load->a->size)
			if (nbr == pt[i++])
				handle_error(DUP_ARG, load);
		ft_stack_push(load->a, &nbr);
	}
}
