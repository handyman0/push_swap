#include "../include/push_swap.h"

/* 
	Enquanto o argumentos são validos, adiciona os números na stack_a
	começando do índice 1 até o final dos argumentos.
	atoi pega o valor do argumento e converte para inteiro.
	o valor onde nos podemos fazer operações matematicas
	com uma pilha nova nos criamos um novo nó com o valor
	argumento sem juntar nas listas
	nos juntamos em ft_add_back
*/
int ft_list_args(char **argv, t_stack **stack_a)
{
	long	i;

	i = 1;
	while (argv[i] != NULL)
	{
		ft_add_back(stack_a, ft_stack_new(ft_atoi(argv[i])));
		i++;
	}
}