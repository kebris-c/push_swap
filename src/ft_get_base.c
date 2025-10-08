/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:45:58 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/05 20:24:45 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
