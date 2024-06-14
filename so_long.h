/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:07:24 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/12 19:35:37 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//predefined libraries
# include <unistd.h>

//own libraries
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"

typedef struct s_player
{
	int	x;
	int	y;
}		t_player;

typedef struct s_exit
{
	int	x;
	int	y;
}		t_exit;

typedef struct s_data
{
	char		**map;
	int			width;
	int			height;
	t_player	player;
	t_exit		exit;
	int			coins_remaining;
	int			moves;
	int			exi;
}		t_data;

typedef struct s_img
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;	
	int		height;
	void	*img_ptr;
	t_data	*data;
	//textures
	void	*wal;
	void	*exi;
	void	*floor;
	void	*col;
	// check after if needed
	void	*plyr;
	int		h;
	int		w;
	int		steps;
}		t_img;

void	check_all(t_data *game);
char	**store_map(char *mapName, size_t size);
t_data	*mesure(char **map);
int		count_elem(t_data *game, char c);
void	check_rec(t_data *game);
void	check_walls(t_data *game);
void	check_components(t_data *game);
char	**dup_map(t_data *game);
void	flood_fill(char **map, t_data *game);
void	init_so_long(char *mapName, t_data *data);
void	moves_drawing(t_img *img, int x, int y);
void	print_error(char *err_msg, t_data *data, int flag);
int		count_coins(t_data *game);
int		handle_key(int key, t_img *img);
int		red_cross(int key, t_data *data);
void	draw_my_images(t_img *img);
void	free2d(char **map);
void	starting_map(t_data *data);
size_t	store_height(char *mapName);
#endif