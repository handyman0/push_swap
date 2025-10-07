#include "../include/push_swap.h"

/* 
	1 - essa funcão classifica as pilhas
	2 - ela pega os numeros que esta entre aspas
		por ordem ele coloca um identificador em cada numero
	3 - separa cada um identificando como um inteiro
*/
t_stack *ft_sub_process(char **argv)
{
	t_stack *a;
	char **tmp;
	int i;
	int j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi(tmp[i])
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_freestr(tmp);
	return(a);
}

/* 
Essa função faz tres coisas:
	1 - Checa se o numero de argumentos é menor que 2
	2 - Checa se o numero de argumentos é igual a 2
		se for, isso signfica que é uma string.
		e chama outra função de sub_process
	3 - Se for maior que 2
		ela lista os argumentos
*/
t_stack *ft_process(int argc, char **argv)
{
	t_stack *a;
	int i;
	int j;

	i = 1;
	a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi(argv[i]);
			ft_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}