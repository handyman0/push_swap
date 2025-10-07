#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;

    a = ft_process(argc, argv);
    if (!a || ft_checkdup(a)); /* to create */
    {
        ft_free(&a);
        ft_error();
    }
    if (!ft_checksorted(a)) /* to create */
        ft_sort(&a); /* to create */
    ft_free(&a);
    return (0);
}