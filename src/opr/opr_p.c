/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:47:05 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/06 13:18:25 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	opr_pa(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_stack_push(stack_a, ft_stack_pop(stack_b)))
		return (-1);
	return (0);
}
