/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_opr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:00:49 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/24 21:36:54 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static int	conv_opr2(int *i, char buf[], int *ret)
{
	int	tmp;

	tmp = *i;
	if (!ft_strcmp(buf, "pa\n\0"))
		ret[(*i)++] = PS_PA;
	else if (!ft_strcmp(buf, "pb\n\0"))
		ret[(*i)++] = PS_PB;
	else if (!ft_strcmp(buf, "sa\n\0"))
		ret[(*i)++] = PS_SA;
	else if (!ft_strcmp(buf, "sb\n\0"))
		ret[(*i)++] = PS_SB;
	else if (!ft_strcmp(buf, "ss\n\0"))
		ret[(*i)++] = PS_SS;
	if (tmp == i)
		free(ret);
	else
		return (0);
	return (-1);
}

static int	conv_opr(char buf[], int *ret)
{
	static int	i;
	int			tmp;

	if (!i)
		i = 0;
	tmp = i;
	if (!ft_strcmp(buf, "rra\n"))
		ret[i++] = PS_RRA;
	else if (!ft_strcmp(buf, "rrb\n"))
		ret[i++] = PS_RRB;
	else if (!ft_strcmp(buf, "rrr\n"))
		ret[i++] = PS_RRR;
	else if (!ft_strcmp(buf, "ra\n\0"))
		ret[i++] = PS_RA;
	else if (!ft_strcmp(buf, "rb\n\0"))
		ret[i++] = PS_RB;
	else if (!ft_strcmp(buf, "rr\n\0"))
		ret[i++] = PS_RR;
	if (tmp == i)
		return (conv_opr2(&i, buf, ret));
	else
		return (0);
}

int	*read_opr(t_ch_load *load)
{
	int		*ret;
	char	buf[4];
	int		b_read;

	ret = malloc(MAX_OPR);
	if (!ret)
		handle_error(READ_ERROR, load);
	while (b_read && !ft_strctrl(buf, '\n'))
	{
		(int )buf = 0;
		b_read = read(1, buf, 4);
		if (b_read == -1)
			break ;
		if (conv_opr(buf, ret))
			handle_error(INV_OPR);
	}
	return (ret);
}
