/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:21:32 by ntarik            #+#    #+#             */
/*   Updated: 2023/11/27 00:22:34 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	found_ya(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int	begging;
	int	end;

	if (!s1 || !set)
		return (NULL);
	begging = 0;
	while (s1[begging] && found_ya(s1[begging], set))
		begging++;
	end = ft_strlen(s1) - 1;
	while (end > begging && found_ya(s1[end], set))
		end--;
	return (ft_substr(s1, begging, end - begging + 1));
}
