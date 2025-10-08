/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:52:30 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/05 12:52:44 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_safe_atoi(const char *str, int *ptr)
{
	char		*end;
	long long	val;

	errno = 0;
	val = ft_strtoll((char *)str, &end, 10);
	if (*end != '\0' || errno == ERANGE || val < INT_MIN || val > INT_MAX)
		return (EXIT_FAILURE);
	*ptr = (int)val;
	return (EXIT_SUCCESS);
}
