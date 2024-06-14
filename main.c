/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:33:52 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/12 20:03:35 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*check_before(t_img *img, char *path)
{
	void	*tmp;
	int		a;
	int		b;

	tmp = mlx_xpm_file_to_image(img->mlx_ptr, path, &a, &b);
	if (tmp == NULL)
	{
		print_error("Error: failed to load image\n", img->data, 2);
		exit (1);
	}
	return (tmp);
}

void	init_windows(t_img *img, t_data *data)
{
	img->mlx_ptr = mlx_init();
	if (img->mlx_ptr == NULL)
	{
		print_error("Error: failed to init mlx\n", data, 2);
		exit (1);
	}
	img->win_ptr = mlx_new_window(img->mlx_ptr, data->width * 50, \
	data->height * 50, "--so_long--");
	if (img->win_ptr == NULL)
	{
		print_error("Error: failed to create window\n", data, 2);
		exit (1);
	}
}

void	init_img(t_img *img)
{
	img->wal = check_before(img, "./so_long_img/wall.xpm");
	img->col = check_before(img, "./so_long_img/coin.xpm");
	img->plyr = check_before(img, "./so_long_img/char.xpm");
	img->exi = check_before(img, "./so_long_img/exit.xpm");
	img->floor = check_before(img, "./so_long_img/floor.xpm");
}

void	starting_map(t_data *data)
{
	t_img	*img;

	img = malloc (sizeof (t_img));
	if (img == NULL)
		return ;
	img->data = data;
	init_windows(img, data);
	init_img(img);
	draw_my_images(img);
	img->steps = 0;
	mlx_hook(img->win_ptr, 02, 0, &handle_key, img);
	mlx_hook(img->win_ptr, 17, 0, &red_cross, NULL);
	mlx_loop(img->mlx_ptr);
}

size_t	store_height(char *mapName)
{
	int		fd;
	int		size;
	char	*line;

	size = 0;
	if (ft_strnstr(mapName, ".ber", ft_strlen(mapName)) == NULL)
		print_error("Error: invalid file\n", NULL, 1);
	fd = open(mapName, O_RDONLY);
	if (fd == -1)
		print_error("can't open file", NULL, 1);
	line = get_next_line(fd);
	if (!line || !line[0])
		print_error("empty line\n", NULL, 1);
	while (line != NULL)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (size);
}
