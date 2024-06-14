/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:21:23 by ntarik            #+#    #+#             */
/*   Updated: 2023/11/26 16:43:22 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp( const char *p1, const char *p2, size_t n)
{
	if (n == 0)
		return (0);
	while (*p1 && *p2 && (*p1 == *p2) && --n)
	{
		p1++;
		p2++;
	}
	return ((unsigned char)(*p1) - (unsigned char)(*p2));
}
