/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_invalid_letter.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:33:54 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/20 18:15:20 by aprosper         ###   ########.fr       */
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

// int	error_check_invalid_letter(t_display_map *map)
// {
// 	t_errors	errors;

// 	errors.fd = open(map->map, O_RDONLY);
// 	errors.i = 0;
// 	errors.str = malloc(sizeof(char *) * read_map_axe_y(map));
// 	while (errors.i < read_map_axe_y(map))
// 	{
// 		errors.str[errors.i] = get_next_line(errors.fd);
// 		errors.str2 = errors.str[errors.i];
// 		errors.k = 0;
// 		while (errors.str2[errors.k] != '\n')
// 		{
// 			if (errors.str2[errors.k] == '1' || errors.str2[errors.k] == '0'
// 				|| errors.str2[errors.k] == 'P'
// 				|| errors.str2[errors.k] == 'E' || errors.str2[errors.k] == 'C')
// 				errors.k++;
// 			else
// 			{
// 				ft_printf("Erreur\nIl y a min un char invalide ds la map !\n");
// 				free_str(map->str, map->i + 1);
// 				return (1);
// 			}
// 		}
// 		errors.i++;
// 	}
// 	free_str(errors.str, errors.i);
// 	return (0);
// }



// int	error_check_invalid_letter(t_display_map *map)
// {
// 	int		fd;
// 	int		i;
// 	int		k;
// 	char	**str;
// 	char	*str2;

// 	fd = open(map->map, O_RDONLY);
// 	i = 0;
// 	str = malloc(sizeof(char *) * read_map_axe_y(map));
// 	while (i < read_map_axe_y(map))
// 	{
// 		str[i] = get_next_line(fd);
// 		str2 = str[i];
// 		k = 0;
// 		while (str2[k] != '\n')
// 		{
// 			if (str2[k] == '1' || str2[k] == '0' || str2[k] == 'P'
// 				|| str2[k] == 'E' || str2[k] == 'C')
// 				k++;
// 			else
// 			{
// 				ft_printf("Erreur\nIl y a min un char invalide ds la map !\n");
// 				free_str(str, i + 1);
// 				return (1);
// 			}
// 		}
// 		i++;
// 	}
// 	free_str(str, i);
// 	return (0);
// }
