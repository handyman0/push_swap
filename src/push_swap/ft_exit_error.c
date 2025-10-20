#include "../../include/push_swap.h"

static void	ft_free_all(t_stack **a, t_stack **b, char **tmp)
{
	if (tmp)
		ft_free_str_array(tmp);
	if (a)
		ft_free(a);
	if (b)
		ft_free(b);
}

void	ft_exit_error(t_stack **a, t_stack **b, char **tmp)
{
	ft_free_all(a, b, tmp);
	ft_error();
}
