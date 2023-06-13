/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:21:53 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/13 16:21:56 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef PS_ERRORS
#  define PS_ERRORS

#  define NO_ARG 1
#  define DUP_ARG 2
#  define INV_ARG 3
# endif /* PS_ERRORS */

# include "libft/stackft.h"
# include "libft/libft.h"

void	handle_error(int errno, t_stack **stack);
t_stack	*ps_input(char *argv[], int argc);
#endif /* PS_ERRORS */
