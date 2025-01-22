# VALGRIND
VALGRIND_LOG := valgrind.log


# COLORS
GREEN := \033[32m
RED := \033[31m
CYAN := \033[36m
VIOLET := \033[38;5;208m
COLOR_LIMITER := \033[0m


# NAME
NAME := push_swap

# FLAGS
CFLAGS := -Ofast -fno-stack-protector -ffast-math -Wall -Wextra -Wunreachable-code -g3 -Werror

# LIBS
LIB_PATH := ./libs/libft
LIB_NAME := libft.a

# PATHS
SRC_PATH := ./src/
BIN_PATH := ./bin/
HEADER_PATH := ./includes/
CMD_PATH := cmd/

# SOURCES AND OBJECTS
FILES := \
	main.c \
	init.c \
	stack.c \
	utils.c \
	error.c \
	validation.c \
	small_sort.c \
	$(CMD_PATH)push.c \
	$(CMD_PATH)swap.c \
	$(CMD_PATH)rotate.c \
	$(CMD_PATH)rotate_reverse.c 
SRCS := $(addprefix $(SRC_PATH), $(FILES))
OBJS := $(addprefix $(BIN_PATH), $(FILES:%.c=%.o))

all: libft $(BIN_PATH) print $(NAME)

libft:
ifeq ($(wildcard $(LIB_PATH)/$(LIB_NAME)),)
	@printf "$(CYAN)------------------- ----------------- -------------------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)-------------------| COMPILING LIBFT |-------------------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)------------------- ----------------- -------------------$(COLOR_LIMITER)\n"
	@make build -C $(LIB_PATH) --no-print-directory
endif

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)$(CMD_PATH)

print:
ifeq ($(wildcard $(NAME)),)
	@printf "$(GREEN) ------------------------$(COLOR_LIMITER)"
	@printf "$(GREEN)| Compiling Main Project |$(COLOR_LIMITER)"
	@printf "$(GREEN)------------------------$(COLOR_LIMITER)"
	@echo " "
endif

$(NAME): $(OBJS) $(HEADER_PATH)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_PATH)/$(LIB_NAME) -I$(HEADER_PATH)
	@printf "$(CYAN)------ ------------------------------------------------- ------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)------| PUSH_SWAP executable was created successfully!! |------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)------ ------------------------------------------------- ------$(COLOR_LIMITER)\n"
	@echo " "

$(BIN_PATH)%.o: $(SRC_PATH)%.c
	@printf "$(GREEN)[Compiling]$(COLOR_LIMITER) $(notdir $<)..."
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_PATH)
	@echo " "

clean:
	@printf "$(RED)[Removing Objects...]$(COLOR_LIMITER)\n"
	@make fclean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(BIN_PATH)
	@rm -rf $(VALGRIND_LOG)

fclean: clean
	@printf "$(RED)[Removing $(notdir $(NAME))...]$(COLOR_LIMITER)\n"
	@rm -rf $(NAME)

re: fclean
	@make --no-print-directory

valgrind: all
	@valgrind --leak-check=full \
	--show-reachable=yes \
	--track-fds=yes \
	--show-leak-kinds=all -s \
	--track-origins=yes \
	--log-file=$(VALGRIND_LOG) \
	./$(NAME) 8 9 2 3 0 1 5 4 6 7
	@cat $(VALGRIND_LOG)

.PHONY: all clean fclean re print libft valgrind