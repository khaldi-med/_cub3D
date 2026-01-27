/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 23:11:45 by mohkhald          #+#    #+#             */
/*   Updated: 2026/01/06 23:49:44 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static bool	ft_is_empty(t_map *map, int x, int y)
{
	int	len;

	if (y < 0 || y >= map->height || x < 0)
		return (true);
	len = (int)ft_strlen(map->grid[y]);
	if (x >= len)
		return (true);
	if (map->grid[y][x] == ' ')
		return (true);
	return (false);
}

bool	ft_check_map_gaps(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == '0' || ft_is_player_char(map->grid[y][x]))
			{
				if (ft_is_empty(map, x + 1, y) || ft_is_empty(map, x - 1, y)
					|| ft_is_empty(map, x, y + 1) || ft_is_empty(map, x, y - 1))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
