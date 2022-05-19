/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:32:38 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/18 13:10:47 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, t_display_map *map)
{
	move_down(key, map);
	move_up(key, map);
	move_left(key, map);
	move_right(key, map);
	exit_game_esc(key, map);
	catch_collectible(key, map);
	return (0);
}
