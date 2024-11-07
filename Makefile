CC = cc -Wall -Wextra -Werror
SRCS = ft_printf.c ft_utils.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
LIBFT = libft/libft.a
INCLUDES = -I. -Ilibft
MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "\nBuilding $(NAME)..."
	@ar rcs $(NAME) $(OBJS) $(LIBFT)
	@echo "\nDone!"

$(LIBFT):
	@echo "\nBuilding libft.a"
	@$(MAKE) -C libft
	@echo "\nDone"

clean:
	@echo "\nRemoving .o files..."
	@rm -f $(OBJS)
	@$(MAKE) -C libft clean
	@echo "\nDone!"

fclean: clean
	@echo "\nRemoving $(NAME) and libft.a ..."
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@echo "\nDone!"

re: fclean all

%.o: %.c
	@$(CC) $(INCLUDES) -c $< -o $@

test: all
	@echo "\nCompiling everything and testing it:\n"
	@$(CC) $(INCLUDES) main.c $(NAME) $(LIBFT) -o main
	@./main
	@rm -f main
	@$(MAKE) fclean


