#include "../../include/push_swap.h"

static int	assign_func(t_load *load, void (*ptr)(int, t_load *))
{
	load->func = ptr;
	return (0);
}

void	rotate(int mode, t_load *load)
{
	t_uint	calc;

	if (mode)
		load->i = &load->a->u_data.i[load->a->size];
	else
		load->i = &load->b->u_data.i[load->b->size];
	load->ctl = INT_MAX;
	while (--load->i != load->a->u_data.v && load->i != load->b->u_data.v)
	{
		calc = calc_rrarrb(mode, load);
		if (load->ctl > calc && !assign_func(load, apply_rrarrb))
			load->ctl = calc;
		calc = calc_rrarb(mode, load);
		if (load->ctl > calc && !assign_func(load, apply_rrarb))
			load->ctl = calc;
		calc = calc_rarrb(mode, load);
		if (load->ctl > calc && !assign_func(load, apply_rarrb))
			load->ctl = calc;
		calc = calc_rarb(mode, load);
		if (load->ctl > calc && !assign_func(load, apply_rarb))
			load->ctl = calc;
	}
}
