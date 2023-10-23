/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:55:34 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/20 22:51:57 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

char	**get_map(int	fd, t_struct *game)
{
	char	*str;
	char	**mapp;

	str = ft_calloc(999999, 1);
	if (!read(fd, str, 999999))
		exit (1);
	//mapp = ft_split(str, '\n');
	mapp = ft_split(str, '\n');
	//free (str);
	if (!check_map(mapp, game))
	{
		printf("map error \n");
		free (mapp);
		exit(1);
	}
	return (mapp);
}

int	check_map(char	**map, t_struct *game)
{
	game->x = ft_strlen(map[0]);
	game->y = 0;
	while (map[game->y])
		game->y++;
	if (!check_square(map, game))
		{
			printf("square error\n");
			return (0);
		}
	if (!check_walls(map, game))
		{
			printf("walls error\n");
			return (0);
		}
	if (check_starter(map) == 0)
		{
			printf("starter error\n");
			return (0);
		}
	else
		return (1);
}

int	check_square(char	**map, t_struct *game)
{
	int	y_1;

	y_1 = 0;
	while (map[y_1])
	{
		if (ft_strlen(map[y_1]) != game->x)
			return (0);
		y_1++;
	}
	return (1);
}

int	check_walls(char **map, t_struct *game)
{
	int	x_1;
	int	y_1;

	x_1 = 0;
	y_1 = 0;
	while (map[0][x_1])
	{
		if (map[0][x_1] != '1' || map[game->y-1][x_1] != '1') 
			return (0);
		x_1++;
	}
	x_1 = 0;
	while (map[y_1])
	{
		if (map[y_1][0] != '1' || map[y_1][game->x -1] != '1')
			return (0);
		y_1++;
	}
	return (1);
}

int	check_starter(char	**map)
{
	int	p;
	int	e;
	int	c;
	int	y;
	int	x;

	y = 0;
	p = 0;
	e = 0;
	c = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				p++;
			if (map[y][x] == 'C')
				c++;
			if (map[y][x] == 'E')
				e++;
			x++;
		}
		x = 0;
		y++;
	}
	//printf("p = %d, e = %d, c = %d\n", p, e, c);
	if (p == 1 && e == 1 && c > 0)
		return (1);
	else
		return (0);
}