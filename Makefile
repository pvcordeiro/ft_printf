CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_utils.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
LIBFT = libft/libft.a
MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "\nBuilding $(NAME)..."
	@ar rcs $(NAME) $(OBJS) libft/*.o
#delete before sending libft/*.o ^
	@echo "\nDone!"

$(LIBFT):
	@echo "\nBuilding libft.a"
	@$(MAKE) -C libft -s
	@echo "\nDone"

clean:
	@echo "\nRemoving .o files..."
	@rm -f $(OBJS)
	@$(MAKE) -C libft clean -s
	@echo "\nDone!"

fclean: clean
	@echo "\nRemoving $(NAME) and libft.a ..."
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean -s
	@echo "\nDone!"

re: fclean all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

test:
	@echo "\nCompiling everything and testing it:\n"
	@$(MAKE) -C libft -s
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rcs $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) main.c $(NAME) $(LIBFT) -o main && ./main
	@rm -f main $(OBJS) $(NAME) $(LIBFT) libft/*.o