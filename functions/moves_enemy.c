/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:33:14 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/23 18:47:48 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enemy_moves(t_struct	*game)
{
	int	move;

	find_el(&game->enemy.position, game, 'N');
	move = rand() % 4;
	if (where_n_will_land(game, move) == 'P')
	{
		free_game(game);
		exit (0);
	}
	if (move == 0 && where_n_will_land(game, 0) == '0')
		do_n_move(game, move);
	if (move == 1 && where_n_will_land(game, 1) == '0')
		do_n_move(game, move);
	if (move == 2 && where_n_will_land(game, 2) == '0')
		do_n_move(game, move);
	if (move == 3 && where_n_will_land(game, 3) == '0')
		do_n_move(game, move);
}

char	where_n_will_land(t_struct *game, int n)
{
	int	x;
	int	y;

	x = game->enemy.position.x;
	y = game->enemy.position.y;
	if (n == 0)
		return (game->map[y - 1][x]);
	else if (n == 1)
		return (game->map[y + 1][x]);
	else if (n == 2)
		return (game->map[y][x + 1]);
	else
		return (game->map[y][x - 1]);
}

void	do_n_move(t_struct	*game, int n)
{
	int	x;
	int	y;

	x = game->enemy.position.x;
	y = game->enemy.position.y;
	if (n == 0)
	{
		game->enemy.n_moves = 8;
		game->map[y - 1][x] = 'N';
	}
	if (n == 1)
	{
		game->enemy.n_moves = 2;
		game->map[y + 1][x] = 'N';
	}
	if (n == 2)
	{
		game->enemy.n_moves = 6;
		game->map[y][x + 1] = 'N';
	}
	if (n == 3)
	{
		game->enemy.n_moves = 4;
		game->map[y][x - 1] = 'N';
	}
	game->map[y][x] = '0';
}

int	all_rocks(t_struct	*game)
{
	find_el(&game->enemy.position, game, 'N');
	if (where_n_will_land(game, 0) != '0' && where_n_will_land(game, 1) != '0' \
	&& where_n_will_land(game, 2) != '0' && where_n_will_land(game, 3) != '0')
		return (0);
	else
		return (1);
}
