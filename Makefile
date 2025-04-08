##
## EPITECH PROJECT, 2025
## B-CPE-200-LIL-2-1-robotfactory-lucas.lhomme
## File description:
## Makefile
##
# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
NC=\033[0m # No Color

# Variables
NAME = amazed
CFLAGS = -g -Wall -Wextra -W -Iinclude -Ilib/include -fdiagnostics-color=always
MATRICE_PATH	=	./src/matrice
QUEUE_PATH	=	./src/queue_handle
SRC_PATH	=	./src
PARSING_PATH	=	./src/parsing
# $(QUEUE_PATH)/queue.c
SRC =	$(MATRICE_PATH)/def_matrice.c \
		$(MATRICE_PATH)/matrice.c \
		$(QUEUE_PATH)/queue.c \
		$(QUEUE_PATH)/def_queue.c \
		$(SRC_PATH)/linked_list_path.c \
		$(SRC_PATH)/main.c \
		$(PARSING_PATH)/line_process.c \
		$(PARSING_PATH)/parsing.c \
		$(PARSING_PATH)/utils.c \
		$(PARSING_PATH)/link_handling.c \
		$(PARSING_PATH)/room_handling.c \

OBJ = $(SRC:.c=.o)
LIBMY = libmy.a

# Default target
all: $(LIBMY) $(NAME)

# Compilation de l'exécutable principal
$(NAME): $(OBJ)
	@echo "$(YELLOW)Building $@...$(NC)"
	@OUTPUT=$$(gcc $(CFLAGS) -o $@ $^ $(LIBMY) 2>&1); \
	ERRORS=$$(echo "$$OUTPUT" | grep -c "error:"); \
	WARNINGS=$$(echo "$$OUTPUT" | grep -c "warning:"); \
	echo "$$OUTPUT"; \
	if [ $$ERRORS -eq 0 ]; then \
		echo "$(GREEN)Build complete!\
		$(MAGENTA)warnings :$$WARNINGS, $(RED)errors: $$ERRORS"; \
	else \
		echo "$(RED)Build failed with $$ERRORS errors\
		$(MAGENTA) and $$WARNINGS warnings!$(NC)"; \
	fi

# Compilation of object files
%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@ || { \
		echo "$(RED)BUILD FAILED!$(NC)"; \
		exit 1; \
	}

# Compilation of the library
$(LIBMY):
	@echo "$(BLUE)Building library...$(NC)"
	@$(MAKE) --no-print-directory -C lib all

# Clean up object files and executables
clean:
	@echo "$(RED)Cleaning up...$(NC)"
	@$(MAKE) --no-print-directory -C lib clean
	@rm -f $(OBJ)

# Full clean up
fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBMY)

# Rebuild everything
re: fclean all

# Debug mode
debug: CFLAGS += -g
debug: $(NAME)

# Rebuild in debug mode
redebug: fclean debug

# Phony targets
.PHONY: all clean fclean re debug redebug
