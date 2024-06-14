/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:59:48 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/12 20:20:13 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_so_long(char *mapName, t_data *data)
{
	char	**map;
	size_t	size;

	size = store_height(mapName);
	map = store_map(mapName, size);
	if (!map && !*map)
		print_error("Error: map is empty\n", data, 1);
	data = mesure(map);
	if ((data->height > 26) || (data->width > 51))
		print_error("Error : map to big\n", data, 1);
	check_all(data);
	starting_map(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
		init_so_long(av[1], &data);
	else
	{
		ft_putstr_fd("No arguments", 2);
		return (1);
	}
}
