#include "push_swap.h"

char	*ft_get_base(int base)
{
	char	*cbase;
	char	*charset;
	int		i;

	if (base < 2 || base > 36)
		return (NULL);
	charset = "0123456789abcdefghijklmnopqrstuvwxyz";
	cbase = (char *)malloc(sizeof(*cbase) * (base + 1));
	if (!cbase)
		return (NULL);
	i = 0;
	while (charset[i] && i < base)
	{
		cbase[i] = charset[i];
		i++;
	}
	cbase[base] = '\0';
	return (cbase);
}