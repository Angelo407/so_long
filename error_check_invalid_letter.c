/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_invalid_letter.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:33:54 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/23 12:29:48 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_print(char *str2)
{
	ft_printf("Erreur\nIl y a min un char invalide ds la map !\n");
	free(str2);
}

int	error_check_invalid_letter(t_display_map *map, char *str2)
{
	int		i;
	int		k;
	int		fd;

	fd = open(map->map, O_RDONLY);
	i = -1;
	while (++i < read_map_axe_y(map))
	{
		str2 = get_next_line(fd);
		k = 0;
		while (str2[k] != '\n')
		{
			if (str2[k] == '1' || str2[k] == '0' || str2[k] == 'P'
				|| str2[k] == 'E' || str2[k] == 'C')
				k++;
			else
			{
				free_print(str2);
				return (1);
			}
		}
		free(str2);
	}
	return (0);
}
