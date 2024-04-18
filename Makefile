NAME = so_long
NAME_BONUS = so_long_bonus

SRCS = ./Mandatory/so_long.c ./Mandatory/get_next_line.c ./Mandatory/get_next_utiles.c \
		./Mandatory/ft_utiles.c ./Mandatory/ft_split.c ./Mandatory/ft_utiles_1.c \
		./Mandatory/ft_utiles_2.c ./Mandatory/draw_func.c ./Mandatory/draw_func1.c \
		./Mandatory/move_func.c ./Mandatory/ft_itoa.c
SRCS_BONUS = ./Bonus/so_long_bonus.c ./Bonus/get_next_bonus.c ./Bonus/get_utiles_bonus.c \
		./Bonus/ft_utiles_bonus.c ./Bonus/ft_split_bonus.c ./Bonus/draw_func_bonus.c \
		./Bonus/ft_utiles_1_bonus.c ./Bonus/ft_utiles_2_bonus.c ./Bonus/ft_itoa_bonus.c \
		./Bonus/draw_func1_bonus.c ./Bonus/move_func_bonus.c ./Bonus/move_ghost_bonus.c ./Bonus/gost.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -Imlx
T = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
CC = cc
RED = \033[0;31m
GREEN = \033[0;32m

all 			: $(NAME)

$(NAME)			: $(OBJS) ./Mandatory/so_long.h
	@$(CC) $(T) $(OBJS) -o $(NAME)
	@echo "$(GREEN)make so_long"

bonus			: $(NAME_BONUS)

$(NAME_BONUS)	: $(OBJS_BONUS) ./Bonus/so_long_bonus.h
	@$(CC) $(T) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo "$(GREEN)make so_long_bonus"

./Mandatory/%.o : ./Mandatory/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

./Bonus/%.o : ./Bonus/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(RED)clean so_long"

clean :
	@$(RM) $(OBJS) $(OBJS_BONUS)

re : fclean $(NAME)

.PHONY : all clean fclean re bonus