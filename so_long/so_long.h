/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:48:52 by pcrispol          #+#    #+#             */
/*   Updated: 2023/05/23 15:48:53 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libraries/Libft/libft.h"

typedef struct	s_data {
	void	*wall;
	void	*key;
	void	*knight;
	void	*exit;
	void	*background;
	int		height;
	int		width;
	int		line_length;
	int		endian;
}				t_data;


typedef struct s_game {
    void *mlx;
    void *win;
    int collen;
    int rowlen;
	int c_number;
	int c_progress;
	int n_moves;
	int x;
	int y;
    char **map;
    t_data  img;
}               t_game;

int close_win(t_game *all);
int ft_collen(char *path);
int ft_rowlen(char *path);
int	key_hook (int keycode, void *r);
int	valid_move (t_game *all, char c);
void    checklinelen(t_game *all);
void	c_num (t_game *all);
void	do_move (int keycode, t_game *all);
void    fillmap(char *path, t_game *all);
void	find_pos (t_game *all);
void	free_close(t_game *all);
void	ft_checkmap(char *path, t_game *all);
void    ft_printmap(t_game *all);
void	init_game (t_game *all);
void	move_down(t_game *all);
void	move_up(t_game *all);
void	move_right(t_game *all);
void	move_left(t_game *all);
void    onlywalls(t_game *all);
void    put_assets(t_game *all);
void	swap_img (int keycode, t_game *all);