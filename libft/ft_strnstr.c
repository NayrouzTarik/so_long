/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:29:29 by ntarik            #+#    #+#             */
/*   Updated: 2023/11/26 16:26:39 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *large, const char *little, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	str = (char *)large;
	if (!little[i])
		return (str);
	if (len == 0)
		return (NULL);
	while (large[i] != '\0' && i < len)
	{
		j = 0;
		while (large[i + j] == little[j] && little[j] != '\0' && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&large[i]);
		i++;
	}
	return (0);
}
