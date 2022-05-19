/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_wall_up_bottom.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:34:54 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/19 12:08:15 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_wall_up_bottom(t_display_map *map)
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
	errors.j = 0;
	while (errors.j < read_map_axe_x(map))
	{
		if (errors.str[0][errors.j] != '1'
			|| errors.str[read_map_axe_y(map) - 1][errors.j] != '1')
		{
			ft_printf("Erreur\nMur haut et/ou bas non conforme !\n");
			free_str(errors.str, errors.i);
			free (map->map);
			exit(0);
		}
		errors.j++;
	}
	free_str(errors.str, read_map_axe_y(map));
	return (0);
}
