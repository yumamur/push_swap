NAME		= push_swap
TITLE	= \033[31;1m[PUSH_SWAP]\033[m

NAME_BONUS	= checker
TITLE_BONUS	= \033[31;1m[CHECKER]\033[m

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

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(SRC_BONUS)
	@printf "$(TITLE_BONUS) \033[1mBonus\033[m\n"
	@printf "$(TITLE_BONUS) Building 'libft.a'\n"
	@make -sC $(LIBFT_DIR)
	@mkdir -p ./include/libft
	@cp -r $(LIBFT_HEADERS)/* ./include/libft/
	@printf "$(TITLE_BONUS) Building '$(NAME_BONUS)'\n"
	@$(CC) $(CFLAGS) -I./include $(SRC_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@printf "$(TITLE_BONUS) Successful\n"

clean:
	@if [ -e $(NAME) ]; then \
		$(RM) -rf $(NAME); \
	fi
	@if [ -e $(NAME_BONUS) ]; then \
		$(RM) -rf $(NAME_BONUS); \
	fi
	@if [ -e ./include/libft ]; then \
		$(RM) -rf ./include/libft; \
	fi
	@make -sC $(LIBFT_DIR) clean

fclean:
	@if [ -e $(NAME) ]; then \
		$(RM) -rf $(NAME); \
	fi
	@if [ -e $(NAME_BONUS) ]; then \
		$(RM) -rf $(NAME_BONUS); \
	fi
	@if [ -e ./include/libft ]; then \
		$(RM) -rf ./include/libft; \
	fi
	@make -sC $(LIBFT_DIR) fclean

re: fclean all
