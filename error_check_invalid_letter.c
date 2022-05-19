/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_invalid_letter.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:33:54 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/19 18:50:52 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_check_invalid_letter(t_display_map *map)
{
	int		fd;
	int		i;
	int		k;
	char	**str;
	char	*str2;

	fd = open(map->map, O_RDONLY);
	i = 0;
	str = malloc(sizeof(char *) * read_map_axe_y(map));
	while (i < read_map_axe_y(map))
	{
		str[i] = get_next_line(fd);
		str2 = str[i];
		
		k = 0;
		printf("%s\n", str2);
		while (str2[k] != '\n')
		{
			if (str2[k] == '1' || str2[k] == '0')
				k++;
			else
			{
				printf("Erreur\nIl y a un ou plusieurs caractère(s) invalide(s) dans la map !\n");
				exit(0);
			}
		}
		i++;
	}
	
//	free_str(str, i + 1);
	return (0);
}
