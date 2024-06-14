/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:08:27 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/12 18:05:15 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *err_msg, t_data *data, int flag)
{
	(void)data;
	if (flag == 2)
	{
		ft_putstr_fd(err_msg, 2);
		free2d(data->map);
		exit(1);
	}
	else
	{
		write(2, err_msg, ft_strlen(err_msg));
		exit(1);
	}
}

char	**store_map(char *mapName, size_t size)
{
	int		i;
	int		fd;
	char	*str;
	char	**map2d;

	i = 0;
	fd = open(mapName, O_RDONLY);
	if (fd < 0)
		print_error("Error: failed to open file\n", NULL, 1);
	map2d = ft_calloc(size + 1, sizeof(char *));
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL || !*str)
			break ;
		map2d[i] = ft_strtrim(str, "\n");
		free(str);
		i++;
	}
	map2d[i] = NULL;
	free(str);
	close(fd);
	return (map2d);
}

t_data	*mesure(char **map)
{
	int		height;
	int		width;
	t_data	*game;

	height = 0;
	width = 0;
	game = malloc(sizeof(t_data));
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	game->height = height;
	game->width = width;
	game->map = map;
	return (game);
}

void	check_rec(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (j != game->width)
			print_error("Map is not Valid\n", game, 2);
		i++;
	}
}

void	check_walls(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == game->height - 1
				|| j == 0 || j == game->width - 1)
			{
				if (game->map[i][j] != '1')
					print_error("The map is not closed\n", game, 2);
			}
			j++;
		}
		i++;
	}
}
