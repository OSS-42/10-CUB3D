#------------------------------------------------------------------------------#
#								   GENERAL									   #
#------------------------------------------------------------------------------#
NAME = cub3D
NAME_BONUS = cub3D_bonus

CC = gcc
#CC = gcc-11
CFLAGS = -g -Wall -Werror -Wextra
#CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf

#LSAN_OPTIONS=detect_leaks=1 ./cub3D

#------------------------------------------------------------------------------#
#								   LIBRARIES								   #
#------------------------------------------------------------------------------#
D_LIBFT = libft/
LIBFT = libft/libft.a
D_LIBFTHEAD = libft/includes/libft.h

D_LIBART = libart/
LIBART = libart/libart.a
D_LIBARTHEAD = libart/includes/libart.h

D_MLX42 = MLX42/
MLX42 = MLX42/build/libmlx42.a

#------------------------------------------------------------------------------#
#									SOURCES									   #
#------------------------------------------------------------------------------#
HEADER = includes/cub3D.h
D_SRC = src/
D_OBJ = obj/
OBJS = $(patsubst $(D_SRC)%.c,$(D_OBJ)%.o,$(SRCS))
SRCS =	src/cub3D.c \
		src/error_management.c \
		src/scene_parsing.c \
		src/scene_parsing_utils.c \
		src/cub3d_utils.c \
		src/check_orientation_params.c \
		src/check_fc_params.c \
		src/map_parsing.c \
		src/map_parsing_utils.c \
		src/flood_fill.c \
		src/check_ceiling_rgb.c \
		src/check_floor_rgb.c \
		src/init_textures.c \
		src/init_player.c \
		src/raycasting.c \
		src/moves.c \
		src/camera.c \
		src/textures.c \
		src/init_3d.c

#------------------------------------------------------------------------------#
#									 RULES									   #
#------------------------------------------------------------------------------#

all:	art_intro $(NAME)

$(NAME):	$(D_OBJ) $(LIBFT) $(LIBART) $(MLX42) $(OBJS)
# Ubuntu
	@$(call creating, $(CC) $(CFLAGS) $(OBJS) $(MLX42) -I include -ldl -lglfw -pthread -lm -o $@ $(LIBFT) $(LIBART))
# MacOS 42
#	@$(call creating, $(CC) $(CFLAGS) $(OBJS) -I include -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ -o $@ $(LIBFT) $(LIBART) $(MLX42))
# Apple M2
#	@$(call creating, $(CC) $(CFLAGS) $(OBJS) -I include -lglfw -L /opt/homebrew/opt/glfw/lib/ -o $@ $(LIBFT) $(LIBART) $(MLX42))
	@echo "$(LGREEN)Software Compilation completed ...!$(NC)"
#	@sleep 2
#	@clear

art_intro:
	@$(MAKE) intro_cub3D -C $(D_LIBART)

$(LIBFT):	$(D_LIBFTHEAD)
	@$(MAKE) -C $(D_LIBFT)

$(LIBART):	$(D_LIBARTHEAD)
	@$(MAKE) -C $(D_LIBART)

$(MLX42):
	@echo "$(LGREEN)MLX42 Configuration started ...$(NC)"
	@brew update --quiet
	@brew install glfw --quiet
	@echo "$(LGREEN)MLX42 Configuration completed ...$(NC)"

$(D_OBJ):
	@mkdir -p $(D_OBJ)

$(OBJS): $(D_OBJ)%.o : $(D_SRC)%.c $(HEADER)
		@$(call run_and_test, $(CC) $(CFLAGS) -c $< -o $@)

#norm a checker
norm:
	@includes/ norminette
	@src/ norminette

clean:
	@$(call cleaning, $(RM) $(D_OBJ))

fclean:	clean
	@$(call fcleaning, $(RM) $(NAME))
	@$(RM) $(NAME_BONUS)

lclean: fclean
	@$(call lcleaning)
	@$(MAKE) -s --no-print-directory -C $(D_LIBFT) fclean
	@$(MAKE) -s --no-print-directory -C $(D_LIBART) fclean

re:	fclean all

.PHONY: all clean fclean lclean re

#------------------------------------------------------------------------------#
#									IF BONUS								   #
#------------------------------------------------------------------------------#
HEADER_BONUS = includes/cub3D_bonus.h
D_SRC_BONUS = bonus/src/
D_OBJ_BONUS = bonus/obj/
OBJS_BONUS = $(patsubst $(D_SRC_BONUS)%.c,$(D_OBJ_BONUS)%.o,$(SRCS_BONUS))
SRCS_BONUS =	bonus/src/cub3D_bonus.c \
				bonus/src/error_management_bonus.c \
				bonus/src/scene_parsing_bonus.c \
				bonus/src/scene_parsing_utils_bonus.c \
				bonus/src/cub3d_utils_bonus.c \
				bonus/src/check_orientation_params_bonus.c \
				bonus/src/check_fc_params_bonus.c \
				bonus/src/map_parsing_bonus.c \
				bonus/src/map_parsing_utils_bonus.c \
				bonus/src/error_utils_bonus.c \
				bonus/src/flood_fill_bonus.c \
				bonus/src/check_ceiling_rgb_bonus.c \
				bonus/src/check_floor_rgb_bonus.c \
				bonus/src/init_textures_bonus.c \
				bonus/src/init_player_bonus.c \
				bonus/src/init_hud_bonus.c \
				bonus/src/raycasting_bonus.c \
				bonus/src/init_minimap_bonus.c \
				bonus/src/moves_bonus.c \
				bonus/src/camera_bonus.c \
				bonus/src/textures_bonus.c \
				bonus/src/extra_textures_bonus.c \
				bonus/src/init_3d_bonus.c \
				bonus/src/audio_bonus.c \
				bonus/src/keyhandler_bonus.c \
				bonus/src/minimap_utils_bonus.c

bonus: intro_bonus art_intro $(NAME_BONUS)

intro_bonus:
	@$(MAKE) bonus -C $(D_LIBART)

$(NAME_BONUS):	$(D_OBJ_BONUS) $(LIBFT) $(LIBART) $(MLX42) $(OBJS_BONUS)
# Ubuntu
# @$(call creating, $(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX42) -I include -ldl -lglfw -pthread -lm -o $@ $(LIBFT) $(LIBART))
# MacOS 42
	@$(call creating, $(CC) $(CFLAGS) $(OBJS_BONUS) -I include -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ -o $@ $(LIBFT) $(LIBART) $(MLX42))
# Apple M2
#	@$(call creating, $(CC) $(CFLAGS) $(OBJS_BONUS) -I include -lglfw -L /opt/homebrew/opt/glfw/lib/ -o $@ $(LIBFT) $(LIBART) $(MLX42))
	@echo "$(LGREEN)Software Compilation completed !$(NC)"

$(D_OBJ_BONUS):
	@mkdir -p $(D_OBJ_BONUS)

$(OBJS_BONUS):	$(D_OBJ_BONUS)%.o : $(D_SRC_BONUS)%.c $(HEADER_BONUS)
		@$(call run_and_test, $(CC) $(CFLAGS) -c $< -o $@)

clean_bonus:
	@$(call cleaning, $(RM) $(D_OBJ_BONUS))

fclean_bonus: clean_bonus
	@$(call fcleaning, $(RM) $(NAME_BONUS))

lclean_bonus: fclean_bonus
	@$(call lcleaning)
	@$(MAKE) -s --no-print-directory -C $(D_LIBFT) fclean
	@$(MAKE) -s --no-print-directory -C $(D_LIBART) fclean

#------------------------------------------------------------------------------#
#								  MAKEUP RULES								   #
#------------------------------------------------------------------------------#

#----------------------------------- COLORS -----------------------------------#
LRED = \033[91m
RED = \033[91m
LGREEN = \033[92m
LYELLOW = \033[93
LMAGENTA = \033[95m
LCYAN = \033[96m
NC = \033[0;39m

#----------------------------------- TEXTES -----------------------------------#
OK_STRING = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING = "[WARNING]"
COMP_STRING = "Generating"
CLEAN_STRING = "Cleaning"
CREAT_STRING = "Creating"

#----------------------------------- DEFINE -----------------------------------#
define run_and_test
printf "%b" "$(LCYAN)$(COMP_STRING)$(LMAGENTA) $(@F)$(NC)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(LCYAN)$(COMP_STRING)$(LMAGENTA) $(@F)" "💥$(NC)\n"; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(LCYAN)$(COMP_STRING)$(LMAGENTA) $(@F)" "⚠️$(NC)\n"; \
	else \
		printf "%-60b%b" "$(LCYAN)$(COMP_STRING)$(LMAGENTA) $(@F)" "✅$(NC)\n"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

define cleaning
printf "%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) OBJECT Files$(NC)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) OBJECT Files" "💥$(NC)\n"; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) OBJECT Files" "⚠️$(NC)\n"; \
	else \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) OBJECT Files" "✅$(NC)\n"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

define fcleaning
printf "%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) PROJECT Executable Files$(NC)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) PROJECT Executable Files" "💥$(NC)\n"; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) PROJECT Executable Files" "⚠️$(NC)\n"; \
	else \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) PROJECT Executable Files" "✅$(NC)\n"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

define lcleaning
printf "%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBRARY Files$(NC)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBRARIES Files" "💥$(NC)\n"; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBRARIES Files" "⚠️$(NC)\n"; \
	else \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBRARIES Files" "✅$(NC)\n"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

define creating
printf "%b" "$(LCYAN)$(CREAT_STRING)$(LMAGENTA) $(@F)$(NC)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(LCYAN)$(CREAT_STRING)$(LMAGENTA) $(@F)" "💥$(NC)\n"; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(LCYAN)$(CREAT_STRING)$(LMAGENTA) $(@F)" "⚠️$(NC)\n"; \
	else \
		printf "%-60b%b" "$(LCYAN)$(CREAT_STRING)$(LMAGENTA) $(@F)" "✅$(NC)\n"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef