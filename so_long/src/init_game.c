/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:48:43 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/02/24 22:10:34 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game *init_game(void)
{
    t_game  *game;

    game = (t_game *) malloc(sizeof(t_game));
    if (!game)
        return (NULL);
    game->mlx = NULL;
    game->win = NULL;
    game->moves = 0;
    game->map = NULL;
    game->player = NULL;
    return (game);
}