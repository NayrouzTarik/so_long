/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:11:39 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/12 17:48:46 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	func_image_window(t_img *img, void *img1, void *img2, int a)
{
	if (a == 1)
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, \
		img1, img->h, img->w);
	else if (a == 2)
	{
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, \
		img1, img->h, img->w);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, \
		img2, img->h, img->w);
	}
}

void	draw_my_images(t_img *img)
{
	int	i;
	int	j;

	img->w = 0;
	i = -1;
	while (img->data->map[++i])
	{
		j = -1;
		img->h = 0;
		while (img->data->map[i][++j])
		{
			if (img->data->map[i][j] == '1')
				func_image_window(img, img->floor, img->wal, 2);
			else if (img->data->map[i][j] == 'C')
				func_image_window(img, img->floor, img->col, 2);
			else if (img->data->map[i][j] == 'E')
				func_image_window(img, img->floor, img->exi, 2);
			else if (img->data->map[i][j] == 'P')
				func_image_window(img, img->floor, img->plyr, 2);
			else if (img->data->map[i][j] == '0')
				func_image_window(img, img->floor, NULL, 1);
			img->h += 50;
		}
		img->w += 50;
	}
}

void	moves_drawing(t_img *img, int x, int y)
{
	if (img->data->map[y][x] != '1')
	{
		if (img->data->map[y][x] == 'C')
		{
			img->data->map[y][x] = '0';
			img->data->coins_remaining--;
		}
		if (img->data->map[y][x] == 'E' && img->data->coins_remaining == 0)
		{
			mlx_destroy_window(img->mlx_ptr, img->win_ptr);
			exit(0);
		}
		else if (img->data->map[y][x] != 'E')
		{
			mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->floor, \
			img->data->player.x * 50, img->data->player.y * 50);
			img->data->player.x = x;
			img->data->player.y = y;
			mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->plyr, \
			img->data->player.x * 50, img->data->player.y * 50);
			ft_putstr_fd("Your player had moved by : ", 1);
			ft_putnbr_fd(++img->steps, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

int	handle_key(int key, t_img *img)
{
	if (key == 53)
	{
		mlx_destroy_window(img->mlx_ptr, img->win_ptr);
		exit(0);
	}
	else
	{
		if (key == 13 || key == 126)
			moves_drawing(img, img->data->player.x, img->data->player.y - 1);
		else if (key == 1 || key == 125)
			moves_drawing(img, img->data->player.x, img->data->player.y + 1);
		else if (key == 0 || key == 123)
			moves_drawing(img, img->data->player.x - 1, img->data->player.y);
		else if (key == 2 || key == 124)
			moves_drawing(img, img->data->player.x + 1, img->data->player.y);
	}
	return (0);
}
