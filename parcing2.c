/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:47:15 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/12 18:05:37 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_elem(t_data *game, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == c)
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

void	check_components(t_data *game)
{
	if (count_elem(game, 'P') != 1
		|| count_elem(game, 'E') != 1 || count_elem(game, 'C') < 1)
		print_error("Error: invalid number of one of \
		the components\n", game, 2);
	game->coins_remaining = count_elem(game, 'C');
}

void	check_char(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'C')
				print_error("Error: invalid character in the map\n", game, 2);
			if (game->map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
			}
			if (game->map[i][j] == 'E')
			{
				game->exit.x = j;
				game->exit.y = i;
			}
		}
	}
}

char	**dup_map(t_data *game)
{
	char	**dup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dup = malloc(sizeof(char *) * (game->height + 1));
	if (!dup)
		print_error("Error: malloc failed\n", NULL, 1);
	while (game->map[i])
	{
		dup[i] = malloc(sizeof(char) * (game->width + 1));
		if (!dup[i])
			print_error("Error: malloc failed\n", NULL, 1);
		j = 0;
		while (game->map[i][j])
		{
			dup[i][j] = game->map[i][j];
			j++;
		}
		dup[i][j] = '\0';
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

void	check_all(t_data *game)
{
	char	**dup;

	check_char(game);
	check_rec(game);
	check_walls(game);
	check_components(game);
	dup = dup_map(game);
	flood_fill(dup, game);
	free2d(dup);
}
