PROJECT 	:= philo
CC 			:= gcc

CFLAGS		:= -Wextra -Wall -Werror #-g -fsanitize=address

INCLUDE 	:= -I ./include

SRC_DIR 	:= src
SRC			:=	main.c \
				check.c \
				utils.c \
				table.check	\
				

OBJ_DIR 	:= obj
OBJ 		:= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
BIN_DIR		:= bin
NAME		:= $(BIN_DIR)/$(PROJECT)


# COLORS
RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE 	:= \033[96m
RESET   := \033[0m

all: $(NAME)

$(NAME): $(OBJ) | $(BIN_DIR)
	@echo "Compiling $(YELLOW)$(PROJECT)$(RESET) with $(BLUE)$(CFLAGS)$(RESET)..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)Done! ✅$(RESET)"
	@echo "$(RED)------------------------------$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(BIN_DIR)

re: clean all

.PHONY: all libft clean fclean re