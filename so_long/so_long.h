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
	int x;
	int y;
    char **map;
    t_data  img;
}               t_game;

int ft_collen(char *path);
int ft_rowlen(char *path);
void ft_checkmap(char *path, t_game *all);
void    fillmap(char *path, t_game *all);
void    ft_printmap(t_game *all);
void    onlywalls(t_game *all);
void    put_assets(t_game *all);
