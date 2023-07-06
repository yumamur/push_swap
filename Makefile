NAME	= push_swap
TITLE	= \033[31;1m[PUSH_SWAP]\033[m

RM		= rm
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address

LIBFT_DIR		= ./src/libft
LIBFT_HEADERS	= $(LIBFT_DIR)/include
LIBFT			= $(LIBFT_DIR)/libft.a

SRC			= $(wildcard ./src/mandatory/*.c)
SRC_BONUS	= $(wildcard ./src/checker/*.c)

$(NAME): $(SRC)
	@printf "$(TITLE) \033[1mMandatory\033[m\n"
	@printf "$(TITLE) Building 'libft.a'\n"
	@make -sC $(LIBFT_DIR)
	@mkdir -p ./include/libft
	@cp -r $(LIBFT_HEADERS)/* ./include/libft/
	@printf "$(TITLE) Building '$(NAME)'\n"
	@$(CC) $(CFLAGS) -I./include $(SRC) $(LIBFT) -o $(NAME)
	@printf "$(TITLE) Successful\n"

.PHONY: all bonus clean fclean re

all: $(NAME) $(HELP)

clean:
	@if [ -e $(NAME) ]; then \
		$(RM) -rf $(NAME); \
	elif [ -e ./include/libft ]; then \
		$(RM) -rf ./include/libft; \
	else \
		continue; \
	fi
	@make -sC $(LIBFT_DIR) clean

fclean:
	@if [ -e $(NAME) ]; then \
		$(RM) -rf $(NAME); \
	elif [ -e ./include/libft ]; then \
		$(RM) -rf ./include/libft; \
	else \
		continue; \
	fi
	@make -sC $(LIBFT_DIR) fclean

re: fclean all
