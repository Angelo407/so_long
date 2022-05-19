/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:37:03 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/17 19:01:29 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_count(int key, t_display_map *map)
{
	map->step_number++;
	ft_printf("Nombre de mouvements : %d\n", map->step_number);
	return (0);
}

/*
int	move_count(int key, t_display_map *map)
{
	if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		map->step_number++;
		ft_printf("Nombre de mouvements : %d\n", map->step_number);
	}
	return (0);
}
*/