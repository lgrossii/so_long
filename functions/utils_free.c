/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:28:49 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/23 12:41:23 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_game(t_struct	*game)
{
	int	i;

	i = 0;
	while (i < game->y)
		free(game->map[i++]);
	free (game->map);
	free_player(game);
	free_wall_collectable(game);
}

void	free_wall_collectable(t_struct *game)
{
	free (game->wall.img_angle_00);
	free (game->wall.img_angle_y0);
	free (game->wall.img_angle_0x);
	free (game->wall.img_angle_yx);
	free (game->wall.img_up);
	free (game->wall.img_down);
	free (game->wall.img_sx);
	free (game->wall.img_dx);
	free (game->wall.rock);
	free (game->collectable.img_00);
	free (game->collectable.img_01);
	free (game->collectable.img_02);
	free (game->collectable.img_03);
}

void	free_player(t_struct *game)
{
	free (game->player.img_down_00);
	free (game->player.img_down_01);
	free (game->player.img_down_02);
	free (game->player.img_down_03);
	free (game->player.img_up_00);
	free (game->player.img_up_01);
	free (game->player.img_up_02);
	free (game->player.img_up_03);
	free (game->player.img_dx_00);
	free (game->player.img_dx_01);
	free (game->player.img_dx_02);
	free (game->player.img_dx_03);
	free (game->player.img_sx_00);
	free (game->player.img_sx_01);
	free (game->player.img_sx_02);
	free (game->player.img_sx_03);
	free (game->player.img_idle_00);
	free (game->player.img_idle_01);
	free (game->player.img_idle_02);
	free (game->player.img_idle_03);
	free_idles(game);
}

void	free_idles(t_struct *game)
{
	free (game->player.idle_dx_00);
	free (game->player.idle_dx_01);
	free (game->player.idle_dx_02);
	free (game->player.idle_sx_00);
	free (game->player.idle_sx_01);
	free (game->player.idle_sx_02);
	free (game->player.idle_up_00);
	free (game->player.idle_up_01);
	free (game->player.idle_up_02);
}

void	free_enemy_textures(t_struct *game)
{
	free (game->enemy.down_00);
	free (game->enemy.down_01);
	free (game->enemy.down_02);
	free (game->enemy.down_03);
	free (game->enemy.up_00);
	free (game->enemy.up_01);
	free (game->enemy.up_02);
	free (game->enemy.up_03);
	free (game->enemy.sx_00);
	free (game->enemy.sx_01);
	free (game->enemy.sx_02);
	free (game->enemy.sx_03);
	free (game->enemy.dx_00);
	free (game->enemy.dx_01);
	free (game->enemy.dx_02);
	free (game->enemy.dx_03);
}