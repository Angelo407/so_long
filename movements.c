/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:41:37 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/19 19:03:15 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_down(int key, t_display_map *map)
{
	if (key == 1)
	{
		if (map->str[map->p_y / 50 + 1][map->p_x / 50] == '1')
			return (0);
		if (map->str[map->p_y / 50 + 1][map->p_x / 50] == 'E'
			&& map->collectible_number != 0)
			return (0);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->background, map->p_x, map->p_y);
		map->p_y += 50;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->player, map->p_x, map->p_y);
		move_count(key, map);
	}
	return (0);
}

int	move_up(int key, t_display_map *map)
{
	if (key == 13)
	{
		if (map->str[map->p_y / 50 - 1][map->p_x / 50] == '1')
			return (0);
		if (map->str[map->p_y / 50 - 1][map->p_x / 50 ] == 'E'
			&& map->collectible_number != 0)
			return (0);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->background, map->p_x, map->p_y);
		map->p_y -= 50;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->player, map->p_x, map->p_y);
		move_count(key, map);
	}
	return (0);
}

int	move_left(int key, t_display_map *map)
{
	if (key == 0)
	{
		if (map->str[map->p_y / 50][map->p_x / 50 - 1] == '1')
			return (0);
		if (map->str[map->p_y / 50][map->p_x / 50 - 1] == 'E'
			&& map->collectible_number != 0)
			return (0);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->background, map->p_x, map->p_y);
		map->p_x -= 50;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->player, map->p_x, map->p_y);
		move_count(key, map);
	}
	return (0);
}

int	move_right(int key, t_display_map *map)
{
	if (key == 2)
	{
		if (map->str[map->p_y / 50][map->p_x / 50 + 1] == '1')
			return (0);
		if (map->str[map->p_y / 50][map->p_x / 50 + 1] == 'E'
			&& map->collectible_number != 0)
			return (0);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->background, map->p_x, map->p_y);
		map->p_x += 50;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->player, map->p_x, map->p_y);
		move_count(key, map);
		if (map->str[map->p_y / 50][map->p_x / 50] == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->background, map->p_x, map->p_y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->player, map->p_x, map->p_y);
	}

	return (0);
}
