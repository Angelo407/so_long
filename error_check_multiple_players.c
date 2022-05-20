/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_multiple_players.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:52:45 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/20 17:14:17 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_check_multiple_players(t_display_map *map)
{
	t_errors	errors;

	errors.fd = open(map->map, O_RDONLY);
	errors.i = 0;
	errors.j = 0;
	errors.str = malloc(sizeof(char *) * read_map_axe_y(map));
	while (errors.i < read_map_axe_y(map))
	{
		errors.str[errors.i] = get_next_line(errors.fd);
		if (ft_strchr(errors.str[errors.i], 'P') != NULL)
			errors.j++;
		if (errors.j > 1)
		{
			ft_printf("Erreur\nIl y a plus d'un player !\n");
			free_str(errors.str, errors.i + 1);
			return (1);
		}	
		errors.i++;
	}
	free_str(errors.str, read_map_axe_y(map));
	return (0);
}
