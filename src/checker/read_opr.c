/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_opr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:00:49 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/24 21:47:17 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static int	conv_opr2(int *i, char buf[], int *ret)
{
	int	tmp;

	tmp = *i;
	if (!ft_memcmp(buf, "rr\n\0", 4))
		ret[++(*i)] = PS_RR;
	else if (!ft_memcmp(buf, "pa\n\0", 4))
		ret[(++*i)] = PS_PA;
	else if (!ft_memcmp(buf, "pb\n\0", 4))
		ret[++(*i)] = PS_PB;
	else if (!ft_memcmp(buf, "sa\n\0", 4))
		ret[++(*i)] = PS_SA;
	else if (!ft_memcmp(buf, "sb\n\0", 4))
		ret[++(*i)] = PS_SB;
	else if (!ft_memcmp(buf, "ss\n\0", 4))
		ret[++(*i)] = PS_SS;
	if (tmp == *i)
		free(ret);
	else
	{
		ret[0] = *i;
		return (0);
	}
	return (-1);
}

static int	conv_opr(char buf[], int *ret)
{
	static int	i;
	int			tmp;

	if (!i)
		i = 0;
	tmp = i;
	if (*buf == 0)
		return (1);
	else if (!ft_memcmp(buf, "rra\n", 4))
		ret[++i] = PS_RRA;
	else if (!ft_memcmp(buf, "rrb\n", 4))
		ret[++i] = PS_RRB;
	else if (!ft_memcmp(buf, "rrr\n", 4))
		ret[++i] = PS_RRR;
	else if (!ft_memcmp(buf, "ra\n\0", 4))
		ret[++i] = PS_RA;
	else if (!ft_memcmp(buf, "rb\n\0", 4))
		ret[++i] = PS_RB;
	if (tmp == i)
		return (conv_opr2(&i, buf, ret));
	else
	{
		ret[0] = i;
		return (0);
	}
}

int	*read_opr(t_ch_load *load)
{
	int		*ret;
	char	buf[4];
	int		b_read;
	int		ctl_conv;

	ret = malloc(500 * 4);
	if (!ret)
		handle_error(READ_ERROR, load);
	b_read = 1;
	while (b_read)
	{
		*(int *)&buf = 0;
		b_read = read(0, buf, 4);
		if (b_read == -1)
			break ;
		ctl_conv = conv_opr(buf, ret);
		if (ctl_conv == -1)
			handle_error(INV_OPR, load);
		else if (ctl_conv == 1)
			break ;
	}
	return (ret);
}
