#include "push_swap.h"

static void	skip_isspace_set_sign(char *nptr, long long *i, long long *sign)
{
	while (nptr[(*i)] == ' ' || (nptr[(*i)] >= 9 && nptr[(*i)] <= 13))
		(*i)++;
	if (nptr[(*i)] == '-')
	{
		(*sign) *= -1;
		(*i)++;
	}
	else if (nptr[(*i)] == '+')
		(*i)++;
}

static char	*ft_get_prefix_base(char **num, int base)
{
	if (*num[0] && *num[1] && *num[0] == '0')
	{
		if (*num[1] == 'x' || *num[1] == 'X')
		{
			(*num) += 2;
			return (ft_get_base(16));
		}
		(*num) += 1;
		return (ft_get_base(8));
	}
	else if (ft_is_num((*num)[0]))
		return (ft_get_base(10));
	return (NULL);
}

static t_bool	valid_num_assign_base(char *num, int base, char **empty_base)
{
	char	*cbase;
	int		i;

	if (base == 0)
		cbase = ft_get_prefix_base(&num, base);
	else
		cbase = ft_get_base(base);
	if (!cbase)
		return (FALSE);
	num = ft_strlowcase(num);
	i = 0;
	while (cbase[i])
	{
		if (*num == cbase[i])
		{
			(*empty_base) = ft_strdup(cbase);
			if (!*empty_base)
				return (free(cbase), FALSE);
			return (free(cbase), TRUE);
		}
		i++;
	}
	return (free(cbase), FALSE);
}

static long long	ft_strtoll_climax(char *num, long long sign, char *cbase)
{
	long long	result;
	size_t		i;
	size_t		base_len;
	int			digit;

	result = 0;
	i = 0;
	base_len = ft_strlen(cbase);
	while (num[i])
	{
		digit = ft_base_pos(num[i], cbase);
		if (digit == -1)
			break ;
		if ((sign == 1 && result > (LLONG_MAX - digit) / base_len) \
			|| (sign == -1 && result < (LLONG_MIN + digit) / base_len))
		{
			errno = ERANGE;
			if (sign == 1)
				return (LLONG_MAX);
			return (LLONG_MIN);
		}
		result = result * base_len + digit;
		i++;
	}
	return (result * sign);
}

long long	ft_strtoll(char *nptr, char **endptr, int base)
{
	long long	i;
	long long	sign;
	char		*cbase;
	char		*num;
	int			num_size;

	if (!nptr || base < 0 || base > 36 || base == 1)
		return (0);
	i = 0;
	sign = 1;
	skip_isspace_set_sign(nptr, &i, &sign);
	num_size = 0;
	cbase = NULL;
	while (valid_num_assign_base(&nptr[i + num_size], base, &cbase))
		num_size++;
	if (endptr)
		*endptr = &nptr[i + num_size];
	if (num_size == 0 || cbase == NULL)
		return (0);
	num = (char *)malloc(sizeof(*num) * (num_size + 1));
	if (!num)
		return (0);
	ft_strncpy(num, &nptr[i], num_size);
	num[num_size] = '\0';
	return (ft_strtoll_climax(num, sign, cbase));
}