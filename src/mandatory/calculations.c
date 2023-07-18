#include "../../include/push_swap.h"

t_uint	calc_rarb(int mode, t_load *load)
{
	t_uint	ret;
	t_stack	*ptr;

	if (mode == TO_A)
	{
		ptr = load->b;
		ret = find_place_a(load->a, *load->i);
	}
	else
	{
		ptr = load->a;
		ret = find_place_b(load->b, *load->i);
	}
	if (ret < (t_uint )((&ptr->u_data.i[ptr->size - 1] - load->i) / 4))
		ret = (t_uint )((&ptr->u_data.i[ptr->size - 1] - load->i) / 4);
	return (ret);
}

t_uint	calc_rrarrb(int mode, t_load *load)
{
	t_uint	ret;
	t_stack	*ptr;

	if (mode == TO_A)
	{
		ptr = load->b;
		ret = find_place_a(load->a, *load->i);
	}
	else
	{
		ptr = load->a;
		ret = find_place_b(load->b, *load->i);
	}
	if (ret < (t_uint )((load->i - ptr->u_data.i) / 4) + 1)
		ret = (t_uint )((load->i - ptr->u_data.i) / 4) + 1;
	return (ret);
}

t_uint	calc_rarrb(int mode, t_load *load)
{
	t_uint	ret;

	if (mode == TO_A)
	{
		if (load->i != &load->b->u_data.i[load->b->size - 1])
			ret = (t_uint )((load->i - load->b->u_data.i) / 4) + 1;
		return (ret + find_place_a(load->a, *load->i));
	}
	else
	{
		ret = find_place_b(load->b, *load->i);
		if (ret)
			ret = (load->b->size - 1) - ret;
		return (ret + (t_uint )((load->i - load->a->u_data.i) / 4));
	}
}

t_uint	calc_rrarb(int mode, t_load *load)
{
	t_uint	ret;

	if (mode == TO_A)
	{
		ret = find_place_a(load->a, *load->i);
		if (ret)
			ret = (load->a->size - 1) - ret;
		return (ret + (t_uint )((load->i - load->b->u_data.i) / 4));
	}
	else
	{
		if (load->i != &load->a->u_data.i[load->a->size - 1])
			ret = (t_uint )((load->i - load->a->u_data.i) / 4) + 1;
		return (ret + find_place_b(load->b, *load->i));
	}
}
