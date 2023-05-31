/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:21:27 by pcrispol          #+#    #+#             */
/*   Updated: 2023/05/23 16:21:28 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_checkmap(char *path, t_game *all)
{
    int i;

    i = 0;
   all->collen = ft_collen(path);
   all->rowlen = ft_rowlen(path);
   all->map = malloc(sizeof(char *) * all->collen);
   while(i < all->collen)
   {
        all->map[i] = malloc(all->rowlen + 1);
        i++;
   }
}

int ft_rowlen(char *path)
{
    int i;
    char *str;
    int fd;

    fd = open(path, O_RDONLY);
    i = 0;
    while(1)
    {
        str = ft_calloc(2, 1);
        read(fd, str, 1);
        if (str[0] == '\n')
            break;
        i++;
        free(str);
    }
    free(str);
    close(fd);
    return(i);
}

int ft_collen(char *path)
{
    int i;
    char *str;
    int fd;

    fd = open(path, O_RDONLY);
    i = 0;
    while(1)
    {
        str = ft_calloc(2, 1);
        read(fd, str, 1);
        if (str[0] == '\n')
            i++;
        if (str[0] == '\0')
            break;
        free(str);
    }
    free(str);
    close(fd);
    return(i + 1);
}

void    fillmap(char *path, t_game *all)
{
    int i;
    int j;
    int fd;
    char *str;

    i = 0;
    fd = open(path, O_RDONLY);
    while(i < all->collen)
    {
        j = 0;
        while (j <= all->rowlen)
        {
            str = ft_calloc(2, 1);
            read(fd, str, 1);
            if (str[0] == '\n')
            {
                all->map[i][j] = '\0';
                free(str);
                break;
            }
            all->map[i][j] = str[0];
            free(str);
            j++;
        }
        i++;
    }
    close(fd);
}

void    ft_printmap(t_game *all)
{
    int i;

    i = 0;
    while (i < all->collen)
    {
        printf("%s\n", all->map[i]);
        i++;
    }
}

void    checklinelen(t_game *all)
{   
    int i;

    i = 0;
    while (i < all->collen)
    {
        if (ft_strlen(all->map[i]) != all->rowlen)
            exit(0);
        i++;
    }
    if (all->collen == all->rowlen)
        exit(0);
}

void    onlywalls(t_game *all)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (all->map[0][j] != '\0')
    {
        if (all->map[0][j] != '1')
            exit(0);
        j++;
    }
    j = 0;
    while (all->map[all->collen - 1][j] != '\0')
    {
        if (all->map[all->collen - 1][j] != '1')
            exit(0);
        j++;
    }
     while (i < all->collen)
    {
        if (all->map[0][all->rowlen - 1] != '1')
            exit(0);
        i++;
    }
    i = 0;
    while (i < all->collen)
    {
        if (all->map[i][0] != '1')
            exit(0);
        i++;
    }
}

void    put_assets(t_game *all)
{
    int i;
    int j;

    i = 0;
    while (i < all->collen)
    {
        j = 0;
        while (j < all->rowlen)
        {
            if (all->map[i][j] == '1')
                mlx_put_image_to_window(all->mlx, all->win, all->img.wall, j*32, i*32);
            if (all->map[i][j] == '0')
                mlx_put_image_to_window(all->mlx, all->win, all->img.background, j*32, i*32);
            if (all->map[i][j] == 'P')
                mlx_put_image_to_window(all->mlx, all->win, all->img.knight, j*32, i*32);
            if (all->map[i][j] == 'E')
                mlx_put_image_to_window(all->mlx, all->win, all->img.exit, j*32, i*32);
            if (all->map[i][j] == 'C')
                mlx_put_image_to_window(all->mlx, all->win, all->img.key, j*32, i*32);
            j++;
        }
        i++;
    }
}