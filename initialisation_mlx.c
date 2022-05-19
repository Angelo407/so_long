/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 09:30:42 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/13 11:38:29 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialisation_mlx(t_display_map *map)
{
	map->size_image = 50;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr,
			read_map_axe_x(map) * 50, read_map_axe_y(map) * 50, "mlx 42");
	map->background = mlx_xpm_file_to_image(map->mlx_ptr,
			"images/sablecopy.xpm", &map->size_image, &map->size_image);
	map->player = mlx_xpm_file_to_image(map->mlx_ptr,
			"images/player.xpm", &map->size_image, &map->size_image);
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr,
			"images/rock.xpm", &map->size_image, &map->size_image);
	map->exit = mlx_xpm_file_to_image(map->mlx_ptr,
			"images/exit.xpm", &map->size_image, &map->size_image);
	map->collectible = mlx_xpm_file_to_image(map->mlx_ptr,
			"images/money.xpm", &map->size_image, &map->size_image);
}
