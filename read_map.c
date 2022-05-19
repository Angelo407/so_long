/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:50:18 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/09 14:47:34 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_wall(t_display_map *map)
{
	if (map->str[map->y][map->x] == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->wall, map->axe_x, map->axe_y);
}

void	read_player(t_display_map *map)
{
	if (map->str[map->y][map->x] == 'P')
	{
		map->p_x = map->axe_x;
		map->p_y = map->axe_y;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->player, map->axe_x, map->axe_y);
	}
}

void	read_collectible(t_display_map *map)
{
	if (map->str[map->y][map->x] == 'C')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->collectible, map->axe_x, map->axe_y);
		map->collectible_number++;
	}
}

void	read_exit(t_display_map *map)
{
	if (map->str[map->y][map->x] == 'E')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->exit, map->axe_x, map->axe_y);
		map->exit_axe_x = map->axe_x;
		map->exit_axe_y = map->axe_y;
	}	
}
