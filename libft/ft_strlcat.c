/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:20:58 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/12 18:13:59 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lenght_dest;
	size_t	lenght_src;

	lenght_dest = ft_strlen(dest);
	lenght_src = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (lenght_src);
	if (size <= lenght_dest)
		return (lenght_src + size);
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (lenght_dest + lenght_src);
}
