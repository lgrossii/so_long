/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:20:25 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/20 22:59:03 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct_textures.h"

void	get_enemy_texture(t_struct	*game)
{
	game->enemy.down_00 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_down_00.xpm", &game->size_x, &game->size_y);
	game->enemy.down_01 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_down_01.xpm", &game->size_x, &game->size_y);
	game->enemy.down_02 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_down_02.xpm", &game->size_x, &game->size_y);
	game->enemy.down_03 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_down_03.xpm", &game->size_x, &game->size_y);
	game->enemy.up_00 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_up_00.xpm", &game->size_x, &game->size_y);
	game->enemy.up_01 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_up_01.xpm", &game->size_x, &game->size_y);
	game->enemy.up_02 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_up_02.xpm", &game->size_x, &game->size_y);
	game->enemy.up_03 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_up_03.xpm", &game->size_x, &game->size_y);
	game->enemy.sx_00 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_sx_00.xpm", &game->size_x, &game->size_y);
	game->enemy.sx_01 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_sx_01.xpm", &game->size_x, &game->size_y);
	game->enemy.sx_02 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_sx_02.xpm", &game->size_x, &game->size_y);
	game->enemy.sx_03 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_sx_03.xpm", &game->size_x, &game->size_y);
	game->enemy.dx_00 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_dx_00.xpm", &game->size_x, &game->size_y);
	game->enemy.dx_01 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_dx_01.xpm", &game->size_x, &game->size_y);
	game->enemy.dx_02 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_dx_02.xpm", &game->size_x, &game->size_y);
	game->enemy.dx_03 = mlx_xpm_file_to_image(game->mlx_instance, "textures/enemy/enemy_dx_03.xpm", &game->size_x, &game->size_y);
}
