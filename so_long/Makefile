NAME = so_long
FLAGS = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Werror -Wextra
LIBFT= libft/libft.a

SRCS = so_long.c \
    	utils/map_parse/map_parse_utils.c\
    	utils/map_parse/map_parse_utils1.c\
    	utils/map_parse/map_parse.c \
		utils/game/game_init.c\
		utils/game/handle_keys.c\
		utils/game/player_move.c\
		utils/map_parse/check_path_utils.c\
		utils/map_parse/check_path.c\

BNS_SRCS = so_long_bonus.c\
		bonus_utils/map_parse_bonus/map_parse_utils_bonus.c\
    	bonus_utils/map_parse_bonus/map_parse_utils1_bonus.c\
    	bonus_utils/map_parse_bonus/map_parse_bonus.c \
		bonus_utils/map_parse_bonus/check_path_utils_bonus.c\
		bonus_utils/map_parse_bonus/check_path_bonus.c\
		bonus_utils/game_bonus/game_init_bonus.c\
		bonus_utils/game_bonus/handle_keys_bonus.c\
		bonus_utils/game_bonus/player_move_bonus.c\
		bonus_utils/game_bonus/animation_bonus.c\
		bonus_utils/game_bonus/enemies_utils_bonus.c\
		bonus_utils/game_bonus/enemies_bonus.c\

INCS= so_long.h libft/libft.h get_next_line/get_next_line.h
INCSB= so_long_bonus.h libft/libft.h get_next_line/get_next_line.h

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
	@cc $(CFLAGS) $(FLAGS) $(BNS_OBJS) $(LIBFT) $(GNL_OBJS) -o $(NAME)
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