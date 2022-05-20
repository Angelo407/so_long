/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_wall_left_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:34:33 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/20 17:14:32 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_wall_left_right(t_display_map *map)
{
	t_errors	errors;

	errors.fd = open(map->map, O_RDONLY);
	errors.i = 0;
	errors.str = malloc(sizeof(char *) * read_map_axe_y(map));
	while (errors.i < read_map_axe_y(map))
	{
		errors.str[errors.i] = get_next_line(errors.fd);
		errors.i++;
	}
	errors.i = 0;
	while (errors.i < read_map_axe_y(map) - 1)
	{
		if (errors.str[errors.i][0] != '1'
			|| errors.str[errors.i][read_map_axe_x(map) - 1] != '1')
		{
			ft_printf("Erreur\nMur de gauche et/ou droite non conforme !\n");
			free_str(errors.str, read_map_axe_y(map));
			return (1);
		}
		errors.i++;
	}
	free_str(errors.str, read_map_axe_y(map));
	return (0);
}
