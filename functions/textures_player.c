/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:05:20 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/20 16:46:43 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct_textures.h"

void	texture_player(t_struct	*game)
{
	get_player_movement_up_down(game);
	get_player_movements_dx_sx(game);
	get_player_idles(game);
}

void	get_player_movements_dx_sx(t_struct	*game)
{
	//dx
	game->player.img_dx_00 = mlx_xpm_file_to_image(game->mlx_instance, "textures/player/player_dx_00.xpm", &game->size_x, &game->size_y);
	game->player.img_dx_01 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_dx_01.xpm", &game->size_x, &game->size_y);
	game->player.img_dx_02 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_dx_02.xpm", &game->size_x, &game->size_y);
	game->player.img_dx_03 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_dx_03.xpm", &game->size_x, &game->size_y);
	//sx
	game->player.img_sx_00 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_sx_00.xpm", &game->size_x, &game->size_y);
	game->player.img_sx_01 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_sx_01.xpm", &game->size_x, &game->size_y);
	game->player.img_sx_02 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_sx_02.xpm", &game->size_x, &game->size_y);
	game->player.img_sx_03 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_sx_03.xpm", &game->size_x, &game->size_y);
}

void	get_player_movement_up_down(t_struct	*game)
{
	//up
	game->player.img_up_00 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_up_00.xpm", &game->size_x, &game->size_y);
	game->player.img_up_01 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_up_01.xpm", &game->size_x, &game->size_y);
	game->player.img_up_02 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_up_02.xpm", &game->size_x, &game->size_y);
	game->player.img_up_03 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_up_03.xpm", &game->size_x, &game->size_y);
	//down
	game->player.img_down_00 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_down_00.xpm", &game->size_x, &game->size_y);
	game->player.img_down_01 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_down_01.xpm", &game->size_x, &game->size_y);
	game->player.img_down_02 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_down_02.xpm", &game->size_x, &game->size_y);
	game->player.img_down_03 =mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_down_03.xpm", &game->size_x, &game->size_y);
}

void	get_player_idles(t_struct	*game)
{
	//idle
	game->player.img_idle_00 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_idle_00.xpm", &game->size_x, &game->size_y);
	game->player.img_idle_01 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_idle_01.xpm", &game->size_x, &game->size_y);
	game->player.img_idle_02 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_idle_02.xpm", &game->size_x, &game->size_y);
	game->player.img_idle_03 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_idle_03.xpm", &game->size_x, &game->size_y);
	//idle dx
	game->player.idle_dx_00 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_idle_dx_00.xpm", &game->size_x, &game->size_y);
	game->player.idle_dx_01 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_idle_dx_01.xpm", &game->size_x, &game->size_y);
	game->player.idle_dx_02 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_idle_dx_02.xpm", &game->size_x, &game->size_y);
	//idle sx
	game->player.idle_sx_00 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_idle_sx_00.xpm", &game->size_x, &game->size_y);
	game->player.idle_sx_01 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_idle_sx_01.xpm", &game->size_x, &game->size_y);
	game->player.idle_sx_02 = mlx_xpm_file_to_image(game->mlx_instance, "./textures/player/player_idle_sx_02.xpm", &game->size_x, &game->size_y);
	//idle up
	game->player.idle_up_00 = mlx_xpm_file_to_image(game->mlx_instance, "textures/player/player_idle_up_00.xpm", &game->size_x, &game->size_y);
	game->player.idle_up_01 = mlx_xpm_file_to_image(game->mlx_instance, "textures/player/player_idle_up_01.xpm", &game->size_x, &game->size_y);
	game->player.idle_up_02 = mlx_xpm_file_to_image(game->mlx_instance, "textures/player/player_idle_up_02.xpm", &game->size_x, &game->size_y);
}