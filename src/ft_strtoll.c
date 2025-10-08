/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:07:17 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/05 21:14:54 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	skip_isspace_set_sign(char *nptr, size_t *i)
{
	long long	sign;

	sign = 1;
	while (nptr[(*i)] == ' ' || (nptr[(*i)] >= 9 && nptr[(*i)] <= 13))
		(*i)++;
	if (nptr[(*i)] == '-')
	{
		sign *= -1;
		(*i)++;
	}
	else if (nptr[(*i)] == '+')
		(*i)++;
	return (sign);
}

static size_t	case_base_zero(char *nptr, int *base)
{
	size_t	i;

	i = 0;
	if (nptr[i] == '0')
	{
		if (nptr[i + 1] == 'x' || nptr[i + 1] == 'X')
		{
			(*base) = 16;
			i += 2;
		}
		else
		{
			(*base) = 8;
			i += 1;
		}
	}
	else
		(*base) = 10;
	return (i);
}

static long long	main_loop(char *nptr, size_t *i, long long sign, int base)
{
	int			digit;
	char		*cbase;
	long long	result;

	cbase = ft_get_base(base);
	result = 0;
	while (nptr[(*i)])
	{
		digit = ft_base_pos(nptr[(*i)++], cbase);
		if (digit == -1)
			break ;
		if ((sign == 1 && result > (LLONG_MAX - digit) / base) \
				|| (sign == -1 && (-result) < (LLONG_MIN + digit) / base))
		{
			errno = ERANGE;
			if (sign == 1)
				return (free(cbase), LLONG_MAX);
			return (free(cbase), LLONG_MIN);
		}
		result = result * base + digit;
	}
	return (free(cbase), result);
}

long long	ft_strtoll(char *nptr, char **endptr, int base)
{
	long long	sign;
	long long	result;
	size_t		i;
	char		*cbase;

	if (!nptr)
		return (0);
	cbase = ft_get_base(base);
	if (!cbase)
		return (0);
	i = 0;
	sign = skip_isspace_set_sign(nptr, &i);
	if (base == 0)
		i += case_base_zero(nptr, &base);
	result = main_loop(nptr, &i, sign, base);
	if (errno == ERANGE)
	{
		if (sign == 1)
			return (free(cbase), LLONG_MAX);
		return (free(cbase), LLONG_MIN);
	}
	if (endptr)
		*endptr = &nptr[i];
	return (free(cbase), result * sign);
}
