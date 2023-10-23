/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemy_animation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:20:55 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/23 19:26:58 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_enemy_animation(t_struct	*game)
{
	int	diff;
	
	if (game->enemy.frame_rate == -1)
	{
		game->enemy.comp_frame_rate = game->frame_rate;
		game->enemy.frame_rate = game->enemy.comp_frame_rate;
	}
	if (all_rocks(game) == 0)
	{
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.down_00, game->enemy.position.x * 64, game->enemy.position.y * 64);
		return ;
	}
	while (game->enemy.n_moves == -1)
		enemy_moves(game);
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
}

void	enemy_goes_up(t_struct	*game, int n)
{
	if (n >= 1 && n < 5)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.up_00, game->enemy.position.x * 64, (game->enemy.position.y * 64) + 64);
	else if (n >= 5 && n < 10)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.up_01, game->enemy.position.x * 64, (game->enemy.position.y * 64) + 43);
	else if (n >= 10 && n < 15)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.up_02, game->enemy.position.x * 64, (game->enemy.position.y * 64) + 22);
	else if (n >= 15 && n <= 20)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.up_03, game->enemy.position.x * 64, game->enemy.position.y * 64);
	else
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.up_00, game->enemy.position.x * 64, (game->enemy.position.y * 64));
	if (n == 50)
	{
		game->enemy.comp_frame_rate = -1;
		game->enemy.frame_rate = -1;
		game->enemy.n_moves = -1;
	}
}

void	enemy_goes_down(t_struct	*game, int n)
{
	if (n >= 1 && n < 5)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.down_00, game->enemy.position.x * 64, (game->enemy.position.y * 64) - 64);
	else if (n >= 5 && n < 10)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.down_01, game->enemy.position.x * 64, (game->enemy.position.y * 64) - 43);
	else if (n >= 10 && n < 15)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.down_02, game->enemy.position.x * 64, (game->enemy.position.y * 64) - 22);
	else if (n >= 15 && n <= 20)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.down_03, game->enemy.position.x * 64, game->enemy.position.y * 64);
	else
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.down_00, game->enemy.position.x * 64, (game->enemy.position.y * 64));
	if (n == 50)
	{
		game->enemy.comp_frame_rate = -1;
		game->enemy.frame_rate = -1;
		game->enemy.n_moves = -1;
	}
}

void	enemy_goes_sx(t_struct	*game, int n)
{
	if (n >= 1 && n < 5)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.sx_00, (game->enemy.position.x * 64) + 64, game->enemy.position.y * 64);
	else if (n >= 5 && n < 10)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.sx_01, (game->enemy.position.x * 64) + 43, game->enemy.position.y * 64);
	else if (n >= 10 && n < 15)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.sx_02, (game->enemy.position.x * 64) + 22, game->enemy.position.y * 64);
	else if (n >= 15 && n <= 20)
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
	if (n >= 1 && n < 5)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.dx_00, (game->enemy.position.x * 64) - 64, game->enemy.position.y * 64);
	else if (n >= 5 && n < 10)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.dx_01, (game->enemy.position.x * 64) - 42, game->enemy.position.y * 64);
	else if (n >= 10 && n < 15)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->enemy.dx_02, (game->enemy.position.x * 64) - 22, game->enemy.position.y * 64);
	else if (n >= 15 && n <= 20)
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
