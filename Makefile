CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\nBuilding $(NAME)..."
	@ar rcs $(NAME) $(OBJS)
	@echo "\nDone!"

clean:
	@echo "\nRemoving .o files..."
	@rm -f $(OBJS)
	@echo "\nDone!"

fclean: clean
	@echo "\nRemoving $(NAME)..."
	@rm -f $(NAME)
	@echo "\nDone!"

re: fclean all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

test:
	@echo "\nCompiling everything and testing it:\n"
	@$(CC) $(CFLAGS) -c ft_printf.c
	@ar rcs $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(NAME) && ./a.out
	@rm -f a.out $(OBJS) $(NAME)