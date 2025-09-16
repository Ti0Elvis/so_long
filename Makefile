# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evera <evera@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/16 16:31:31 by evera             #+#    #+#              #
#    Updated: 2025/09/16 16:52:03 by evera            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ================================ COLORS ================================== #
RESET		= \033[0m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
MAGENTA		= \033[35m
CYAN		= \033[36m
WHITE		= \033[37m
BOLD		= \033[1m
BLACK 		= \033[30m
ITALIC		= \033[3m

# =============================== PROJECT =================================== #
NAME		= so_long
COMPILER	= gcc
FLAGS		= -Wall -Wextra -Werror
OBJS_DIR	= objs

# ================================ FILES ==================================== #
C_FILES		=	./src/check-map.c \
				./src/destroy-game.c \
				./src/flood-fill.c \
				./src/init-game.c \
				./src/init-map.c \
				./src/init-player.c \
				./src/init-textures.c \
				./src/key-listener.c \
				./src/player.c \
				./src/render.c \
				./src/utils.c \
				./src/validate-map.c \
				./so_long.c
OBJS		= $(patsubst %.c,$(OBJS_DIR)/%.o,$(C_FILES))

# ================================= MLX ===================================== #
MLX_DIR		= ./src/mlx
MLX			= $(MLX_DIR)/libmlx.a
MLX_LIB		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_INC		= -I$(MLX_DIR)

# ================================ LIBFT ==================================== #
LIBFT_DIR	= ./src/libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_LIB	= -L$(LIBFT_DIR) -lft
LIBFT_INC	= -I$(LIBFT_DIR)

# =============================== TARGETS =================================== #
all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)$(BOLD)🔗 Linking $(NAME)...$(RESET)"
	@$(COMPILER) $(FLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo "$(GREEN)$(BOLD)✅ $(NAME) successfully compiled!$(RESET)"
	@echo ""
	@echo "$(BLACK)$(BOLD)"
	@echo "            ________o8A888888o_					   "    
	@echo "        _o888888888888K_1888888o					   "
	@echo "                  ~~~+8888888888o				   "
	@echo "                      ~8888888888				   "
	@echo "                      o88888888888				   "
	@echo "                     o8888888888888				   "
	@echo "                   _8888888888888888				   "
	@echo "                  o888888888888888888_			   "
	@echo "                 o88888888888888888888_			   "
	@echo "                _8888888888888888888888_			   "
	@echo "                888888888888888888888888_		   "
	@echo "                8888888888888888888888888		   "
	@echo "                88888888888888888888888888	       "
	@echo "                88888888888888888888888888		   "
	@echo "                888888888888888888888888888		   "
	@echo "                ~88888888888888888888888888_		   "	
	@echo "                 488888888888888888888888888		   "	
	@echo "                  888888888888888888888888888	   "
	@echo "                   888888888888888888888888888_     "
	@echo "                   ~8888888888888888888888888888    "
	@echo "                     +88888888888888888888~~~~~	   "
	@echo "                      ~=888888888888888888o         "
	@echo "               _=oooooooo888888888888888888         "
	@echo "                _o88=8888==~88888888===8888         "
	@echo "                ~   =~~ _o88888888=      ~~~		   "
	@echo "                        ~ o8=~88=~				   "
	@echo "$(YELLOW)    🐧 Tux says: Great job! Your program is ready! 🐧$(RESET)"
	@echo ""

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)🔨 Compiling $<...$(RESET)"
	@$(COMPILER) $(FLAGS) $(MLX_INC) $(LIBFT_INC) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(BLUE)📁 Creating objects directory...$(RESET)"

$(MLX):
	@echo "$(MAGENTA)$(BOLD)🏗️  Building MLX library...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

$(LIBFT):
	@echo "$(MAGENTA)$(BOLD)🏗️  Building LIBFT library...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(GREEN)✨ Clean completed!$(RESET)"

fclean: clean
	@echo "$(RED)🗑️  Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(GREEN)✨ Full clean completed!$(RESET)"

re: fclean all

help:
	@echo "$(CYAN)$(BOLD)📖 Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)     - Build the project"
	@echo "  $(GREEN)clean$(RESET)   - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)  - Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)      - Rebuild everything from scratch"
	@echo "  $(GREEN)help$(RESET)    - Show this help message"

.PHONY: all clean fclean re help
