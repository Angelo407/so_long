/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:33:53 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/19 12:02:46 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_check_player(t_display_map *map)
{
	int		i;
	char	**str;
	int		fd;

	fd = open(map->map, O_RDONLY);
	i = 0;
	str = malloc(sizeof(char *) * read_map_axe_y(map));
	while (i < read_map_axe_y(map))
	{
		str[i] = get_next_line(fd);
		if (ft_strchr(str[i], 'P') != NULL)
		{
			free_str(str, i + 1);
			return (0);
		}	
		else
			i++;
	}
	ft_printf("Erreur\nIl manque le player !\n");
	free_str(str, read_map_axe_y(map));
	free (map->map);
	exit(0);
}
