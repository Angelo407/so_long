/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_variables.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 09:44:39 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/13 13:10:47 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialisation_variables(t_display_map *map)
{
	map->step_number = 0;
	map->collectible_number = 0;
	map->str = malloc(sizeof(char *) * read_map_axe_y(map));
	map->y = 0;
	map->axe_y = 0;
}
