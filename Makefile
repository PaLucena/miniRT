NAME = miniRT

CC = gcc -g
FLAGS = -Wall -Wextra -Werror

SRC_PATH = src/
SRC = main.c init.c parser.c save_amb.c save_extras.c save_extras2.c save_camera.c save_light.c\
	scene_list_tools.c save_sphere.c

OBJ_PATH = objs/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

INC = -I include/libft -I ./include -I ./include/MLX42/include/MLX42
MLX = include/MLX42/libmlx42.a
BREW = -lglfw -L "/Users/${USER}/.brew/opt/glfw/lib/"
LIB = include/libft/libft.a


#//= Colors =//#
BOLD    := \033[1m
BLACK   := \033[30;1m
RED     := \033[31;1m
GREEN   := \033[32;1m
YELLOW  := \033[33;1m
BLUE    := \033[34;1m
MAGENTA := \033[35;1m
CYAN    := \033[36;1m
WHITE   := \033[37;1m
RESET   := \033[0m

all: libft mlx $(NAME)

$(NAME): $(OBJ)
	@ gcc $(FLAGS) $(OBJ) $(LIB) $(MLX) $(BREW) -o $(NAME)
	@ echo "\n\t\t$(GREEN)$(BOLD)----$(NAME) compiled----\n$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@ mkdir -p  $(OBJ_PATH)
	@ $(CC) $(FLAGS) -c $< -o $@ $(HEADERS) 

libft:
	@ make -C include/libft

mlx:
	@make -C include/MLX42/

clean:
	@ rm -rf $(OBJ_PATH)
	@ make -C include/libft clean
	@ make -C include/MLX42 clean
	@ echo "\n\t\t\t$(RED)$(BOLD)Cleaning...\n$(RESET)"

fclean: clean
	@ rm -rf $(NAME)
	@ make -C include/libft fclean
	@ make -C include/MLX42/ fclean

re: fclean all

norme:
	@ norminette src/
	@ norminette include/libft/
	@ norminette include/*.h

.PHONY: all libft mlx clean fclean re norme