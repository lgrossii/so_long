/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:28:49 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/23 19:23:36 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_game(t_struct	*game)
{
	int	y;

	y = 0;
	while (y < game->y)
		free (game->map[y++]);
	free (game->map);
}

void	free_map(char	**map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
		free (map[y++]);
	free (map);
}
