#include "../../include/push_swap.h"

t_uint	find_place_a(t_stack *stack, int nbr)
{
	t_uint	ret;
	t_uint	btw;

	ret = 1;
	if (nbr < stack->u_data.i[stack->size - 1]
		&& nbr > stack->u_data.i[0])
		ret = 0;
	else if (nbr > stack->u_data.i[biggest(stack)]
			|| nbr < stack->u_data.i[smallest(stack)])
		ret = stack->size - smallest(stack);
	else
	{
		btw = stack->size - 1;
		while (nbr < stack->u_data.i[btw] || nbr > stack->u_data.i[btw - 2])
		{
			--btw;
			ret++;
		}
	}
	return (ret);
}

t_uint	find_place_b(t_stack *stack, int nbr)
{
	t_uint	ret;
	t_uint	btw;

	ret = 1;
	if (nbr > stack->u_data.i[stack->size - 1]
		&& nbr < stack->u_data.i[0])
		ret = 0;
	else if (nbr > stack->u_data.i[biggest(stack)]
			|| nbr < stack->u_data.i[smallest(stack)])
		ret = stack->size - biggest(stack);
	else
	{
		btw = stack->size - 1;
		while (nbr > stack->u_data.i[btw] || nbr < stack->u_data.i[btw - 2])
		{
			--btw;
			ret++;
		}
	}
	return (ret);
}
