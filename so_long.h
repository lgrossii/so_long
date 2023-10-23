/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:48:12 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/23 18:28:25 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
#define SO_LONG_H
#include	"struct_textures.h"
#include	"fcntl.h"
#include	"src/libft/libft.h"
#include 	"stdio.h"
#include	<math.h>
#include 	"src/ft_printf/ft_printf.h"

/************************************************/
/*					map_check					*/

char	**get_map(int	fd, t_struct *game);

int	check_map(char	**map, t_struct *game);

int	check_square(char	**map, t_struct *game);

int	check_walls(char **map, t_struct *game);

int	check_starter(char	**map);

int	check_enemy(char	**map, t_struct	*game);

int	check_collectable(char	**map);

/************************************************/
/*					render_animation			*/

int	render_animation(t_struct	*game);

/************************************************/
/*					render_singles				*/

void	render_perimetral_wall(t_struct *game);

void	render_singles(t_struct	*game);

void	render_collectable(t_struct	*game, int x, int y);

/************************************************/
/*					UTILS						*/

void	find_el(t_coordinate	*element, t_struct *game, char c);

int	no_more_coll(t_struct	*game);

/************************************************/
/*					MOVES						*/

void	calculate_next_move(t_struct *game);

int	check_move(t_struct	*game);

int	which_n(int	n, t_struct *game);

/************************************************/
/*					RENDER_PLAYER_ANIM			*/

void	render_player(t_struct	*game);

void	render_player_idle(t_struct *game, int n);

void	render_player_left(t_struct *game, int n);

void	render_player_up(t_struct *game, int n);

void	render_player_down(t_struct *game, int n);

void	render_player_right(t_struct *game, int n);

void	render_player_idle_sx(t_struct *game, int n);

void	render_player_idle_dx(t_struct *game, int n);

void	render_player_idle_up(t_struct *game, int n);

/************************************************/
/*					FREE GAME					*/

void	free_game(t_struct	*game);

void	free_map(char	**map);

/************************************************/
/*					ENEMY 						*/

void	render_enemy_animation(t_struct	*game);

void	enemy_goes_up(t_struct	*game, int n);

void	enemy_goes_down(t_struct	*game, int n);

void	enemy_goes_sx(t_struct	*game, int n);

void	enemy_goes_dx(t_struct	*game, int n);

void	enemy_moves(t_struct	*game);

char	where_n_will_land(t_struct *game, int n);

void	do_n_move(t_struct	*game, int n);

int		all_rocks(t_struct	*game);

#endif