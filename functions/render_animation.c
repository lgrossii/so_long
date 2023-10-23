/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:34:36 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/20 23:04:49 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render_animation(t_struct	*game)
{
	//char	*s;
	//char	*n;

	//s = "numero mosse";
	//n = ft_itoa(game->moves_number);
	//s = ft_strjoin(s, ft_itoa(game->moves_number));
	if (game->frame_rate == 24)
		game->frame_rate = 1;
	else
		game->frame_rate++;
	mlx_clear_window(game->mlx_instance, game->mlx_window);
	render_perimetral_wall(game);
	//printf("%d\n", game->frame_rate);
	render_singles(game);
	render_player(game);
	//if (game->enemy_status == 1)
		render_enemy_animation(game);
	//mlx_string_put(game->mlx_instance, game->mlx_window, 0 * 64, (game->y + 1) * 64 - 32, 0x0000ff, "ciao");
	//free (n);
	//free (s);
	return (0);
}