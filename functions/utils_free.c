/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:28:49 by lorenzogros       #+#    #+#             */
/*   Updated: 2024/08/29 16:11:32 by lorenzogros      ###   ########.fr       */
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

	y = 0;
	while (map[y])
		free (map[y++]);
	free (map);
}
