#include "push_swap.h"

int	ft_base_pos(char nb, char *base)
{
    int	pos;

    pos = 0;
    while (base[pos])
    {
        if (nb == base[pos])
            return (pos);
        pos++;
    }
    return (-1);
}