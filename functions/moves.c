/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:19:39 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/23 18:50:23 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	calculate_next_move(t_struct *game)
{
	if (game->n_move == 126 || game->n_move == 13)
	{
		game->player.next_move.x = game->player.position.x;
		game->player.next_move.y = game->player.position.y -1;
	}
	else if (game->n_move == 125 || game->n_move == 1)
	{
		game->player.next_move.x = game->player.position.x;
		game->player.next_move.y = game->player.position.y + 1;
	}
	else if (game->n_move == 123 || game->n_move == 0)
	{
		game->player.next_move.x = game->player.position.x - 1;
		game->player.next_move.y = game->player.position.y;
	}
	else if (game->n_move == 124 || game->n_move == 2)
	{
		game->player.next_move.x = game->player.position.x + 1;
		game->player.next_move.y = game->player.position.y;
	}
}

int	check_move(t_struct	*game)
{
	if (game->map[game->player.next_move.y][game->player.next_move.x] == '1')
		return (0);
	if (game->map[game->player.next_move.y][game->player.next_move.x] == 'N')
	{
		free_game(game);
		exit(0);
	}
	if (game->map[game->player.next_move.y][game->player.next_move.x] == 'E')
	{
		if (no_more_coll(game))
			return (0);
		else
		{
			free_game(game);
			exit (0);
		}
	}
	game->player.move = game->n_move;
	if (game->player.move == 124 || game->player.move == 2)
		game->player.idle = 6;
	else if (game->player.move == 123 || game->player.move == 0)
		game->player.idle = 4;
	else if (game->player.move == 126 || game->player.move == 13)
		game->player.idle = 8;
	else
		game->player.idle = 0;
	game->moves_number++;
	game->map[game->player.position.y][game->player.position.x] = '0';
	game->map[game->player.next_move.y][game->player.next_move.x] = 'P';
	return (1);
}

int	which_n(int n, t_struct *game)
{
	if (n == 53)
	{
		free_game(game);
		exit (0);
	}
	else if ((n >= 123 && n <= 126) || (n == 0 || n == 1 || n == 2 || n == 13))
		game->n_move = n;
	else
		return (0);
	find_el(&game->player.position, game, 'P');
	calculate_next_move(game);
	if (!check_move(game))
		return (0);
	else
	{
		game->player.comp_frame_rate = -1;
		return (1);
	}
}
