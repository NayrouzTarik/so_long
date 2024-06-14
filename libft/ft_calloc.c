/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:35:16 by ntarik            #+#    #+#             */
/*   Updated: 2023/11/26 22:07:12 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	of;
	char	*pointer;

	of = count * size;
	if (of != 0 && (of / size) != count && size > 0)
		return (NULL);
	pointer = malloc(of);
	if (pointer != NULL)
		ft_bzero(pointer, of);
	return (pointer);
}
