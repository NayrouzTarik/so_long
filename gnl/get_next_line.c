/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:25:50 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/12 20:14:26 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_line(int fd, char *line)
{
	char	*buffer;
	int		rd_byt;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd_byt = 1;
	while (!ft_strchr_gnl(line, '\n') && rd_byt != 0)
	{
		rd_byt = read(fd, buffer, BUFFER_SIZE);
		if (rd_byt == -1)
		{
			if (line)
				free(line);
			free(buffer);
			return (NULL);
		}
		buffer[rd_byt] = '\0';
		line = ft_strjoin_gnl(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*ret_valu;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_read_to_line(fd, line);
	if (!line)
		return (NULL);
	ret_valu = get_the_line(line);
	line = new_line(line);
	return (ret_valu);
}
