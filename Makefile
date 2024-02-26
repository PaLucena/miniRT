#//= Executables =//#
NAME = miniRT
NAME_B = miniRT_bonus

#//= Compilator =//#
CC = gcc
FLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

#//= Mandatory src files =//#
SRC_PATH = mandatory/src/
SRC = mandatory/src/main.c mandatory/src/utils/init.c mandatory/src/parser/parser.c mandatory/src/parser/savers/save_amb.c mandatory/src/parser/savers/save_extras.c\
	mandatory/src/parser/savers/save_extras2.c mandatory/src/parser/savers/save_camera.c mandatory/src/parser/savers/save_light.c\
	mandatory/src/parser/savers/scene_list_tools.c mandatory/src/parser/savers/save_sphere.c mandatory/src/parser/savers/save_cylinder.c\
	mandatory/src/parser/savers/save_plane.c mandatory/src/utils/exit.c mandatory/src/utils/mlx_hooks.c mandatory/src/collider/pixels.c\
	mandatory/src/collider/inters/inter_sphere.c mandatory/src/collider/inters/inter_plane.c mandatory/src/collider/inters/inter_cylinder.c\
	mandatory/src/collider/inters/inter_utils.c mandatory/src/utils/vector/vector_utils.c mandatory/src/utils/vector/vector_utils2.c\
	mandatory/src/light/light.c mandatory/src/light/light_utils.c mandatory/src/collider/camera/camera.c mandatory/src/utils/vector/vector_point_color.c\
	mandatory/src/utils/vector/vector_utils3.c mandatory/src/collider/inters/inter_cylinder2.c mandatory/src/parser/parser_utils.c\

#//= Bonus src files =//#
SRC_PATH_B = bonus/src/
SRC_B = bonus/src/main.c bonus/src/utils/init_bonus.c bonus/src/parser/parser_bonus.c bonus/src/parser/savers/save_amb_bonus.c bonus/src/parser/savers/save_extras_bonus.c\
		bonus/src/parser/savers/save_extras2_bonus.c bonus/src/parser/savers/save_camera_bonus.c bonus/src/parser/savers/save_light_bonus.c\
		bonus/src/parser/savers/scene_list_tools_bonus.c bonus/src/parser/savers/save_sphere_bonus.c bonus/src/parser/savers/save_cylinder_bonus.c\
		bonus/src/parser/savers/save_plane_bonus.c bonus/src/utils/exit_bonus.c bonus/src/utils/mlx_hooks_bonus.c bonus/src/collider/pixels_bonus.c \
		bonus/src/collider/inters/inter_sphere_bonus.c bonus/src/collider/inters/inter_plane_bonus.c bonus/src/collider/inters/inter_cylinder_bonus.c bonus/src/collider/inters/inter_utils_bonus.c\
		bonus/src/utils/vector/vector_utils_bonus.c bonus/src/utils/vector/vector_utils2_bonus.c\
		bonus/src/light/light_bonus.c bonus/src/light/color_bonus.c bonus/src/light/light_utils_bonus.c bonus/src/collider/camera/camera_bonus.c bonus/src/utils/vector/vector_point_color_bonus.c bonus/src/utils/vector/vector_utils3_bonus.c\
		bonus/src/collider/inters/inter_cylinder2_bonus.c bonus/src/parser/parser_utils_bonus.c bonus/src/parser/savers/save_light_utils_bonus.c bonus/src/parser/savers/save_cone_bonus.c\
		bonus/src/collider/inters/inter_cone_bonus.c bonus/src/collider/inters/inter_cone2_bonus.c


#//= Objects =//#
OBJ_PATH = objs/

OBJ = $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o,$(SRC))
# OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
OBJ_B = $(patsubst $(SRC_PATH_B)/%.c,$(OBJ_PATH)/%.o,$(SRC_B))
# OBJ_B = $(addprefix $(OBJ_PATH), $(SRC_B:.c=.o))

#//= Included libraries =//#
LIBS = -I libs/libft -I libs/MLX42/include/MLX42
MLX = libs/MLX42/libmlx42.a
LIB = libs/libft/libft.a

INC =  -I ./mandatory/include
INC_B = -I ./bonus/include

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


#//= Compilation rules =//#
all: libft mlx $(NAME)
$(NAME): $(OBJ)
	@ $(CC) $(FLAGS) $(OBJ) $(LIB) $(MLX) $(BREW) $(INC) $(LIBS) -o $(NAME)
	@ echo "$(GREEN)$(BOLD)$(NAME) compiled\n$(RESET)"
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@ mkdir -p  $(OBJ_PATH)
	@ $(CC) $(FLAGS) -c $< -o $@ $(INC)

bonus: libft mlx $(NAME_B)
$(NAME_B): $(OBJ_B)
	@ $(CC) $(FLAGS) $(OBJ_B) $(LIB) $(MLX) $(BREW) $(INC_B) $(LIBS) -o $(NAME_B)
	@ echo "$(GREEN)$(BOLD)$(NAME_B) compiled\n$(RESET)"
$(OBJ_PATH)%.o: $(SRC_PATH_B)%.c
	@ mkdir -p  $(OBJ_PATH)
	@ $(CC) $(FLAGS) -c $< -o $@ $(INC_B)

libft:
	@ make -C libs/libft

mlx:
	@make -C libs/MLX42/

#//= Cleaning rules =//#
clean:
	@ rm -rf $(OBJ_PATH)
	@ make -C libs/libft/ clean
	@ make -C libs/MLX42/ clean
	@ echo "\n$(RED)$(BOLD)$(NAME) deleted\n$(RESET)"

bclean:
	@ rm -rf $(OBJ_PATH)
	@ make -C libs/libft/ clean
	@ make -C libs/MLX42/ clean
	@ echo "\n$(RED)$(BOLD)$(NAME_B) deleted\n$(RESET)"

fclean: clean bclean
	@ rm -rf $(NAME)
	@ make -C libs/libft/ fclean
	@ make -C libs/MLX42/ fclean
	@ rm -rf $(NAME_B)
	@ make -C libs/libft/ fclean
	@ make -C libs/MLX42/ fclean

#//= Re-do rules =//#
re: fclean all

bre: fclean bonus

#//= Norme rules =//#
norme:
	@ norminette mandatory/src/
	@ norminette libs/libft/
	@ norminette mandatory/include/*.h

bnorme:
	@ norminette bonus/src/
	@ norminette libs/libft/
	@ norminette bonus/include/*.h

.PHONY: all libft mlx clean fclean re norme bonus bclean bre bnorme