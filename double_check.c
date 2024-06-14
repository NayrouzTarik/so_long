/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:38:24 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/12 17:28:15 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **map, int x, int y, t_data *game)
{
	int	height;
	int	width;

	height = game->height;
	width = game->width;
	if (x < 0 || y < 0 || y >= height || x >= width
		|| map[y][x] == 'F' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	map[y][x] = 'F';
	fill(map, x + 1, y, game);
	fill(map, x - 1, y, game);
	fill(map, x, y + 1, game);
	fill(map, x, y - 1, game);
}

void	flood_fill(char **map, t_data *game)
{
	int	i;
	int	j;

	fill(map, game->player.x, game->player.y, game);
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != 'F' && map[i][j] != '0')
				print_error("Error: player cannot move\n", game, 2);
			j++;
		}
		i++;
	}
}
