/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:22:15 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/21 20:02:33 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_el(t_coordinate	*element, t_struct *game, char c)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while(y < game->y - 1)
	{
		while (x < game->x - 1)
		{
			if (game->map[y][x] == c)
				{
					element->x = x;
					element->y = y;
				}
			x++;
		}
		x = 1;
		y++;
	}
}

int	no_more_coll(t_struct	*game)
{
	int	i;

	i = 1;
	while (i < game->y - 1)
	{
		if (ft_strchr(game->map[i], 'C'))
			return(1);
		i++;
	}
	return (0);
}

void	enemy_status(t_struct	*game)
{
	int	i;
	
	i = 0;
	while (i < game->y)
	{
		if (ft_strchr(game->map[i], 'N'))
		{
			game->enemy.n_moves = -1;
			game->enemy_status = 1;
		}
		i++;
	}
}