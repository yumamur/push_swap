#include "../../include/push_swap.h"

int	ps_sort(t_load *load)
{
	if (if_sorted(load->a))
		return (-1);
	if (load->a->size == 2)
		return (ps_opr(load, (int []){1, PS_SA}));
	if (load->a->size > 3 && if_sorted(load->a))
	{
		ps_opr(load, (int []){2, PS_PB, PS_PB});
		while (load->a->size > 3 && if_sorted(load->a))
		{
			rotate(TO_B, load);
			load->func(TO_B, load);
		}
	}
	if (load->a->size == 3)
		sort_three(load);
	while (load->b->size)
	{
		load->i = 0;
		rotate(TO_A, load);
		load->func(TO_A, load);
	}
	return (0);
}
