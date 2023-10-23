/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_singles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:47:00 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/23 19:19:38 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_perimetral_wall(t_struct *game)
{
	int	i;

	i = 1;
	mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->wall.img_angle_00, 0, 0);
	mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->wall.img_angle_0x, (game->x - 1) * 64, 0);
	mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->wall.img_angle_y0, 0, (game->y - 1) * 64);
	mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->wall.img_angle_yx, (game->x - 1) * 64, (game->y - 1) * 64);
	while (i < game->x -1)
	{
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->wall.img_up, i * 64, 0);
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->wall.img_down, i * 64, (game->y - 1) * 64);
		i++;
	}
	i = 1;
	while (i < game->y -1)
	{
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->wall.img_sx, 0, i * 64);
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->wall.img_dx, (game->x - 1) * 64, i * 64);
		i++;
	}
}

void	render_singles(t_struct	*game)
{
	int	h;
	int	w;

	h = 1;
	w = 1;
	while (h < game->y -1)
	{
		while (w < game->x - 1)
		{
			if (game->map[h][w] == '0' || game->map[h][w] == 'P' || game->map[h][w] == 'N')
				mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->tile.img_00, w * 64, h * 64);
			else if (game->map[h][w] == '1')
				mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->wall.rock, w * 64, h * 64);
			else if (game->map[h][w] == 'C')
				render_collectable(game, w, h);
			else if (game->map[h][w] == 'E' && no_more_coll(game))
				mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->exit.img_closed, w * 64, h * 64);
			else if (game->map[h][w] == 'E' && !no_more_coll(game))
				mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->exit.img_open, w * 64, h * 64);
			w++;
		}
		w = 1;
		h++;
	}
}

void	render_collectable(t_struct	*game, int x, int y)
{
	if (game->frame_rate >= 0 && game->frame_rate < 6)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->collectable.img_00, x * 64, y * 64);
	if (game->frame_rate >= 6 && game->frame_rate < 12)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->collectable.img_01, x * 64, y * 64);
	if (game->frame_rate >= 12 && game->frame_rate < 18)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->collectable.img_02, x * 64, y * 64);
	if (game->frame_rate >= 18 && game->frame_rate <= 24)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->collectable.img_03, x * 64, y * 64);
}
