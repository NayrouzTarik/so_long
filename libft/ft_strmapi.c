/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:21:18 by ntarik            #+#    #+#             */
/*   Updated: 2023/11/26 18:40:11 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*rs;
	size_t	len ;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	rs = (char *)malloc(len + 1);
	if (!rs)
		return (NULL);
	while (s[i])
	{
		rs[i] = f(i, s[i]);
		i++;
	}
	rs[i] = '\0';
	return (rs);
}
