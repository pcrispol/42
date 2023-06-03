/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:22:51 by pcrispol          #+#    #+#             */
/*   Updated: 2023/03/07 15:22:55 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	free_close(t_game *all)
{
	if (all->img.key)
		mlx_destroy_image(all->mlx, all->img.key);
	if (all->img.wall)
		mlx_destroy_image(all->mlx, all->img.wall);
	if (all->img.exit)
		mlx_destroy_image(all->mlx, all->img.exit);
	if (all->img.knight)
		mlx_destroy_image(all->mlx, all->img.knight);
	if (all->img.background)
		mlx_destroy_image(all->mlx, all->img.background);
	if (all->win)
		mlx_destroy_window(all->mlx, all->win);
	if (all->mlx)
	{
		mlx_destroy_display(all->mlx);
		free(all->mlx);
	}
	exit (0);
}
void	init_game (t_game *all)
{
	all->collen = 0;
	all->rowlen = 0;
	all->c_number = 0;
	all->n_moves = 0;
	all->c_progress = 0;
	all->x = 0;
	all->y = 0;
}
void	c_num (t_game *all)
{
	int	i;
	int j;
	int p;
	int	e;

	i = 0;
	e = 0;
	p = 0;
	while (i < all->collen)
	{
		j = 0;
		while (j < all->rowlen)
		{
			if (all->map[i][j] == 'E')
				e += 1;
			if (all->map[i][j] == 'P')
				p += 1;
			if (all->map[i][j] == 'C')
				all->c_number += 1;
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 || all->c_number < 1)
		free_close(all);
}

int	valid_move (t_game *all, char c)
{
	int x;
	int y;

	x = all->x;
	y = all->y;
	if (c == 'a' && all->map[y][x-1] != '1')
	{
		if (all->map[y][x-1] == 'E' && all->c_number > all->c_progress)
			return (1);
		return (0);
	}
	if (c == 'd' && all->map[y][x+1] != '1')
	{
		if (all->map[y][x+1] == 'E' && all->c_number > all->c_progress)
			return (1);
		return (0);
	}
	if (c == 'w' && all->map[y-1][x] != '1') 
	{
		if (all->map[y-1][x] == 'E' && all->c_number > all->c_progress)
			return (1);
		return (0);
	}
	if (c == 's' && all->map[y+1][x] != '1') 
	{
		if (all->map[y+1][x] == 'E' && all->c_number > all->c_progress)
			return (1);
		return (0);
	}
	return (1);
}

void	move_left(t_game *all)
{
	int x;
	int y;

	x = all->x;
	y = all->y;
	mlx_put_image_to_window(all->mlx, all->win, all->img.background, x*32, y*32);
	mlx_put_image_to_window(all->mlx, all->win, all->img.knight, (x-1)*32, y*32);
	if (all->map[y][x-1] == 'C')
	{
		all->c_progress += 1;
		all->map[y][x-1] = '0';
	}
	if (all->map[y][x-1] == 'E' && all->c_number == all->c_progress)
		free_close(all);
	all->x -= 1;
	all->n_moves += 1;
}

void	move_right(t_game *all)
{
	int x;
	int y;

	x = all->x;
	y = all->y;
	mlx_put_image_to_window(all->mlx, all->win, all->img.background, x*32, y*32);
	mlx_put_image_to_window(all->mlx, all->win, all->img.knight, (x+1)*32, y*32);
	if (all->map[y][x+1] == 'C')
	{
		all->c_progress += 1;
		all->map[y][x+1] = '0';
	}
	if (all->map[y][x+1] == 'E' && all->c_number == all->c_progress)
		free_close(all);
	all->x += 1;
	all->n_moves += 1;
}

void	move_up(t_game *all)
{
	int x;
	int y;

	x = all->x;
	y = all->y;
	mlx_put_image_to_window(all->mlx, all->win, all->img.background, x*32, y*32);
	mlx_put_image_to_window(all->mlx, all->win, all->img.knight, x*32, (y-1)*32);
	if (all->map[y-1][x] == 'C')
	{
		all->c_progress += 1;
		all->map[y-1][x] = '0';
	}
	if (all->map[y-1][x] == 'E' && all->c_number == all->c_progress)
		free_close(all);
	all->y -= 1;
	all->n_moves += 1;
}

void	move_down(t_game *all)
{
	int x;
	int y;

	x = all->x;
	y = all->y;
	mlx_put_image_to_window(all->mlx, all->win, all->img.background, x*32, y*32);
	mlx_put_image_to_window(all->mlx, all->win, all->img.knight, x*32, (y+1)*32);
	if (all->map[y+1][x] == 'C')
	{
		all->c_progress += 1;
		all->map[y+1][x] = '0';
	}
	if (all->map[y+1][x] == 'E' && all->c_number == all->c_progress)
		free_close(all);
	all->y += 1;
	all->n_moves += 1;
}

void	swap_img (int keycode, t_game *all)
{
	if (keycode == 97)
		move_left (all);
	if (keycode == 100)
		move_right (all);
	if (keycode == 119)
		move_up (all);
	if (keycode == 115)
		move_down (all);
}

void	do_move (int keycode, t_game *all)
{
	if (keycode == 97 && valid_move (all, 'a') == 0)
		swap_img (keycode, all);
	if (keycode == 100 && valid_move (all, 'd') == 0)
		swap_img (keycode, all);
	if (keycode == 119 && valid_move (all, 'w') == 0)
		swap_img (keycode, all);
	if (keycode == 115 && valid_move (all, 's') == 0)
		swap_img (keycode, all);
}

int	key_hook (int keycode, void *r)
{
	t_game *all;

	all = (t_game *)r;
	if (keycode == 97 || keycode == 100 || keycode == 115 || keycode == 119)
		do_move (keycode, all);
	return (keycode);
}

int close_win(t_game *all)
{
	exit(1);
}

void	find_pos (t_game *all)
{
	int i;
    int j;

    i = 0;
    while (i < all->collen)
    {
        j = 0;
        while (j < all->rowlen)
        {
            if (all->map[i][j] == 'P')
			{
				all->x = j;
				all->y = i;
				return ;
			}
            j++;
        }
        i++;
    }
}

int	main(int ac, char **av)
{
	t_game	all;

	if(ac != 2)
		return(0);
	else
	{
		init_game(&all);
		ft_checkmap(av[1], &all);
		fillmap(av[1], &all);
		onlywalls(&all);
		find_pos(&all);
		c_num (&all);
		printf("%d\n", all.c_number);
		all.mlx = mlx_init();
		all.win = mlx_new_window(all.mlx, all.rowlen * 32, all.collen * 32, "so_long");
		ft_printmap(&all);
		mlx_hook(all.win, 17, 0, close_win, &all);
		mlx_key_hook(all.win, key_hook, &all);
		all.img.knight = mlx_xpm_file_to_image(all.mlx, "./img/knight.xpm", &all.img.width, &all.img.height);
		all.img.background = mlx_xpm_file_to_image(all.mlx, "./img/background.xpm", &all.img.width, &all.img.height);
		all.img.wall = mlx_xpm_file_to_image(all.mlx, "./img/wall.xpm", &all.img.width, &all.img.height);
		all.img.exit = mlx_xpm_file_to_image(all.mlx, "./img/exit.xpm", &all.img.width, &all.img.height);
		all.img.key = mlx_xpm_file_to_image(all.mlx, "./img/key.xpm", &all.img.width, &all.img.height);
		put_assets(&all);
		mlx_loop(all.mlx);
	}
}