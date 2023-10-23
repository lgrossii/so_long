/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:10:41 by lgrossi           #+#    #+#             */
/*   Updated: 2023/10/23 19:08:35 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_starter(char	**map)
{
	int	p;
	int	e;
	int	y;
	int	x;

	y = 0;
	p = 0;
	e = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				p++;
			if (map[y][x] == 'E')
				e++;
			x++;
		}
		x = 0;
		y++;
	}
	if (p == 1 && e == 1)
		return (1);
	else
		return (0);
}

int	check_enemy(char	**map, t_struct	*game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	game->enemy_status = 0;
	while (map[y])
	{
		while (map[y][x++])
		{
			if (map[y][x] == 'N')
				game->enemy_status++;
		}
		y++;
		x = 0;
	}
	if (game->enemy_status == 1)
	{
		game->enemy.n_moves = -1;
		game->enemy.frame_rate = -1;
		return (1);
	}
	if (game->enemy_status >= 2)
		return (0);
	else
		return (1);
}

int	check_collectable(char	**map)
{
	int	c;
	int	y;
	int	x;

	y = 0;
	c = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x++] == 'C')
				c++;
		}
		x = 0;
		y++;
	}
	if (c > 0)
		return (1);
	else
		return (0);
}
