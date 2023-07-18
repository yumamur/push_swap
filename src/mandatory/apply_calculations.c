#include "../../include/push_swap.h"

void	apply_rarb(int mode, t_load *load)
{
	if (mode)
	{
		load->nbr = *load->i;
		while (load->b->u_data.i[load->b->size - 1] != load->nbr
			&& find_place_a(load->a, load->nbr))
			ps_opr(load, (int []){1, PS_RR});
		while (load->b->u_data.i[load->b->size - 1] != load->nbr)
			ps_opr(load, (int []){1, PS_RB});
		while (find_place_a(load->a, load->nbr))
			ps_opr(load, (int []){1, PS_RA});
	}
	else
	{
		load->nbr = *load->i;
		while (load->a->u_data.i[load->a->size - 1] != load->nbr
			&& find_place_b(load->b, load->nbr))
			ps_opr(load, (int []){1, PS_RR});
		while (load->a->u_data.i[load->a->size - 1] != load->nbr)
			ps_opr(load, (int []){1, PS_RA});
		while (find_place_b(load->b, load->nbr))
			ps_opr(load, (int []){1, PS_RB});
	}
	ps_opr(load, (int []){1, PS_PB + mode});
	load->func = NULL;
}

void	apply_rrarb(int mode, t_load *load)
{
	if (mode)
	{
		load->nbr = *load->i;
		while (load->b->u_data.i[load->b->size - 1] != load->nbr)
			ps_opr(load, (int []){1, PS_RB});
		while (find_place_a(load->a, load->nbr))
			ps_opr(load, (int []){1, PS_RRA});
	}
	else
	{
		load->nbr = *load->i;
		while (load->a->u_data.i[load->a->size - 1] != load->nbr)
			ps_opr(load, (int []){1, PS_RRA});
		while (find_place_b(load->b, load->nbr))
			ps_opr(load, (int []){1, PS_RB});
	}
	ps_opr(load, (int []){1, PS_PB + mode});
	load->func = NULL;
}

void	apply_rarrb(int mode, t_load *load)
{
	if (mode)
	{
		load->nbr = *load->i;
		while (load->b->u_data.i[load->b->size - 1] != load->nbr)
			ps_opr(load, (int []){1, PS_RRB});
		while (find_place_a(load->a, load->nbr))
			ps_opr(load, (int []){1, PS_RA});
	}
	else
	{
		load->nbr = *load->i;
		while (load->a->u_data.i[load->a->size - 1] != load->nbr)
			ps_opr(load, (int []){1, PS_RA});
		while (find_place_b(load->b, load->nbr))
			ps_opr(load, (int []){1, PS_RRB});
	}
	ps_opr(load, (int []){1, PS_PB + mode});
	load->func = NULL;
}

void	apply_rrarrb(int mode, t_load *load)
{
	if (mode)
	{
		load->nbr = *load->i;
		while (load->b->u_data.i[load->b->size - 1] != load->nbr
			&& find_place_a(load->a, load->nbr))
			ps_opr(load, (int []){1, PS_RRR});
		while (load->b->u_data.i[load->b->size - 1] != load->nbr)
			ps_opr(load, (int []){1, PS_RRB});
		while (find_place_a(load->a, load->nbr))
			ps_opr(load, (int []){1, PS_RRA});
	}
	else
	{
		load->nbr = *load->i;
		while (load->a->u_data.i[load->a->size - 1] != load->nbr
			&& find_place_b(load->b, load->nbr))
			ps_opr(load, (int []){1, PS_RRR});
		while (load->a->u_data.i[load->a->size - 1] != load->nbr)
			ps_opr(load, (int []){1, PS_RRA});
		while (find_place_b(load->b, load->nbr))
			ps_opr(load, (int []){1, PS_RRB});
	}
	ps_opr(load, (int []){1, PS_PB + mode});
	load->func = NULL;
}