/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 08:29:09 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/20 18:13:40 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include <stdarg.h>
# include <limits.h>

typedef struct errors_util{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**str;
	char	*str2;
	int		fd;
	int		i;
	int		j;
	int		k;
}	t_errors;

typedef struct display_map_util{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**str;
	char	*map;
	int		fd;
	int		i;
	int		j;
	int		x;
	int		y;
	int		axe_x;
	int		axe_y;
	int		p_x;
	int		p_y;
	void	*background;
	void	*nothing;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	int		size_image;
	int		exit_axe_x;
	int		exit_axe_y;
	int		step_number;
	int		collectible_number;
}	t_display_map;

int		ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s, char c);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
int		ft_strnstr(const char *big, const char *little, int len);
//-------------------------------------------------------------------
int		ft_printf(const char *str, ...);
int		ft_dec_to_hexa(unsigned int nb);
int		ft_dec_to_hexa_maj(unsigned int nb);
int		ft_dec_to_hexa_p(unsigned long long int nb);
size_t	ft_nbrlen(int nb);
size_t	ft_nbrlen_plus(unsigned int nb);
size_t	ft_nbrlen_hexa(unsigned int nb);
size_t	ft_nbrlen_hexa_p(unsigned long long int nb);
char	ft_itoa_char_hexa(int nbr);
int		ft_putptr(unsigned long long int nb);
int		ft_prct_c_prct_to_str(char *str, int idx, va_list ap);
int		ft_prct_s_to_str(char *str, int idx, va_list ap);
int		ft_prct_d_i_u_to_str(char *str, int idx, va_list ap);
int		ft_prct_x_xmaj_p_to_str(char *str, int idx, va_list ap);
void	ft_putstr(const char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
//-------------------------------------------------------------------
int		read_map_axe_x(t_display_map *map);
int		read_map_axe_y(t_display_map *map);
int		error_wall_up_bottom(t_display_map *map);
int		error_wall_left_right(t_display_map *map);
int		error_check_exit(t_display_map *map);
int		error_check_invalid_letter(t_display_map *map, char *str2);
int		error_check_multiple_exits(t_display_map *map);
int		error_check_item(t_display_map *map);
int		error_check_player(t_display_map *map);
int		error_check_multiple_players(t_display_map *map);
int		error_check_rectangle(t_display_map *map);
int		errors_all(t_display_map *map);
int		exit_game_esc(int key, t_display_map *map);
int		destroy_window(t_display_map *map);
void	initialisation_mlx(t_display_map *map);
void	initialisation_variables(t_display_map *map);
int		deal_key(int key, t_display_map *map);
int		move_up(int key, t_display_map *map);
int		move_down(int key, t_display_map *map);
int		move_left(int key, t_display_map *map);
int		move_right(int key, t_display_map *map);
int		move_count(int key, t_display_map *map);
int		catch_collectible(int key, t_display_map *map);
void	read_wall(t_display_map *map);
void	read_collectible(t_display_map *map);
void	read_exit(t_display_map *map);
void	read_player(t_display_map *map);
void	free_str(char **str, int line);
void	free_and_exit(t_display_map *map);

#endif