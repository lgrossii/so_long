/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:12:51 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/23 18:10:22 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main()
{
	int	fd;
	t_struct game;
	fd = open("map/map.ber",O_RDONLY);
	game.frame_rate = 0;
	game.n_move = -1;
	game.map = get_map(fd, &game);
	game.player.move = -1;
	game.moves_number = 0;
	game.player.comp_frame_rate = -1;
	game.mlx_instance = mlx_init();
	get_enemy_texture(&game);
	game.mlx_window = mlx_new_window(game.mlx_instance, game.x * 64, (game.y + 1) * 64, "so_long");
	get_texture(&game);
	render_singles(&game);
	mlx_key_hook(game.mlx_window, which_n, &game);
	mlx_loop_hook(game.mlx_instance, render_animation, &game);
	mlx_loop(game.mlx_instance);
	return (0);
}