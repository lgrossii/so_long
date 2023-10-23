/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_animation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:49:46 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/20 17:17:09 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
void	render_player(t_struct	*game)
{
	int	diff;
	find_el(&game->player.position, game, 'P');
	//printf("y: %d x : %d\n", game->player.position.y, game->player.position.x);
	if (game->player.comp_frame_rate == -1)
	{
		game->player.comp_frame_rate = game->frame_rate;
		game->player.frame_rate = game->frame_rate;
	}
	game->player.frame_rate++;
	diff = game->player.frame_rate - game->player.comp_frame_rate;

		if (game->player.move == -1)
		{
			if (game->player.idle == 4)
				render_player_idle_sx(game, diff);
			else if (game->player.idle == 6)
				render_player_idle_dx(game, diff);
			else if (game->player.idle == 8)
				render_player_idle_up(game, diff);
			else
			render_player_idle(game, diff);
		}
		else if (game->player.move == 123 || game->player.move == 0)
			render_player_left(game, diff);
		else if (game->player.move == 13 || game->player.move == 126)
			render_player_up(game, diff);
		else if (game->player.move == 1 || game->player.move == 125)
			render_player_down(game, diff);
		else if (game->player.move  == 2 || game->player.move == 124)
			render_player_right(game, diff);
		
}

void	render_player_idle(t_struct *game, int n)
{
	if (n >= 1 && n < 4)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_idle_00, game->player.position.x * 64, game->player.position.y * 64);
	if (n >= 4 && n < 8)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_idle_01, game->player.position.x * 64, game->player.position.y * 64);
	if (n >= 8 && n < 12)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_idle_02, game->player.position.x * 64, game->player.position.y * 64);
	if (n >= 12 && n <= 16)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_idle_03, game->player.position.x * 64, game->player.position.y * 64);
	if (n == 16)
	{
		game->player.comp_frame_rate = -1;
		game->player.frame_rate = -1;
		game->player.move = -1;
	}
}

void	render_player_left(t_struct *game, int n)
{
	if (n >= 1 && n < 3)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_sx_00, (game->player.position.x * 64) + 64, game->player.position.y * 64);
	if (n >= 3 && n < 6)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_sx_01, (game->player.position.x * 64) + 43, game->player.position.y * 64);
	if (n >= 6 && n < 9)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_sx_02,  (game->player.position.x * 64) + 22, game->player.position.y * 64);
	if (n >= 9 && n <= 12)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_sx_03,  (game->player.position.x * 64), game->player.position.y * 64);
	if (n == 12)
	{
		game->player.comp_frame_rate = -1;
		game->player.frame_rate = -1;
		game->player.move = -1;
	}
}

void	render_player_up(t_struct *game, int n)
{
	if (n >= 1 && n < 3)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_up_00, game->player.position.x * 64 ,(game->player.position.y * 64) + 64);
	if (n >= 3 && n < 6)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_up_01, game->player.position.x * 64, (game->player.position.y * 64) + 43);
	if (n >= 6 && n < 9)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_up_02, game->player.position.x * 64, (game->player.position.y * 64) + 22);
	if (n >= 9 && n <= 12)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_up_03, game->player.position.x * 64, (game->player.position.y * 64));
	if (n == 12)
	{
		game->player.comp_frame_rate = -1;
		game->player.frame_rate = -1;
		game->player.move = -1;
	}
}

void	render_player_down(t_struct *game, int n)
{
	if (n >= 1 && n < 3)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_down_00, game->player.position.x * 64 ,(game->player.position.y * 64) -64);
	if (n >=3 && n < 6)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_down_01, game->player.position.x * 64, (game->player.position.y * 64) - 43);
	if (n >= 6 && n < 9)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_down_02, game->player.position.x * 64, (game->player.position.y * 64) - 22);
	if (n >= 9 && n <= 12)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_down_03, game->player.position.x * 64, (game->player.position.y * 64));
	if (n == 12)
	{
		game->player.comp_frame_rate = -1;
		game->player.frame_rate = -1;
		game->player.move = -1;
	}
}

void	render_player_right(t_struct *game, int n)
{
	if (n >= 1 && n < 3)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_dx_00, (game->player.position.x * 64) - 64 ,game->player.position.y * 64);
	if (n >= 3 && n < 6)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_dx_01, (game->player.position.x * 64) - 43, game->player.position.y * 64);
	if (n >= 6 && n < 9)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_dx_02, (game->player.position.x * 64) - 22, game->player.position.y * 64);
	if (n >= 9 && n <= 12)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.img_dx_03, (game->player.position.x * 64), game->player.position.y * 64);
	if (n == 12)
	{
		game->player.comp_frame_rate = -1;
		game->player.frame_rate = -1;
		game->player.move = -1;
	}
}

void	render_player_idle_dx(t_struct *game, int n)
{
	if (n >= 1 && n < 4)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.idle_dx_00, game->player.position.x * 64, game->player.position.y * 64);
	if (n >= 4 && n < 8)
			mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.idle_dx_01, game->player.position.x * 64, game->player.position.y * 64);
	if (n >= 8 && n < 12)
			mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.idle_dx_02, game->player.position.x * 64, game->player.position.y * 64);
	if (n >= 12 && n <= 16)
			mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.idle_dx_01, game->player.position.x * 64, game->player.position.y * 64);
	if (n == 16)
	{
		game->player.comp_frame_rate = -1;
		game->player.frame_rate = -1;
		game->player.move = -1;
	}
}

void	render_player_idle_sx(t_struct *game, int n)
{
	if (n >= 1 && n < 4)
			mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.idle_sx_00, game->player.position.x * 64, game->player.position.y * 64);
	if (n >= 4 && n < 8)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.idle_sx_01, game->player.position.x * 64, game->player.position.y * 64);
	if (n >= 8 && n < 12)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.idle_sx_02, game->player.position.x * 64, game->player.position.y * 64);
	if (n >= 12 && n <= 16)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.idle_sx_01, game->player.position.x * 64, game->player.position.y * 64);
	if (n == 16)
	{
		game->player.comp_frame_rate = -1;
		game->player.frame_rate = -1;
		game->player.move = -1;
	}
}

void	render_player_idle_up(t_struct *game, int n)
{
	if (n >= 1 && n < 4)
			mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.idle_up_00, game->player.position.x * 64, game->player.position.y * 64);
	if (n >= 4 && n < 8)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.idle_up_01, game->player.position.x * 64, game->player.position.y * 64);
	if (n >= 8 && n < 12)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.idle_up_02, game->player.position.x * 64, game->player.position.y * 64);
	if (n >= 12 && n <= 16)
		mlx_put_image_to_window(game->mlx_instance, game->mlx_window, game->player.idle_up_01, game->player.position.x * 64, game->player.position.y * 64);
	if (n == 16)
	{
		game->player.comp_frame_rate = -1;
		game->player.frame_rate = -1;
		game->player.move = -1;
	}
}