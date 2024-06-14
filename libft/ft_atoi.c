/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:16:55 by ntarik            #+#    #+#             */
/*   Updated: 2023/11/26 21:52:54 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkthesigne(char *str, int *sign, int i)
{
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			(*sign) *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				signe;
	long long int	previous_checker;
	long long int	res;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	i = checkthesigne((char *)str, &signe, i);
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		previous_checker = res;
		res = res * 10 + str[i] - '0';
		if (previous_checker != res / 10 && signe == 1)
			return (-1);
		else if (previous_checker != res / 10 && signe == -1)
			return (0);
		i++;
	}
	return ((int)(signe * res));
}
