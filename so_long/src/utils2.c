/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:11:39 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/02/25 10:54:24 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// The map can be composed of only these 5 characters:
// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position.


void set_xy(t_coordinate *coordinate, int x, int y)
{
    coordinate->x = x;
    coordinate->y = y;
}

/**
 * Opens a file with the given path and ensures it has a ".ber" extension.
 *
 * @param filepath The path of the file to be opened.
 * @return The file descriptor of the opened file, or -1 if an error occurs.
 */
int open_ber_file(const char *filepath)
{
    int fd;
    int len;

    len = ft_strlen(filepath);
    if (len <= 4 || ft_strncmp(filepath + len - 4, ".ber", 4) != 0)
        throw_error(NULL, "should use *.ber extension", 0);
    fd = open(filepath, O_RDONLY);
    if (fd >= 0)
        return (fd);
    else 
        return (-1);
}