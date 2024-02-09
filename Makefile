NAME = miniRT
NAME_B = miniRT_bonus

CC = gcc -g
FLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

SRC_PATH = src/
SRC = main.c init.c parser.c save_amb.c save_extras.c save_extras2.c save_camera.c save_light.c\
	scene_list_tools.c save_sphere.c save_cylinder.c save_plane.c exit.c mlx_hooks.c pixels.c \
	inter_sphere.c inter_plane.c inter_cylinder.c inter_utils.c vector_utils.c vector_utils2.c\
	light.c light_utils.c camera.c vector_point_color.c vector_utils3.c inter_cylinder2.c parser_utils.c\

SRC_PATH_B = src_bonus/
SRC_B = main_bonus.c init_bonus.c parser_bonus.c save_amb_bonus.c save_extras_bonus.c\
		save_extras2_bonus.c save_camera_bonus.c save_light_bonus.c\
		scene_list_tools_bonus.c save_sphere_bonus.c save_cylinder_bonus.c\
		save_plane_bonus.c exit_bonus.c mlx_hooks_bonus.c pixels_bonus.c \
		inter_sphere_bonus.c inter_plane_bonus.c inter_cylinder_bonus.c inter_utils_bonus.c\
		vector_utils_bonus.c vector_utils2_bonus.c\
		light_bonus.c light_utils_bonus.c camera_bonus.c vector_point_color_bonus.c vector_utils3_bonus.c\
		inter_cylinder2_bonus.c parser_utils_bonus.c\

OBJ_PATH = objs/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

OBJ_PATH_B = objs_bonus/
OBJ_B = $(addprefix $(OBJ_PATH_B), $(SRC_B:.c=.o))

INC = -I include/libft -I ./include/MLX42/include/MLX42 -I ./include
MLX = include/MLX42/libmlx42.a
LIB = include/libft/libft.a

INC_B = -I include_bonus/libft -I ./include_bonus/MLX42/include/MLX42 -I ./include_bonus
MLX_B = include_bonus/MLX42/libmlx42.a
LIB_B = include_bonus/libft/libft.a

BREW = -lglfw -L "/Users/${USER}/.brew/opt/glfw/lib/"


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

bonus: libftb mlxb $(NAME_B)

$(NAME_B): $(OBJ_B)
	@ gcc $(FLAGS) $(OBJ_B) $(LIB_B) $(MLX_B) $(BREW) $(INC_B) -o $(NAME_B)
	@ echo "$(GREEN)$(BOLD)$(NAME) compiled\n$(RESET)"

$(OBJ_PATH_B)%.o: $(SRC_PATH_B)%.c
	@ mkdir -p  $(OBJ_PATH_B)
	@ $(CC) $(FLAGS) -c $< -o $@ $(INC_B)

libftb:
	@ make -C include_bonus/libft

mlxb:
	@make -C include_bonus/MLX42/

all: libft mlx $(NAME)

$(NAME): $(OBJ)
	@ gcc $(FLAGS) $(OBJ) $(LIB) $(MLX) $(BREW) $(INC) -o $(NAME)
	@ echo "$(GREEN)$(BOLD)$(NAME) compiled\n$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@ mkdir -p  $(OBJ_PATH)
	@ $(CC) $(FLAGS) -c $< -o $@ $(INC)

libft:
	@ make -C include/libft

mlx:
	@make -C include/MLX42/

clean:
	@ rm -rf $(OBJ_PATH) $(OBJ_PATH_B)
	@ make -C include/libft clean
	@ make -C include/MLX42 clean
	@ make -C include_bonus/libft clean
	@ make -C include_bonus/MLX42 clean
	@ echo "\n$(RED)$(BOLD)$(NAME) deleted\n$(RESET)"

fclean: clean
	@ rm -rf $(NAME) $(NAME_B)
	@ make -C include/libft fclean
	@ make -C include/MLX42/ fclean
	@ make -C include_bonus/libft fclean
	@ make -C include_bonus/MLX42/ fclean

re: fclean all

norme:
	@ norminette src/
	@ norminette src_bonus/
	@ norminette include/libft/
	@ norminette include/*.h

.PHONY: all libft mlx clean fclean re norme bonus libftb mlxb