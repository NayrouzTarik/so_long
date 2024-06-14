/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:19:25 by ntarik            #+#    #+#             */
/*   Updated: 2023/11/26 22:26:35 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		cr;

	str = (const unsigned char *)s;
	cr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == cr)
		{
			return ((void *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
