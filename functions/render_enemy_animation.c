/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemy_animation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:20:55 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/21 20:13:54 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_enemy_animation(t_struct	*game)
{
	int	diff;
	if (game->enemy.comp_frame_rate == -1)
	{
		game->enemy.comp_frame_rate = game->frame_rate;
		game->enemy.frame_rate = game->frame_rate;
	}
	while (game->enemy.n_moves == -1)// 	DEVI FIXARE CASO IN CUI N NON PUO MUOVERSI
	{
		enemy_moves(game);
	}
	if (game->enemy.comp_moves != game->enemy.n_moves)
		printf("position enemy : x %d y %d mossa : %d \n", game->enemy.position.x, game->enemy.position.y, game->enemy.n_moves);
	game->enemy.frame_rate++;
	diff = game->enemy.frame_rate - game->enemy.comp_frame_rate;
	find_el(&game->enemy.position, game, 'N');
	if (game->enemy.n_moves == 8)
		enemy_goes_up(game, diff);
	else if (game->enemy.n_moves == 2)
		enemy_goes_down(game, diff);
	else if (game->enemy.n_moves == 4)
		enemy_goes_sx(game, diff);
	else if (game->enemy.n_moves == 6)
		enemy_goes_dx(game, diff);
	game->enemy.comp_moves = game->enemy.n_moves;
	// else
	// {
	// 	enemy_moves(game);
	// 	render_enemy_animation(game);
	// }
}

void	enemy_goes_up(t_struct	*game, int n)
{
	if (n >= 1 && n < 4)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.up_00, game->enemy.position.x * 64, (game->enemy.position.y * 64) + 64);
	else if (n >= 4 && n < 8)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.up_01, game->enemy.position.x * 64, (game->enemy.position.y * 64) + 43);
	else if (n >= 8 && n < 12)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.up_02, game->enemy.position.x * 64, (game->enemy.position.y * 64) + 22);
	else if (n >= 12 && n <= 16)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.up_03, game->enemy.position.x * 64, game->enemy.position.y * 64);
	else
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.up_00, game->enemy.position.x * 64, (game->enemy.position.y * 64) );
	if (n == 50)
	{
		game->enemy.comp_frame_rate = -1;
		game->enemy.frame_rate = -1;
		game->enemy.n_moves = -1;
	}
}

void	enemy_goes_down(t_struct	*game, int n)
{
	if (n >= 1 && n < 4)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.down_00, game->enemy.position.x * 64, (game->enemy.position.y * 64) - 64);
	else if (n >= 4 && n < 8)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.down_01, game->enemy.position.x * 64, (game->enemy.position.y * 64) - 43);
	else if (n >= 8 && n < 12)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.down_02, game->enemy.position.x * 64, (game->enemy.position.y * 64) - 22);
	else if (n >= 12 && n <= 16)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.down_03, game->enemy.position.x * 64, game->enemy.position.y * 64);
	else
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.down_00, game->enemy.position.x * 64, (game->enemy.position.y * 64) );
	if (n == 50)
	{
		game->enemy.comp_frame_rate = -1;
		game->enemy.frame_rate = -1;
		game->enemy.n_moves = -1;
	}
}

void	enemy_goes_sx(t_struct	*game, int n)
{
	if (n >= 1 && n < 4)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.sx_00, (game->enemy.position.x * 64) + 64, game->enemy.position.y * 64);
	else if (n >= 4 && n < 8)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.sx_01, (game->enemy.position.x * 64) + 43, game->enemy.position.y * 64);
	else if (n >= 8 && n < 12)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.sx_02, (game->enemy.position.x * 64) + 22, game->enemy.position.y * 64);
	else if (n >= 12 && n <= 16)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.sx_03, game->enemy.position.x * 64, game->enemy.position.y * 64);
	else
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.sx_00, game->enemy.position.x * 64, (game->enemy.position.y * 64) );
	if (n == 50)
	{
		game->enemy.comp_frame_rate = -1;
		game->enemy.frame_rate = -1;
		game->enemy.n_moves = -1;
	}
}

void	enemy_goes_dx(t_struct	*game, int n)
{
	if (n >= 1 && n < 4)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.dx_00, (game->enemy.position.x * 64) - 64, game->enemy.position.y * 64);
	else if (n >= 4 && n < 8)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.dx_01, (game->enemy.position.x * 64) - 42, game->enemy.position.y * 64);
	else if (n >= 8 && n < 12)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.dx_02, (game->enemy.position.x * 64) - 22, game->enemy.position.y * 64);
	else if (n >= 12 && n <= 16)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.dx_03, game->enemy.position.x * 64, game->enemy.position.y * 64);
	else
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.dx_00, game->enemy.position.x * 64, game->enemy.position.y * 64 );
	if (n == 50)
	{
		game->enemy.comp_frame_rate = -1;
		game->enemy.frame_rate = -1;
		game->enemy.n_moves = -1;
	}
}