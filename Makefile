NAME = so_long
FLAGS = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Werror -Wextra
LIBFT= libft/libft.a

SRCS = mandatory/so_long.c \
    	mandatory/utils/map_parse/map_parse_utils.c\
    	mandatory/utils/map_parse/map_parse_utils1.c\
    	mandatory/utils/map_parse/map_parse.c \
		mandatory/utils/game/game_init.c\
		mandatory/utils/game/handle_keys.c\
		mandatory/utils/game/player_move.c\
		mandatory/utils/map_parse/check_path_utils.c\
		mandatory/utils/map_parse/check_path.c\

BNS_SRCS = bonus/so_long_bonus.c\
		bonus/bonus_utils/map_parse_bonus/map_parse_utils_bonus.c\
    	bonus/bonus_utils/map_parse_bonus/map_parse_utils1_bonus.c\
    	bonus/bonus_utils/map_parse_bonus/map_parse_bonus.c \
		bonus/bonus_utils/map_parse_bonus/check_path_utils_bonus.c\
		bonus/bonus_utils/map_parse_bonus/check_path_bonus.c\
		bonus/bonus_utils/game_bonus/game_init_bonus.c\
		bonus/bonus_utils/game_bonus/handle_keys_bonus.c\
		bonus/bonus_utils/game_bonus/player_move_bonus.c\
		bonus/bonus_utils/game_bonus/animation_bonus.c\
		bonus/bonus_utils/game_bonus/enemies_utils_bonus.c\
		bonus/bonus_utils/game_bonus/enemies_bonus.c\

INCS= mandatory/so_long.h libft/libft.h get_next_line/get_next_line.h
INCSB= bonus/so_long_bonus.h libft/libft.h get_next_line/get_next_line.h

BNS_OBJS=$(BNS_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

GNL_SRCS = get_next_line/get_next_line.c\
        	get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(INCS)
	@make -s -C libft
	@echo "libft compiled successfully"
	@cc $(CFLAGS) $(FLAGS) $(OBJS) $(LIBFT) $(GNL_OBJS) -o $(NAME)
	@echo "so_long compiled successfully"

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@
	

bonus: $(BNS_OBJS) $(GNL_OBJS) $(INCSB)
	@make -s -C libft
	@echo "libft compiled successfully"
	@cc $(CFLAGS) $(FLAGS) $(BNS_OBJS) $(LIBFT) $(GNL_OBJS) -o so_long_bonus
	@echo "so_long compiled successfully"
clean:
	@make clean -s -C libft
	@rm -f $(OBJS) $(BNS_OBJS) $(GNL_OBJS)
	@echo "| Objects removed |"

fclean: clean
	@make fclean -s -C libft
	@rm -f $(NAME)
	@echo "| so_long removed |"

re: fclean all
