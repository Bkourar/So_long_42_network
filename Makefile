NAME = so_long
NAME_BONUS = so_long_bonus

SRCS = $(addprefix Mandatory/, so_long.c\
					get_next_line.c get_next_utiles.c \
					ft_utiles.c ft_split.c ft_utiles_1.c \
					ft_utiles_2.c draw_func.c draw_func1.c \
					move_func.c ft_itoa.c)
SRCS_BONUS = $(addprefix Bonus/, so_long_bonus.c get_next_bonus.c get_utiles_bonus.c \
							ft_utiles_bonus.c ft_split_bonus.c draw_func_bonus.c \
							ft_utiles_1_bonus.c ft_utiles_2_bonus.c ft_itoa_bonus.c \
							draw_func1_bonus.c move_func_bonus.c move_ghost_bonus.c \
							gost_bonus.c)
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