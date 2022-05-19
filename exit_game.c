/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:35:37 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/19 12:16:32 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_display_map *map)
{
	free_and_exit(map);
	exit(0);
}

int	exit_game_esc(int key, t_display_map *map)
{
	if (key == 53)
	{
		free_and_exit(map);
		exit (0);
	}
	return (0);
}

void	free_and_exit(t_display_map *map)
{
	int	i;
	int	ligne;

	i = 0;
	ligne = read_map_axe_y(map);
	mlx_destroy_image(map->mlx_ptr, map->background);
	mlx_destroy_image(map->mlx_ptr, map->wall);
	mlx_destroy_image(map->mlx_ptr, map->player);
	mlx_destroy_image(map->mlx_ptr, map->collectible);
	mlx_destroy_image(map->mlx_ptr, map->exit);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	while (i < ligne)
	{
		if (map->str[i])
			free(map->str[i]);
		i++;
	}
	free(map->str);
	close (map->fd);
}
