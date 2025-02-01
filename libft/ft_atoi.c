/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:28:37 by olachgue          #+#    #+#             */
/*   Updated: 2024/11/06 19:18:42 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_spaces_and_check_sign(int *i, const char *str)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			sign = -1;
		}
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long long	result;
	long long	tmp;

	result = 0;
	tmp = 0;
	i = 0;
	sign = skip_spaces_and_check_sign(&i, str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp *= 10;
		tmp += str[i] - '0';
		if (tmp / 10 < result)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		result = tmp;
		i++;
	}
	return (result * sign);
}
