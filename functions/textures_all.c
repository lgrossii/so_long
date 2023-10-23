/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:45:23 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/20 16:51:23 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct_textures.h"

void	texture_wall(t_struct	*game)
{
	game->wall.img_angle_00 = mlx_xpm_file_to_image(game->mlx_instance, "textures/wall/wall_angle_00.xpm",&game->size_x, &game->size_y);
	game->wall.img_angle_0x = mlx_xpm_file_to_image(game->mlx_instance, "textures/wall/wall_angle_0x.xpm",&game->size_x, &game->size_y);
	game->wall.img_angle_y0 = mlx_xpm_file_to_image(game->mlx_instance, "textures/wall/wall_angle_y0.xpm",&game->size_x, &game->size_y);
	game->wall.img_angle_yx = mlx_xpm_file_to_image(game->mlx_instance, "textures/wall/wall_angle_yx.xpm",&game->size_x, &game->size_y);
	game->wall.img_up = mlx_xpm_file_to_image(game->mlx_instance, "textures/wall/wall_up.xpm",&game->size_x, &game->size_y);
	game->wall.img_down =  mlx_xpm_file_to_image(game->mlx_instance, "textures/wall/wall_down.xpm",&game->size_x, &game->size_y);
	game->wall.img_dx = mlx_xpm_file_to_image(game->mlx_instance, "textures/wall/wall_dx.xpm",&game->size_x, &game->size_y);
	game->wall.img_sx = mlx_xpm_file_to_image(game->mlx_instance, "textures/wall/wall_sx.xpm",&game->size_x, &game->size_y);
	game->wall.rock = mlx_xpm_file_to_image(game->mlx_instance, "textures/wall/wall_rock", &game->size_x, &game->size_y);
}

void	texture_collectable(t_struct	*game)
{
	game->collectable.img_00 = mlx_xpm_file_to_image(game->mlx_instance, "textures/collectable/collectable_00.xpm", &game->size_x, &game->size_y);
	game->collectable.img_01 = mlx_xpm_file_to_image(game->mlx_instance, "textures/collectable/collectable_01.xpm", &game->size_x, &game->size_y);
	game->collectable.img_02 = mlx_xpm_file_to_image(game->mlx_instance, "textures/collectable/collectable_02.xpm", &game->size_x, &game->size_y);
	game->collectable.img_03 = mlx_xpm_file_to_image(game->mlx_instance, "textures/collectable/collectable_03.xpm", &game->size_x, &game->size_y);
}

void	texture_exit(t_struct	*game)
{
	game->exit.img_closed = mlx_xpm_file_to_image(game->mlx_instance, "textures/exit/exit_closed.xpm", &game->size_x, &game->size_y);
	game->exit.img_open = mlx_xpm_file_to_image(game->mlx_instance, "textures/exit/exit_open.xpm", &game->size_x, &game->size_y);
}


void	get_texture(t_struct *game)
{
	texture_collectable(game);
	texture_player(game);
	texture_wall(game);
	texture_exit(game);
	game->tile.img_00 = mlx_xpm_file_to_image(game->mlx_instance, "textures/tile/tile.xpm", &game->size_x, &game->size_y);
}