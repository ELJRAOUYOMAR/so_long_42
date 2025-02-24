/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:11:42 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/02/24 22:49:03 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void free_arr(char **map)
{
    int i;

    i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
}

void destroy_game(t_game *game)
{
    free_arr(game->map->grid);
    free(game->map);
    free(game->player);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    free(game);
}

int exit_game(t_game *game)
{
    destroy_game(game);
    exit(0);
    return (0);
}
void throw_error(t_game *game, char *msg, int error)
{
    ft_printf("Error:\n");
    if (msg)
        ft_printf("%s", msg);
    if (error)
        ft_printf("%s", strerror(error));
    if (game)
        destroy_game(game);
    exit(1);
}