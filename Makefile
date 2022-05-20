NAME = so_long

CC = gcc
CFLAG = -Wall -Wextra -Werror -Lmlx -lmlx -framework OpenGL -framework AppKit

RM = rm
RMFLAG = -f

INCLUDES = ./so_long.h

SRC_LIBFT =	\
	libft/ft_strchr.c	\
	libft/ft_strdup.c	\
	libft/ft_strjoin.c	\
	libft/ft_strlen.c	\
	libft/get_next_line.c	\
	libft/ft_strnstr.c

SRC_LIBFT_PRINTF =	\
	ft_printf/ft_printf.c	\
	ft_printf/ft_prct_c_prct_s_to_str.c	\
	ft_printf/ft_prct_d_i_u_to_str.c	\
	ft_printf/ft_prct_x_xmaj_p_to_str.c	\
	ft_printf/ft_dec_to_hexa.c	\
	ft_printf/ft_dec_to_hexa_maj.c	\
	ft_printf/ft_putptr.c	\
	ft_printf/ft_itoa_char_hexa.c	\
	ft_printf/ft_nbrlen_variants.c	\
	ft_printf/ft_putstr.c	\
	ft_printf/ft_putnbr.c	\
	ft_printf/ft_putchar.c	

SRC_SO_LONG =	\
	catch_collectible.c	\
	deal_key.c	\
	error_check_exit.c	\
	error_check_invalid_letter.c	\
	error_check_multiple_exits.c	\
	error_check_item.c	\
	error_check_player.c	\
	error_check_multiple_players.c	\
	error_wall_left_right.c	\
	error_wall_up_bottom.c	\
	error_check_rectangle.c	\
	errors_all.c	\
	exit_game.c	\
	initialisation_mlx.c	\
	initialisation_variables.c	\
	movements.c	\
	read_map_axe_x.c	\
	read_map_axe_y.c	\
	read_map.c	\
	move_count.c	\
	so_long.c

SRCS =	\
	$(SRC_LIBFT)	\
	$(SRC_LIBFT_PRINTF)	\
	$(SRC_SO_LONG)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)
	make clean -C mlx

re : fclean all
	make re -C mlx

.c.o : $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	make all -C mlx
	$(CC) $(SRCS) $(CFLAG) -o $(NAME)
