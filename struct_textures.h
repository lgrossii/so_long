/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_textures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:34:11 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/21 20:04:00 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STRUCT_TEXTURES_H
#define	STRUCT_TEXTURES_H

#include "src/mlx/mlx.h"

typedef	struct s_coordinate
{
	int	x;
	int	y;
} t_coordinate;

typedef	struct s_enemy
{
	void	*up_00;
	void	*up_01;
	void	*up_02;
	void	*up_03;
	void	*sx_00;
	void	*sx_01;
	void	*sx_02;
	void	*sx_03;
	void	*dx_00;
	void	*dx_01;
	void	*dx_02;
	void	*dx_03;
	void	*down_00;
	void	*down_01;
	void	*down_02;
	void	*down_03;
	int		path;
	t_coordinate	position;
	int		frame_rate;
	int		comp_frame_rate;
	int		n_moves;
	int		comp_moves;
} t_enemy;

typedef	struct s_wall
{
	void	*img_angle_00;
	void	*img_angle_0x;
	void	*img_angle_y0;
	void	*img_angle_yx;
	void	*img_up;
	void	*img_down;
	void	*img_dx;
	void	*img_sx;
	void	*rock;
} t_wall;

typedef	struct s_collectable
{
	void	*img_00;
	void	*img_01;
	void	*img_02;
	void	*img_03;

} t_collectable;

typedef	struct s_tile
{
	void	*img_00;
} t_tile;

typedef	struct s_player
{
	void	*img_up_00;
	void	*img_up_01;
	void	*img_up_02;
	void	*img_up_03;
	void	*img_down_00;
	void	*img_down_01;
	void	*img_down_02;
	void	*img_down_03;
	void	*img_dx_00;
	void	*img_dx_01;
	void	*img_dx_02;
	void	*img_dx_03;
	void	*img_sx_00;
	void	*img_sx_01;
	void	*img_sx_02;
	void	*img_sx_03;
	void	*img_idle_00;
	void	*img_idle_01;
	void	*img_idle_02;
	void	*img_idle_03;
	void	*idle_dx_00;
	void	*idle_dx_01;
	void	*idle_dx_02;
	void	*idle_sx_00;
	void	*idle_sx_01;
	void	*idle_sx_02;
	void	*idle_up_00;
	void	*idle_up_01;
	void	*idle_up_02;

	t_coordinate	position;
	t_coordinate	next_move;
	int		idle;
	int		move;
	int		frame_rate;
	int		comp_frame_rate;
}	t_player;

typedef	struct s_exit
{
	void	*img_open;
	void	*img_closed;
} t_exit;

typedef	struct s_struct
{
	int				size_x;
	int				size_y;
	t_wall			wall;
	t_collectable	collectable;
	t_player		player;
	t_tile			tile;
	t_exit			exit;
	t_enemy			enemy;
	char			**map;
	int				x;
	int				y;
	int				n_move;
	void			*mlx_instance;
	void			*mlx_window;
	int				frame_rate;
	int				moves_number;
	int				enemy_status;
} t_struct;


void	texture_player(t_struct	*game);

void	get_player_idles(t_struct	*game);

void	get_player_movement_up_down(t_struct	*game);

void	get_player_movements_dx_sx(t_struct	*game);

void	texture_wall(t_struct	*game);

void	texture_collectable(t_struct	*game);

void	texture_exit(t_struct	*game);

void	get_texture(t_struct *game);

void	get_enemy_texture(t_struct	*game);
#endif