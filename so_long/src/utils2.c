/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:11:39 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/02/24 23:23:57 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void set_xy(t_coordinate *coordinate, int x, int y)
{
    coordinate->x = x;
    coordinate->y = y;
}

int 