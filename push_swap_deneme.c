#include "../push_swap/include/push_swap.h"

int main(int ac, char *av[])
{
	t_load load;

	ps_input(&av[1], ac - 1, &load);
	ps_opr(&load, PS_PB);
	ps_opr(&load, PS_PB);
	ps_opr(&load, PS_PB);
	ps_opr(&load, PS_PB);
	ps_opr(&load, PS_PB);
	printf("a.cap = %u   b.cap = %u\n", load.a->cap, load.b->cap);
	printf("    ST A  ST B\t\tA\tB\n\n");
	printf("0-> %i	  %i\t|\t0-> %i\t%i\n", load.a->u_data.i[0], load.b->u_data.i[0], load.a->u_data.i[4], load.b->u_data.i[4]);
	printf("1-> %i	  %i\t|\t1-> %i\t%i\n", load.a->u_data.i[1], load.b->u_data.i[1], load.a->u_data.i[3], load.b->u_data.i[3]);
	printf("2-> %i	  %i\t|\t2-> %i\t%i\n", load.a->u_data.i[2], load.b->u_data.i[2], load.a->u_data.i[2], load.b->u_data.i[2]);
	printf("3-> %i	  %i\t|\t3-> %i\t%i\n", load.a->u_data.i[3], load.b->u_data.i[3], load.a->u_data.i[1], load.b->u_data.i[1]);
	printf("4-> %i	  %i\t|\t4-> %i\t%i\n", load.a->u_data.i[4], load.b->u_data.i[4], load.a->u_data.i[0], load.b->u_data.i[0]);
	load.i = &load.a->u_data.i[4];
	printf("\n*load.i = %i\n", *load.i);
	printf("place is %u\n", find_place_b(load.b, *load.i));
	printf("rarb   %u\n", calc_rarb(TO_B, &load));
	printf("rrarrb %u\n", calc_rrarrb(TO_B, &load));
	printf("rarrb  %u\n", calc_rarrb(TO_B, &load));
	printf("rrarb  %u\n", calc_rrarb(TO_B, &load));
	load.i = &load.a->u_data.i[3];
	printf("\n*load.i = %i\n", *load.i);
	printf("place is %u\n", find_place_b(load.b, *load.i));
	printf("rarb   %u\n", calc_rarb(TO_B, &load));
	printf("rrarrb %u\n", calc_rrarrb(TO_B, &load));
	printf("rarrb  %u\n", calc_rarrb(TO_B, &load));
	printf("rrarb  %u\n", calc_rrarb(TO_B, &load));
	load.i = &load.a->u_data.i[2];
	printf("\n*load.i = %i\n", *load.i);
	printf("place is %u\n", find_place_b(load.b, *load.i));
	printf("rarb   %u\n", calc_rarb(TO_B, &load));
	printf("rrarrb %u\n", calc_rrarrb(TO_B, &load));
	printf("rarrb  %u\n", calc_rarrb(TO_B, &load));
	printf("rrarb  %u\n", calc_rrarb(TO_B, &load));
	load.i = &load.a->u_data.i[1];
	printf("\n*load.i = %i\n", *load.i);
	printf("place is %u\n", find_place_b(load.b, *load.i));
	printf("rarb   %u\n", calc_rarb(TO_B, &load));
	printf("rrarrb %u\n", calc_rrarrb(TO_B, &load));
	printf("rarrb  %u\n", calc_rarrb(TO_B, &load));
	printf("rrarb  %u\n", calc_rrarb(TO_B, &load));
	load.i = &load.a->u_data.i[0];
	printf("\n*load.i = %i\n", *load.i);
	printf("place is %u\n", find_place_b(load.b, *load.i));
	printf("rarb   %u\n", calc_rarb(TO_B, &load));
	printf("rrarrb %u\n", calc_rrarrb(TO_B, &load));
	printf("rarrb  %u\n", calc_rarrb(TO_B, &load));
	printf("rrarb  %u\n", calc_rrarb(TO_B, &load));
}
