/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:59:10 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/08 23:50:33 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	render_walls(t_game_state *game)
{
	int		x;
	t_ray	ray;
	t_draw	draw;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(game, &ray, x);
		dda(game, &ray);
		compute_wall(&ray, &draw);
		draw_wall(game, &ray, &draw, x);
		x++;
	}
}
